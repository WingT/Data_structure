#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
void merge(int data[],int l,int r,int len){
  int m=l+len-1,i=l,j=m+1,tmp[MAX],k=0;
  while (i<=m&&j<=r)
    if (data[i]<=data[j])
      tmp[k++]=data[i++];
    else
      tmp[k++]=data[j++];
  while (i<=m)
    tmp[k++]=data[i++];
  while (j<=r)
    tmp[k++]=data[j++];
  for (int i=0;i<=r-l;i++)
    data[l+i]=tmp[i];
}
void mergesort(int data[],int n){
  for (int len=1;len<n;len*=2){
    int i;
    for (i=0;i<n-2*len;i+=len*2)
      merge(data,i,i+len*2-1,len);
    if (i+len<n)
      merge(data,i,n-1,len);
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=1;i<argc;i++)
    data[i-1]=atoi(argv[i]);
  mergesort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
}
