#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}node;
node *merge(node *h1,node *h2)
{
  node *h3=(node *)malloc(sizeof(node)),*tail=h3,*p;
  h3->next=h3;
  p=h1->next;
  while (p!=h1)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=p->data;
      new->next=tail->next;
      tail->next=new;
      tail=new;
      p=p->next;
    }
  p=h2->next;
  while (p!=h2)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=p->data;
      new->next=tail->next;
      tail->next=new;
      tail=new;
      p=p->next;
    }
  return h3;
}
int main(int argc,char **argv)
{
  node *h1=(node *)malloc(sizeof(node)),*h2=(node *)malloc(sizeof(node)),*tail;
  int x=atoi(argv[1]),y=atoi(argv[2]);
  h1->next=h1;
  h2->next=h2;
  tail=h1;
  for (int i=0;i<x;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=atoi(argv[i+3]);
      new->next=tail->next;
      tail->next=new;
      tail=new;
    }
  tail=h2;
  for (int i=0;i<y;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=atoi(argv[i+x+3]);
      new->next=tail->next;
      tail->next=new;
      tail=new;
    }
  node *h3=merge(h1,h2);
  node *p=h3->next;
  while (p!=h3)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  return 0;
}
