#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
void merge(int data[],int l,int mid,int r){
  int *tmp=(int *)malloc(sizeof(int)*(r-l+1));
  int i=l,j=mid+1,k=0;
  while (i<=mid && j<=r)
    if (data[i]<=data[j])
      tmp[k++]=data[i++];
    else
      tmp[k++]=data[j++];
  while (i<=mid)
      tmp[k++]=data[i++];
  while (j<=r)
      tmp[k++]=data[j++];
  for (k=r-l;k>=0;k--)
    data[l+k]=tmp[k];
  free(tmp);
}
void merge_sort(int data[],int n){
  for (int len=1;len<n;len*=2){
    int i;
    for (i=0;i+2*len<=n;i+=2*len)
      merge(data,i,i+len-1,i+2*len-1);
    if (i+len<n)
      merge(data,i,i+len-1,n-1);
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=atoi(argv[i+1]);
  merge_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
