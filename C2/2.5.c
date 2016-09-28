#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  int freq;
  struct node *pre,*next;
}node;
node *locatenode(node *h,int x)
{
  node *p=h->next,*i;
  while (p&&p->data!=x)
    p=p->next;
  if (p)
    {
      p->freq++;
      i=p->pre;
      while (i!=h && i->freq<p->freq)
        i=i->pre;
      if (i!=p->pre)
        {
          if (p->next)
            p->next->pre=p->pre;
          p->pre->next=p->next;
          p->next=i->next;
          p->next->pre=p;
          p->pre=i;
          i->next=p;
        }
      return p;
    }
  else
    return NULL;
}
void test(node *h)
{
  int tmp;
  while (scanf("%d",&tmp)!=-1)
    {
      node *p=locatenode(h,tmp);
      if (p)
        printf("%d found,freq: %d\n",tmp,p->freq);
      else
        printf("%d not found!\n",tmp);
    }
}
int main(int argc,char **argv)
{
  node *h=(node *)malloc(sizeof(node)),*tail=h;
  h->pre=NULL;
  h->next=NULL;
  for (int i=1;i<=argc-1;i++)
    {
      node *new=(node *)malloc(sizeof(node));
      new->data=atoi(argv[i]);
      new->freq=0;
      new->next=tail->next;
      new->pre=tail;
      tail->next=new;
      tail=new;
    }
  test(h);
  printf("------------Summary-----------------\n");
  node *p=h->next;
  while (p!=NULL)
    {
      printf("data: %d,freq: %d\n",p->data,p->freq);
      p=p->next;
    }
  return 0;
}
