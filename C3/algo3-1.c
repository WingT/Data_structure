#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef char data_t;
typedef struct{
  data_t data[MAXSIZE];
  int top;
}stack;
stack *create_stack(void)
{
  stack *new_stack=(stack *)malloc(sizeof(stack));
  return new_stack;
}
void init_stack(stack *st)
{
  st->top=-1;
}
int stack_empty(stack *st)
{
  return (st->top==-1);
}
void free_stack(stack *st)
{
  free(st);
}
int push(stack *st,data_t data)
{
  if (st->top==MAXSIZE-1)
    return 0;
  else
    {
      st->data[++st->top]=data;
      return 1;
    }
}
int pop(stack *st,data_t *data)
{
  if (st->top==-1)
    return 0;
  else
    {
      *data=st->data[st->top];
      st->top--;
      return 1;
    }
}
