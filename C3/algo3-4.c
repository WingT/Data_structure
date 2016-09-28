#include<stdio.h>
#include<stdlib.h>
typedef char data_t;
typedef struct node{
  data_t data;
  struct node *next;
}node;
typedef struct{
  node *head,*tail;
  int count;
}queue;
queue *create_queue(void)
{
  queue *new_queue=(queue *)malloc(sizeof(queue));
  return new_queue;
}
void init_queue(queue *q)
{
  q->head=NULL;
  q->tail=NULL;
  q->count=0;
}
int queue_empty(queue *q)
{
  return (q->head==NULL);
}
void free_queue(queue *q)
{
  node *pre,*p=q->head;
  while (p)
    {
      pre=p;
      p=p->next;
      free(pre);
    }
  free(q);
}
int queue_length(queue *q)
{
  return q->count;
}
int enque(queue *q,data_t data)
{
  node *new_node=(node *)malloc(sizeof(node));
  new_node->data=data;
  new_node->next=NULL;
  q->count++;
  if (q->head)
    {
      q->tail->next=new_node;
      q->tail=new_node;
    }
  else
    q->tail=q->head=new_node;
  return 1;
}
int deque(queue *q,data_t *data)
{
  if (q->head)
    {
      q->count--;
      node *tmp=q->head;
      q->head=tmp->next;
      *data=tmp->data;
      if (q->head==NULL)
        q->tail=NULL;
      free(tmp);
      return 1;
    }
  else
    return 0;
}
