#include<stdio.h>
#include<stdlib.h>
void work(int n,int m)
{
  int s=0;
  for (int i=2;i<=n;i++)
    s=(s+m)%i;
  printf("%d\n",s+1);
}
int main(int argc,char **argv)
{
  if (argc !=3 || atoi(argv[1])==0 || atoi(argv[2])==0)
    return 1;
  else
    work(atoi(argv[1]),atoi(argv[2]));
}
