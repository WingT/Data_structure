#include<stdio.h>
#include<stdlib.h>
#define move(a,b) printf("%c->%c\n",a,b)
void hanoi(int n,char a,char b,char c)
{
  if (n==1)
    {
      move(a,c);
      return;
    }
  hanoi(n-1,a,c,b);
  move(a,c);
  hanoi(n-1,b,a,c);
}
int main(int argc,char **argv)
{
  int n=atoi(argv[1]);
  hanoi(n,'A','B','C');
  return 0;
}
