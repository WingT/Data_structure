#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node* next;
}node;
node *merge(node *h1,node *h2)
{
  node *h3=(node *)malloc(sizeof(node));
  h3->next=NULL;
  node *p1=h1->next,*p2=h2->next,*tail=h3;
  while (p1!=NULL||p2!=NULL)
    {
      if (p1==NULL||p1->data>p2->data)
        {
          node *new=(node *)malloc(sizeof(node));
          new->data=p2->data;
          new->next=tail->next;
          tail->next=new;
          tail=new;
          p2=p2->next;
        }
      else
        {
          node *new=(node *)malloc(sizeof(node));
          new->data=p1->data;
          new->next=tail->next;
          tail->next=new;
          tail=new;
          p1=p1->next;
        }
    }
  return h3;
}
int main(void)
{
  int l1,l2;
  node *h1,*h2;
  h1=(node *)malloc(sizeof(node));
  h1->next=NULL;
  h2=(node *)malloc(sizeof(node));
  h2->next=NULL;
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
  node *h3=merge(h1,h2),*p=h3->next;
  while (p)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  return 0;
}
