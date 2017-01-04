#include<stdio.h>
#include<stdlib.h>
int common_parent(int i,int j){
  int p=i,q=j;
  while (p!=q){
    if (p>q)
      p>>=1;
    else
      q>>=1;
  }
  return p;
}
int main(int argc,char **argv){
  printf("%d\n",common_parent(atoi(argv[1]),atoi(argv[2])));
}
