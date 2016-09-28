#include<stdio.h>
#include<stdlib.h>
int main(int argc,char ** argv)
{
  int x=atoi(argv[1]),y=atoi(argv[2]),n=argc-3,*num=(int *)malloc(sizeof(int)*n),offset=0;
  for (int i=0;i<n;i++)
    num[i]=atoi(argv[i+3]);
  for (int i=0;i<n;i++)
    {
      if (num[i]>=x&&num[i]<=y)
        offset++;
      else
        num[i-offset]=num[i];
    }
  n-=offset;
  for (int i=0;i<n;i++)
    printf("%d ",num[i]);
  return 0;
}
