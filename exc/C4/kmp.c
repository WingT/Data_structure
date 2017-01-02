#include<stdio.h>
#include<string.h>
#define MAX 10000
void compute_next(char p[],int next[]){
  int l=strlen(p);
  next[0]=-1;
  next[1]=0;
  for (int i=2;i<l;i++){
    int q=next[i-1];
    while (q&&p[q]!=p[i-1])
      q=next[q];
    if (p[q]==p[i-1])
      q++;
    next[i]=q;
  }
  int q=next[l-1];
  while (q&&p[q]!=p[l-1])
    q=next[q];
  if (p[q]==p[l-1])
    q++;
  next[l]=q;
  printf("next:");
  for (int i=0;i<=l;i++)
    printf("%d ",next[i]);
  printf("\n-------------\n");
}
void kmp(char t[],char p[],int next[]){
  int q=0,lt=strlen(t),lp=strlen(p);
  for (int i=0;i<lt;i++){
    while (q&&t[i]!=p[q])
      q=next[q];
    if (t[i]==p[q])
      q++;
    if (q==lp){
      q=next[q];
      printf("%d\n",i-lp+1);
    }
  }
}
int main(int argc,char **argv){
  char *p=argv[1],*t=argv[2];
  int next[MAX];
  compute_next(p,next);
  kmp(t,p,next);
  return 0;
}
