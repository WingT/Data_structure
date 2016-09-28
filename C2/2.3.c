#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
void partition(int *a,int key,int l,int r)
{
  int i=l,j=l-1;
  for (i=l;i<=r;i++)
    if (a[i]<0)
      {
        j++;
        swap(a+l+i,a+l+j);
      }
}
int main(int argc,char **argv)
{
  int n=argc-1,*a=(int *)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++)
    a[i]=atoi(argv[i+1]);
  partition(a,0,0,n-1);
  for (int i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
