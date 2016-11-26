#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void shell_sort(int data[],int n){
  for (int gap=n/2;gap>=1;gap/=2){
    for (int i=gap;i<n;i++){
      int j,x=data[i];
      for (j=i-gap;j>=0 && x<data[j];j-=gap)
        data[j+gap]=data[j];
      data[j+gap]=x;
    }
  }
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=atoi(argv[i+1]);
  shell_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
