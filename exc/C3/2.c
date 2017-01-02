#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int count;
void fun(int data[],int idx,int st[],int top,int output[],int n){
  if (idx==n&&top==-1){
    for (int i=0;i<n;i++)
      printf("%d ",output[i]);
    printf("\n");
    count++;
  }
  else{
    if (top>-1){
      int tmp=st[top];
      output[idx-top-1]=tmp;
      fun(data,idx,st,top-1,output,n);
      st[top]=tmp;
    }
    if (idx<n){
      st[top+1]=data[idx];
      fun(data,idx+1,st,top+1,output,n);
    }
  }
}
int main(int argc,char **argv){
  int data[MAX],st[MAX],output[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=atoi(argv[i+1]);
  fun(data,0,st,-1,output,argc-1);
  printf("total:%d\n",count);
  return 0;
}
