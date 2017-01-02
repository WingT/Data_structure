#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void comb(int n,int r,int c,int p,int choices[]){
  if (n<r)
    return;
  if (p==r){
    for (int i=0;i<p;i++)
      printf("%d ",choices[i]);
    printf("\n");
    return;
  }
  for (int i=c+1;i<=n;i++){
    choices[p]=i;
    comb(n,r,i,p+1,choices);
  }
}
int main(int argc,char **argv){
  int choices[MAX];
  comb(atoi(argv[1]),atoi(argv[2]),0,0,choices);
}
