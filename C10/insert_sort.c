#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void insert_sort(int data[],int n){
  for (int i=1;i<n;i++){
    int x=data[i],j;
    for (j=i-1;j>=0 && data[j]>x;j--)
      if (data[j]>x)
        data[j+1]=data[j];
    data[j+1]=x;
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=1;i<argc;i++)
    data[i-1]=atoi(argv[i]);
  insert_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
