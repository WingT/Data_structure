#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void bubble_sort(int data[],int n){
  for (int i=0;i<n-1;i++){
    int changed=0;
    for (int j=n-1;j>i;j--)
      if (data[j]<data[j-1]){
        int tmp=data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
        changed=1;
      }
    if (!changed)
      break;
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=1;i<argc;i++)
    data[i-1]=atoi(argv[i]);
  bubble_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
