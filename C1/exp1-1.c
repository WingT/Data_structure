/*to prove this just make sure:*/
/*1.all composite numbers can be filtered out*/
/*2.no repetitive filter is carried out*/
/*note: all composite numbers can be written as the product of prime numbers*/
#include<stdio.h>
#include<stdlib.h>
#define FALSE 1
#define TRUE 0
int main(int argc,char **argv)
{
  int n=atoi(argv[1]);
  int *p=(int *)calloc(n+1,sizeof(int));
  short *flag=(short *)calloc(n+1,sizeof(short));
  p[0]=0;
  flag[1]=FALSE;
  for (int i=2;i<=n;i++)
    {
      if (flag[i]==TRUE)
        {
          p[0]++;
          p[p[0]]=i;
        }
      for (int j=1;j<=p[0];j++)
        {
          if (i*p[j]>n)
            break;
          flag[i*p[j]]=FALSE;
          if (i%p[j]==0)
            break;
        }
    }
  for (int i=1;i<=p[0];i++)
    printf("%d ",p[i]);
  printf("\n");
  return 0;
}
