#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct{
  int r,c,d;
}tupnode;
typedef struct{
  int r,c,n;
  tupnode data[MAXSIZE];
}tsmatrix;
int sum(tsmatrix *mat){
  int sum=0;
  for (int i=0;i<mat->n;i++){
    if (mat->data[i].r==mat->data[i].c || mat->data[i].r+mat->data[i].c==mat->r-1){
      sum+=mat->data[i].d;
    }
  }
  return sum;
}
int main(void){
  int m,n,count=0;
  tsmatrix mat;
  scanf("%d%d",&m,&n);
  mat.r=m;
  mat.c=n;
  for (int i=0;i<m;i++)
    for (int j=0;j<n;j++){
      scanf("%d",&mat.data[count].d);
      mat.data[count].r=i;
      mat.data[count].c=j;
      count++;
    }
  mat.n=count;
  printf("%d\n",sum(&mat));
}
