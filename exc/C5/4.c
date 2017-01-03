#include<stdio.h>
#define MAX 20
void perm(char data[],int p,int n){
  if (p==n-1){
    for (int i=0;i<n;i++)
      printf("%c ",data[i]);
    printf("\n");
  }
  for (int i=p;i<n;i++){
    int tmp=data[p];
    data[p]=data[i];
    data[i]=tmp;
    perm(data,p+1,n);
    tmp=data[p];
    data[p]=data[i];
    data[i]=tmp;
  }
}
int main(int argc,char **argv){
  char data[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=argv[i+1][0];
  perm(data,0,argc-1);
}
