#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000
typedef struct{
  int data[MAXLINE];
  int top;
}st;
int push(st *st,int key)
{
  if (st->top==MAXLINE-1)
    return 1;
  else
    {
      st->data[++st->top]=key;
      return 0;
    }
}
int pop(st *st,int *key)
{
  if (st->top!=-1)
    {
      *key=st->data[st->top];
      st->top--;
      return 0;
    }
  else
    return 1;
}
void error(void)
{
  printf("invalid\n");
  exit(1);
}
int main(void)
{
  char s[MAXLINE];
  scanf("%s",s);
  int l=strlen(s),i,type;
  st st;
  st.top=-1;
  for (i=0;i<l;i++)
    switch (s[i])
      {
      case '(':
        push(&st,1);break;
      case ')':
        if (pop(&st,&type)||type!=1)
          error();
        break;
      case '[':
        push(&st,2);break;
      case ']':
        if (pop(&st,&type)||type!=2)
          error();
        break;
      case '{':
        push(&st,3);break;
      case '}':
        if (pop(&st,&type)||type!=3)
          error();
        break;
      }
  if (st.top>=0)
    error();
  else
    {
      printf("valid\n");
      return 0;
    }
}
