#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next,*pre;
}node;
void insert(node *h1,node *h2,int loc)
{
  node *p=h1->next;
  int i=1;
  while (p!=h1&&i<loc)
    {
      p=p->next;
      i++;
    }
  if (loc && p!=h1)
    {
      h2->pre->next=p->next;
      p->next->pre=h2->pre;
      p->next=h2->next;
      h2->next->pre=p;
      free(h2);
    }
  else
    if (p==h1)
      {
        h1->pre->next=h2->next;
        h2->next->pre=h1->pre;
        h2->pre->next=h1;
        h1->pre=h2->pre;
        free(h2);
      }
    else
      {
        h2->pre->next=h1->next;
        h1->next->pre=h2->pre;
        h2->next->pre=h1;
        h1->next=h2->next;
        free(h2);
      }
}
int main(int argc,char **argv)
{
  node *h1=(node *)malloc(sizeof(node)),*h2=(node *)malloc(sizeof(node)),*tail;
  int x=atoi(argv[1]),y=atoi(argv[2]),loc=atoi(argv[argc-1]);
  h1->next=h1;
  h1->pre=h1;
  h2->next=h2;
  h2->pre=h2;
  tail=h1;
  for (int i=0;i<x;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=atoi(argv[i+3]);
      new->next=tail->next;
      new->pre=tail;
      tail->next=new;
      tail=new;
      h1->pre=new;
    }
  tail=h2;
  for (int i=0;i<y;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=atoi(argv[i+x+3]);
      new->next=tail->next;
      new->pre=tail;
      tail->next=new;
      tail=new;
      h2->pre=new;
    }
  insert(h1,h2,loc);
  node *p=h1->next;
  while (p!=h1)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  return 0;
}
