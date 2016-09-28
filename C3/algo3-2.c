/******************************************************************************/
/* to use this as a header file,define data_t before include this one,such as */
/*   typedef char data_t;                                                     */
/******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  data_t data;
  struct node *next;
}node;
typedef struct{
  node *head,*tail;
  int count;
}stack;
stack *create_stack(void)
{
  stack *new_stack=(stack *)malloc(sizeof(stack));
  return new_stack;
}
void init_stack(stack *st)
{
  st->head=NULL;
  st->tail=NULL;
  st->count=0;
}
int stack_empty(stack *st)
{
  return (st->head==NULL);
}
void free_stack(stack *st)
{
  node *pre,*p=st->head;
  while (p)
    {
      pre=p;
      p=p->next;
      free(pre);
    }
  free(st);
}
int stack_length(stack *st)
{
  return st->count;
}
int get_top(stack *st,data_t *data)
{
  if (st->head==NULL)
    return 0;
  else
    {
      *data=st->head->data;
      return 1;
    }
}
data_t *get_top_ptr(stack *st)
{
  if (st->head==NULL)
    return NULL;
  else
    return &st->head->data;
}
int push(stack *st,data_t data)
{
  node *new_node=(node *)malloc(sizeof(node));
  new_node->data=data;
  new_node->next=st->head;
  st->count++;
  st->head=new_node;
  if (st->tail==NULL)
    st->tail=new_node;
  return 1;
}
int pop(stack *st,data_t *data)
{
  if (st->head)
    {
      st->count--;
      node *tmp=st->head;
      st->head=tmp->next;
      if (data)
        *data=tmp->data;
      free(tmp);
      if (st->head==NULL)
        st->tail=NULL;
      return 1;
    }
  else
    return 0;
}
