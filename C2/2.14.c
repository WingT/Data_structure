#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next,*p;
}node;
void dels(node *h)
{
  node *tail=h->next,*p=tail->next;
  while (p)
    {
      if (p->data==tail->data)
        {
          tail->next=p->next;
          free(p);
          p=tail->next;
        }
      else
        {
          tail=p;
          p=p->next;
        }
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
  dels(h);
  node *p=h->next;
  while (p)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  return 0;
}
