#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
  int len=strlen(argv[1]);
  int sum=0;
  for (int i=0;i<len;i++)
    sum+=argv[1][i]-48;
  printf("%d\n",sum);
  return 0;
}
