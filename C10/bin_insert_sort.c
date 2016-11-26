#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void bin_insert_sort(int data[],int n){
  for (int i=1;i<n;i++){
    int x=data[i],l=0,r=i-1;
    while (l<=r){
      int mid=(l+r)/2;
      if (data[mid]>x)
        r=mid-1;
      else
        l=mid+1;
    }
    for (int j=i;j>l;j--)
      data[j]=data[j-1];
    data[l]=x;
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=atoi(argv[i+1]);
  bin_insert_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
