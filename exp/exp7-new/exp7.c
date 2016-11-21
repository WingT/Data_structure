#include<stdio.h>
#include<stdlib.h>
typedef struct node_t{
  int count;
  struct node_t *c[256];
}node_t;
node_t *new_node(){
  node_t *node=(node_t *)malloc(sizeof(node_t));
  node->count=0;
  for (int i=0;i<256;i++)
    node->c[i]=NULL;
  return node;
}
int main(int argc,char **argv){
  FILE *fin=fopen(argv[1],"r");
  FILE *fout=fopen(argv[2],"w");
  char c;
  int new_word=1;
  while (fscanf(fin,"%c",&c)!=EOF){
    if (c==' ' || c=='\t' || c=='\n'){
      new_word=1;
      fprintf(fout,"%c",c);
    }
    else{
      if (c>='A' && c<='Z'){
        if (new_word)
          fprintf(fout,"%c",c);
        else
          fprintf(fout,"%c",c+32);
      }
      else
        fprintf(fout,"%c",c);
      new_word=0;
    }
  }
  fclose(fout);
  fclose(fin);
  fin=fopen(argv[2],"r");
  node_t *t=new_node(),*p=t;
  new_word=1;
  while (fscanf(fin,"%c",&c)!=EOF){
    if (c!=' ' && c!='\n' && c!='\t' && c!='\r'){
      if (new_word)
        p=t;
      if (c>='A' && c<='Z')
        c=c+32;
      if (p->c[c]==NULL)
        p->c[c]=new_node();
      new_word=0;
    }
    else{
      new_word=1;
      p->count++;
    }
  }
  fclose(fin);
}
