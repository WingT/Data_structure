#include<stdio.h>
#include<stdlib.h>
typedef struct item{
  int p;
  int e;
  struct item *next;
}item;
typedef struct poly{
  item *head,*tail;
}poly;
poly ans,p;
void init_poly(poly *poly,int i){
  int n;
  printf("enter the number of items of poly %d:\n",i+1);
  scanf("%d",&n);
  printf("enter p & e:\n");
  for (int i=0;i<n;i++){
    int p,e;
    scanf("%d%d",&p,&e);
    item *new_item=(item *)malloc(sizeof(item));
    new_item->p=p;
    new_item->e=e;
    new_item->next=NULL;
    if (!poly->head){
      poly->head=poly->tail=new_item;
    }
    else{
      poly->tail->next=new_item;
      poly->tail=new_item;
    }
  }
}
void reinit_poly(poly *poly){
  item *pre,*p=poly->head;
  while (p){
    pre=p;
    p=p->next;
    free(pre);
  }
  poly->head=poly->tail=NULL;
}
void add_poly(poly *a,poly *b){
  item *item_a=a->head,*item_b=b->head,*pre;
  while (item_b){
    while (item_a && item_a->e < item_b->e){
      pre=item_a;
      item_a=item_a->next;
    }
    if (item_a && item_a->e == item_b->e)
      item_a->p+=item_b->p;
    else{
      item *new_item=(item *)malloc(sizeof(item));
      new_item->p=item_b->p;
      new_item->e=item_b->e;
      new_item->next=item_a;
      if (item_a == a->head){
        a->head=new_item;
        pre=new_item;
        if (!a->tail)
          a->tail=new_item;
      }
      else{
        pre->next=new_item;
        pre=new_item;
        if (!item_a)
          a->tail=item_a;
      }

    }
    item_b=item_b->next;
  }
}
void print_poly(poly poly){
  item *item=poly.head;
  while (item){
    printf("(%d,%d)",item->p,item->e);
    item=item->next;
  }
  printf("\n");
}
int main(void){
  int n;
  ans.head=ans.tail=NULL;
  p.head=p.tail=NULL;
  printf("enter the number of polys:\n");
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    init_poly(&p,i);
    add_poly(&ans,&p);
    reinit_poly(&p);
  }
  printf("answer: ");
  print_poly(ans);
}
