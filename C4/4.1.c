#include<stdio.h>
#include"algo4-1.c"
int str_cmp(sq_string s,sq_string t)
{
  int min_length=s.length<t.length?s.length:t.length;
  for (int i=0;i<min_length;i++)
    if (s.data[i]<t.data[i])
      return -1;
    else
      if (s.data[i]>t.data[i])
        return 1;
  if (s.length==t.length)
    return 0;
  if (s.length>t.length)
    return 1;
  if (s.length<t.length)
    return -1;
}
int main(int argc,char **argv)
{
  sq_string s,t;
  str_assign(&s,argv[1]);
  str_assign(&t,argv[2]);
  printf("%d\n",str_cmp(s,t));
}
