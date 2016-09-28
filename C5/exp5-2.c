#include<stdio.h>
#define MAX 1000
int f(int n,int W,int w[],int v[])
{
  if (n==0 || W<=0)
    return 0;
  int max,val;
  max=f(n-1,W,w,v);
  if (W>=w[n-1])
    {
      val=v[n-1]+f(n-1,W-w[n-1],w,v);
      max=max>val?max:val;
    }
  return max;
}
int main(void)
{
  int n,W,w[MAX],v[MAX];
  scanf("%d%d",&n,&W);
  for (int i=0;i<n;i++)
    scanf("%d",&v[i]);
  for (int i=0;i<n;i++)
    scanf("%d",&w[i]);
  printf("%d\n",f(n,W,w,v));
  return 0;
}
