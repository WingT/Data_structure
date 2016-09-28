#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node* next;
}node;
void merge(node *h1,node *h2,node *h3)
{
  node *p1=h1->next,*p2=h2->next,*p3=h3->next,*pre=h1;
  while (p1&&p2&&p3)
    {
      while (p2&&p2->data<p1->data)
        p2=p2->next;
      while (p3&&p3->data<p1->data)
        p3=p3->next;
      if (p2&&p3&& p1->data==p2->data && p1->data==p3->data)
        {
          pre=p1;
          p1=p1->next;
        }
      else
        {
          pre->next=p1->next;
          free(p1);
          p1=pre->next;
        }
    }
  pre->next=NULL;
  if (p1!=NULL)
    {
      while (p1!=NULL)
        {
          pre=p1;
          p1=p1->next;
          free(pre);
        }
    }
}
int main(void)
{
  int l1,l2,l3;
  node *h1,*h2,*h3;
  h1=(node *)malloc(sizeof(node));
  h1->next=NULL;
  h2=(node *)malloc(sizeof(node));
  h2->next=NULL;
  h3=(node *)malloc(sizeof(node));
  h3->next=NULL;
  scanf("%d",&l1);
  node *tail=h1;
  for (int i=1;i<=l1;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      scanf("%d",&new->data);
      new->next=tail->next;
      tail->next=new;
      tail=new;
    }
  tail=h2;
  scanf("%d",&l2);
  for (int i=1;i<=l2;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      scanf("%d",&new->data);
      new->next=tail->next;
      tail->next=new;
      tail=new;
    }
  tail=h3;
  scanf("%d",&l3);
  for (int i=1;i<=l3;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      scanf("%d",&new->data);
      new->next=tail->next;
      tail->next=new;
      tail=new;
    }
  merge(h1,h2,h3);
  node *p=h1->next;
  while (p)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  return 0;
}
