#include<stdio.h>
int main(int argc,char **argv)
{
  int stat=0;
  for (int i=1;i<argc;i++)
    if (argv[i][0]=='I')
      stat++;
    else
      {
        stat--;
        if (stat<0)
          {
            printf("invalid\n");
            return 1;
          }
      }
  if (stat>0)
    {
      printf("invalid\n");
      return 1;
    }
  printf("valid\n");
  return 0;
}
