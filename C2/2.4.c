#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next,*p;
}node;
void revert(node *h)
{
  node *p=h->next,*pre;
  h->next=NULL;
  while (p)
    {
      pre=p->next;
      p->next=h->next;
      h->next=p;
      p=pre;
    }
}
int main(int argc,char **argv)
{
  node *h=(node *)malloc(sizeof(node)),*tail=h;
  for (int i=1;i<=argc-1;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=atoi(argv[i]);
      new->next=NULL;
      tail->next=new;
      tail=new;
    }
  revert(h);
  node *p=h->next;
  while (p)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  return 0;
}
