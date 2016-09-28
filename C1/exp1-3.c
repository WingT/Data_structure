#include<stdio.h>
#include<string.h>
int main(int argc,char ** argv)
{
  int len=strlen(argv[1]);
  int mid=len/2;
  for (int i=0;i<mid;i++)
    if (argv[1][i]!=argv[1][len-i-1])
      {
        printf("No!\n");
        return 1;
      }
  printf("Yes!\n");
  return 0;
}
