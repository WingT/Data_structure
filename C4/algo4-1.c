#include<stdio.h>
#define MAXSIZE 100
typedef struct{
  char data[MAXSIZE];
  int length;
}sq_string;
void str_assign(sq_string *s,char cstr[])
{
  int i;
  for (i=0;cstr[i]!=0;i++)
    s->data[i]=cstr[i];
  s->length=i;
}
int str_length(sq_string s)
{
  return s.length;
}
sq_string ins_str(sq_string s1,int i,sq_string s2)
{
  sq_string ans;
  ans.length=0;
  if (i<=0 || i>s1.length)
    return ans;
  ans.length=s1.length+s2.length;
  for (int k=0;k<i-1;k++)
    ans.data[k]=s1.data[k];
  for (int k=0;k<s2.length;k++)
    ans.data[i-1+k]=s2.data[k];
  for (int k=i-1;k<s1.length;k++)
    ans.data[k+s2.length]=s1.data[k];
  return ans;
}
sq_string del_str(sq_string s,int i,int j)
{
  sq_string ans;
  ans.length=0;
  if (i<=0 || j<0 || i+j-1>s.length)
    return ans;
  ans.length=s.length-j;
  for (int k=0;k<i-1;k++)
    ans.data[k]=s.data[k];
  for (int k=i+j-1;k<s.length;k++)
    ans.data[k-j]=s.data[k];
  return ans;
}
void disp_str(sq_string s)
{
  for (int i=0;i<s.length;i++)
    printf("%c",s.data[i]);
}
