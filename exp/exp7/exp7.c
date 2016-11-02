#include<stdio.h>
#include<string.h>
#define INF 0x7fffffff
#define MAXLINE 1000
int freq[128];
typedef struct{
  char ch;
  int f,l,r;
}hnode_t;
typedef struct{
  hnode_t node[255];
  int n;
}htree_t;
typedef struct{
  char code[128][128];
}hcode_t;
void build_htree(htree_t *htree){
  int visited[255];
  for (int i=0;i<255;i++)
    visited[i]=0;
  for (int i=0;i<htree->n-1;i++){
    int min1=INF,min2=INF,min1_j,min2_j;
    for (int j=0;j<htree->n+i;j++)
      if (!visited[j]){
        if (htree->node[j].f<min1){
          min2=min1;
          min2_j=min1_j;
          min1=htree->node[j].f;
          min1_j=j;
        }
        else
          if (htree->node[j].f<min2){
            min2=htree->node[j].f;
            min2_j=j;
          }
      }
    visited[min1_j]=1;
    visited[min2_j]=1;
    htree->node[htree->n+i].f=htree->node[min1_j].f+htree->node[min2_j].f;
    htree->node[htree->n+i].l=min1_j;
    htree->node[htree->n+i].r=min2_j;
  }
}
void print(htree_t *htree,int i){
  if (i==-1)
    return;
  printf("%d",htree->node[i].f);
  if (htree->node[i].l!=-1 ||htree->node[i].r!=-1){
    printf("(");
    print(htree,htree->node[i].l);
    if (htree->node[i].r!=-1){
      printf(",");
      print(htree,htree->node[i].r);
    }
    printf(")");
  }
}
void init_htree(htree_t *htree){

  int n=0;
  for (int i=0;i<128;i++)
    if (freq[i]){
      htree->node[n].ch=i;
      htree->node[n].f=freq[i];
      htree->node[n].l=-1;
      htree->node[n].r=-1;
      n++;
    }
  htree->n=n;
}
void gen_hcode(htree_t *htree,hcode_t *hcode,char code_buf[],int len,int i){
  if (htree->node[i].l==-1){
    for (int j=0;j<len;j++)
      hcode->code[htree->node[i].ch][j]=code_buf[j];
    hcode->code[htree->node[i].ch][len]=0;
  }
  else{
    code_buf[len]='0';
    gen_hcode(htree,hcode,code_buf,len+1,htree->node[i].l);
    code_buf[len]='1';
    gen_hcode(htree,hcode,code_buf,len+1,htree->node[i].r);
  }
}
void encode(char buf[],hcode_t *hcode,htree_t *htree,FILE *out){
  fprintf(out,"%d\n",htree->n);
  for (int i=0;i<128;i++)
    if (freq[i])
      fprintf(out,"%c:%d\n",i,freq[i]);
  int i=0;
  while (buf[i]){
    fprintf(out,"%s",hcode->code[buf[i]]);
    i++;
  }
}
void decode(FILE *out,htree_t *htree,char buf[]){
  int i=0,j=2*htree->n-2;
  while (buf[i]){
    if (buf[i]=='0')
      j=htree->node[j].l;
    else
      j=htree->node[j].r;
    if (htree->node[j].l==-1){
      fprintf(out,"%c",htree->node[j].ch);
      j=2*htree->n-2;
    }
    i++;
  }
}
int main(int argc,char **argv){
  if (argc!=4){
    printf("usage:\n%s -e inputfile targetfile\n,%s -d encoded_file decoded_file",argv[0],argv[0]);
    return 1;
  }
  FILE *in=fopen(argv[2],"r");
  if (in==NULL){
    printf("inputfile not found!\n");
    return 1;
  }
  if (!strcmp(argv[1],"-e")){
    char buf[MAXLINE];
    fgets(buf,MAXLINE,in);
    htree_t htree;
    int len=strlen(buf);
    for (int i=0;i<len;i++)
      freq[buf[i]]++;
    init_htree(&htree);
    build_htree(&htree);
    hcode_t hcode;
    char code_buf[128];
    gen_hcode(&htree,&hcode,code_buf,0,2*htree.n-2);
    for (int i=0;i<htree.n;i++)
      printf("%c:%s$\n",htree.node[i].ch,hcode.code[htree.node[i].ch]);
    fclose(in);
    FILE *out=fopen(argv[3],"w");
    encode(buf,&hcode,&htree,out);
    fclose(out);
    return 0;
  }
  if (!strcmp(argv[1],"-d")){
    int n;
    fscanf(in,"%d",&n);
    for (int i=0;i<n;i++){
      int f;
      fgetc(in);
      char tmp=fgetc(in);
      fgetc(in);
      fscanf(in,"%d",&f);
      freq[tmp]=f;
    }
    char buf[MAXLINE*128];
    fgetc(in);
    fgets(buf,MAXLINE*128,in);
    fclose(in);
    htree_t htree;
    init_htree(&htree);
    build_htree(&htree);
    print(&htree,n*2-2);
    FILE *out=fopen(argv[3],"w");
    decode(out,&htree,buf);
    fclose(out);
    return 0;
  }
  else{
    printf("usage:\n%s -e inputfile targetfile\n,%s -d encoded_file decoded_file",argv[0],argv[0]);
    return 1;
  }
}
