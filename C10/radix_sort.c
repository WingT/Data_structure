#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
void radix_sort(int data[],int n){
  int count[10],finish=0,base=1,exchanged=0;
  int *a1=data,*a2=(int *)malloc(sizeof(int)*n);
  while (1){
    for (int i=0;i<10;i++)
      count[i]=0;
    finish=0;
    for (int i=0;i<n;i++){
      int idx=(a1[i]/base)%10;
      finish=finish || (a1[i]/base);
      count[idx]++;
    }
    finish=!finish;
    if (finish)
      break;
    for (int i=1;i<10;i++)
      count[i]+=count[i-1];
    for (int i=n-1;i>=0;i--){
      int idx=(a1[i]/base)%10;
      a2[--count[idx]]=a1[i];
    }
    base*=10;
    int *tmp=a1;
    a1=a2;
    a2=tmp;
    exchanged=!exchanged;
  }
  if (exchanged){
    for (int i=0;i<n;i++)
      data[i]=a1[i];
    free(a1);
  }
  else
    free(a2);
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=atoi(argv[i+1]);
  radix_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
