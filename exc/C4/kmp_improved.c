#include<stdio.h>
#include<string.h>
#define MAX 1000
void compute_nextval(char p[],int next[],int nextval[]){
  int lp=strlen(p);
  next[0]=-1;
  next[1]=0;
  for (int i=2;i<lp;i++){
    int q=next[i-1];
    while (q&&p[q]!=p[i-1])
      q=next[q];
    if (p[q]==p[i-1])
      q++;
    next[i]=q;
  }
  int q=next[lp-1];
  while (q&&p[q]!=p[lp-1])
    q=next[q];
  if (p[q]==p[lp-1])
    q++;
  next[lp]=q;
  nextval[0]=-1;
  for (int i=1;i<lp;i++){
    int q=next[i];
    while (q!=-1&&p[q]==p[i])
      q=next[q];
    nextval[i]=q;
  }
  nextval[lp]=next[lp];
  printf("next:");
  for (int i=0;i<=lp;i++)
    printf("%d ",next[i]);
  printf("\n");
  printf("nextval:");
  for (int i=0;i<=lp;i++)
    printf("%d ",nextval[i]);
  printf("\n");
}
void kmp(char t[],char p[],int nextval[]){
  int lt=strlen(t),lp=strlen(p),q=0;
  for (int i=0;i<lt;i++){
    while (q!=-1&&t[i]!=p[q])
      q=nextval[q];
    q++;
    if (q==lp){
      q=nextval[lp];
      printf("%d\n",i-lp+1);
    }
  }
}
int main(int argc,char **argv){
  char *p=argv[1],*t=argv[2];
  int next[MAX],nextval[MAX];
  compute_nextval(p,next,nextval);
  kmp(t,p,nextval);
}
