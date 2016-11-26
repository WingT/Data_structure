#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
void quick_sort(int data[],int l,int r){
  int i=l,j=r,x;
  if (l>=r)
    return;
  int k=rand()%(r-l+1)+l;
  int tmp=data[k];
  data[k]=data[l];
  data[l]=tmp;
  x=data[l];
  while (i<j){
    while (i<j && data[j]>=x)
      j--;
    data[i]=data[j];
    while (i<j && data[i]<=x)
      i++;
    data[j]=data[i];
  }
  data[i]=x;
  quick_sort(data,l,i-1);
  quick_sort(data,i+1,r);
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=1;i<argc;i++)
    data[i-1]=atoi(argv[i]);
  time_t t=time(NULL);
  srand((unsigned)t);
  quick_sort(data,0,argc-2);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
