#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}node;
typedef struct{
  node *rear;
}que;
int deque(que *q,int *data)
{
  if (q->rear)
    {
      *data=q->rear->next->data;
      if (q->rear==q->rear->next)
        {
          free(q->rear);
          q->rear=NULL;
        }
      else
        {
          node *tmp;
          tmp=q->rear->next;
          q->rear->next=tmp->next;
          free(tmp);
        }
      return 0;
    }
  else
    return 1;
}
int enque(que *q,int data)
{
  node *new=(node *)malloc(sizeof(node));
  new->data=data;
  if (q->rear)
    {
      new->next=q->rear->next;
      q->rear->next=new;
      q->rear=new;
    }
  else
    {
      new->next=new;
      q->rear=new;
    }
  return 0;
}
int main(void)
{
  que q;
  q.rear=NULL;
  int tmp,key;
  while (scanf("%d",&tmp)!=-1)
    if (tmp>0)
      enque(&q,tmp);
    else
      if (tmp<0)
        {
          if (deque(&q,&key))
            printf("queue empty!\n");
        }
      else
        return 0;
}
