#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
#define MAX 1000
void select_sort(int data[],int n){
  for (int i=0;i<n-1;i++){
    int min=INF,minj;
    for (int j=n-1;j>=i;j--)
      if (data[j]<min){
        min=data[j];
        minj=j;
      }
    int tmp=data[i];
    data[i]=data[minj];
    data[minj]=tmp;
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=1;i<argc;i++)
    data[i-1]=atoi(argv[i]);
  select_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
