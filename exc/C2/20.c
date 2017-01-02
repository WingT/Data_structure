#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
void do_fun(int data[],int x,int n){
  int l=0,r=n-1,m;
  while (l<=r){
    m=(l+r)/2;
    if (x==data[m]){
      l=m;
      break;
    }
    if (x<data[m])
      r=m-1;
    else
      l=m+1;
  }
  if (data[l]==x){
    if (l<n-1){
    int tmp=data[l+1];
    data[l+1]=data[l];
    data[l]=tmp;
    }
    return;
  }
  for (int i=n-1;i>=l;i--)
    data[i+1]=data[i];
  data[l]=x;
}
int main(int argc,char **argv){
  int data[MAX];
  int x=atoi(argv[1]);
  for (int i=2;i<argc;i++)
    data[i-2]=atoi(argv[i]);
  do_fun(data,x,argc-2);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
  return 0;
}
