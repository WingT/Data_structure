#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void heap_sort(int data[],int n){
  for (int i=n/2-1;i>=0;i--){
    int x=data[i],j=i;
    while (j<n/2){
      int maxj=j,max=x;
      if ((j+1)*2<=n && data[(j+1)*2-1]>x){
        maxj=(j+1)*2-1;
        max=data[maxj];
      }
      if ((j+1)*2+1<=n && data[(j+1)*2]>max){
        maxj=(j+1)*2;
        max=data[maxj];
      }
      if (maxj!=j){
        data[j]=data[maxj];
        j=maxj;
      }
      else break;
    }
    data[j]=x;
  }//make heap
  for (int i=n-1;i>0;i--){
    int tmp=data[0];
    data[0]=data[i];
    data[i]=tmp;//swap
    int x=data[0],j=0;
    while (j<i/2){
      int maxj=j,max=x;
      if ((j+1)*2<=i && data[(j+1)*2-1]>x){
        maxj=(j+1)*2-1;
        max=data[maxj];
      }
      if ((j+1)*2+1<=i && data[(j+1)*2]>max){
        maxj=(j+1)*2;
        max=data[maxj];
      }
      if (maxj!=j){
        data[j]=data[maxj];
        j=maxj;
      }
      else break;
    }
    data[j]=x;
  }//sort
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=0;i<argc-1;i++)
    data[i]=atoi(argv[i+1]);
  heap_sort(data,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%d ",data[i]);
  printf("\n");
}
