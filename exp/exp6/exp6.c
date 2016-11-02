#include<stdio.h>
#include<string.h>
char key[100][601];
char text[100][10001];
int ans[100];
void compute_next(char p[],int next[]){
  int len=strlen(p);
  next[0]=0;
  next[1]=0;
  for (int i=2;i<=len;i++){
    int q=next[i-1];
    while (q && p[q]!=p[i-1])
      q=next[q];
    if (p[q]==p[i-1])
      q++;
    next[i]=q;
  }
  for (int i=2;i<len;i++)
    if (!(next[i]==0 || p[i]!=p[next[i]]))
      next[i]=next[next[i]];
}
int kmp_matcher(char p[],char t[],int next[]){
  int p_len=strlen(p),t_len=strlen(t);
  int q=0;
  for (int i=0;i<t_len;i++){
    while (q && p[q]!=t[i])
      q=next[q];
    if (p[q]==t[i])
      q++;
    if (q==p_len)
      return 1;
  }
  return 0;
}
int matcher(char *p,char *t){
  char buf[601];
  int p_len=strlen(p);
  for (int i=0;i<p_len;i++){
    for (int j=i;j<p_len;j++)
      buf[j-i]=p[j];
    for (int j=0;j<i;j++)
      buf[p_len-i+j]=p[j];
    buf[p_len]=0;
    int next[602];
    compute_next(buf,next);
    if (kmp_matcher(buf,t,next))
      return 1;
  }
  return 0;
}
int main(int argc,char **argv){
  int n;
  FILE *in=fopen(argv[1],"r");
  if (in==NULL){
    printf("no such file!\n");
    return 1;
  }
  fscanf(in,"%d",&n);
  for (int i=0;i<n;i++){
    fscanf(in,"%s",key[i]);
    fscanf(in,"%s",text[i]);
    ans[i]=matcher(key[i],text[i]);
  }
  fclose(in);
  FILE *out=fopen(argv[2],"w");
  if (out==NULL){
    printf("no such file!\n");
    return 1;
  }
  fprintf(out,"%d\n",n);
  for (int i=0;i<n;i++){
    fprintf(out,"%s %s ",key[i],text[i]);
    if (ans[i])
      fprintf(out,"YES\n");
    else
      fprintf(out,"NO\n");
  }
  fclose(out);
}
