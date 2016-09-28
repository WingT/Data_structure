#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}node;
typedef struct que{
  node *head,*tail;
}que;
int enque(que * qu,int key)
{
  node *new=(node *)malloc(sizeof(node));
  new->data=key;
  new->next=NULL;
  if (qu->head==NULL)
    qu->head=qu->tail=new;
  else
    {
      qu->tail->next=new;
      qu->tail=new;
    }
  return 0;
}
int deque(que * qu,int *key)
{
  if (qu->head)
    {
      node *tmp=qu->head;
      qu->head=tmp->next;
      *key=tmp->data;
      free(tmp);
      if (qu->head==NULL)
          qu->tail=NULL;
      return 0;
    }
  else
    return 1;
}
int main(int argc,char ** argv)
{
  que qu;
  qu.head=NULL;
  qu.tail=NULL;
  int n=atoi(argv[1]);
  for (int i=1;i<=n;i++)
    enque(&qu,i);
  int count=1,tmp;
  while (qu.head)
    {
      deque(&qu,&tmp);
      if (count%2)
        {
          printf("%d ",tmp);
          count++;
        }
      else
        {
          count++;
          enque(&qu,tmp);
        }
    }
  return 0;
}
