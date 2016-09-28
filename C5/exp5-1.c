#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int check(int map[],int x,int y)
{
  for (int k=0;k<y;k++)
    if (x==map[k] || x+y==map[k]+k || x-y==map[k]-k)
      return 0;
  return 1;
}
void try(int map[],int j,int n)
{
  if (j==n-1)
    {
      for (int i=0;i<n;i++)
        printf("%d ",map[i]);
      printf("\n");
    }
  else
    {
      for (int k=0;k<n;k++)
        {
          if (check(map,k,j+1))
            {
              map[j+1]=k;
              try(map,j+1,n);
            }
        }
    }
}
int main(int argc,char **argv)
{
  int n=atoi(argv[1]);
  int map[MAX];
  try(map,-1,n);
  return 0;
}
