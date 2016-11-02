#include<stdio.h>
#include<stdlib.h>
typedef struct
item{
  int p;
  int e;
  struct item *next;
}item;
typedef struct poly{
  item *head,*tail;
}poly;
poly ans,p;
void init_poly(poly *poly,int i){//将输入排序生成链表
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
      item *tmp=poly->head,*pre;
      while (tmp && tmp->e<e){
        pre=tmp;
        tmp=tmp->next;
      }
      if (tmp==poly->head){
        new_item->next=tmp;
        poly->head=new_item;
      }
      else{
        new_item->next=tmp;
        pre->next=new_item;
        if (tmp==NULL)
          poly->tail=new_item;
      }
    }
  }
}
void reinit_poly(poly *poly){//释放链表空间
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
    }//在被加多项式中寻找指数适当的项
    if (item_a && item_a->e == item_b->e)//找到了指数相同的项
      item_a->p+=item_b->p;
    else{//没有指数相同的项,则在被加多项式中插入相应的项
      item *new_item=(item *)malloc(sizeof(item));
      new_item->p=item_b->p;
      new_item->e=item_b->e;
      new_item->next=item_a;
      if (item_a == a->head){//在列表头插入
        a->head=new_item;
        pre=new_item;
        if (!a->tail)//链表为空
          a->tail=new_item;
      }
      else{
        pre->next=new_item;
        pre=new_item;
        if (!item_a)
          a->tail=item_a;//在链表尾插入
      }

    }
    item_b=item_b->next;
  }
}
void print_item(item *item){//同exp2-1
  if (item->p==0)
    return;
  if (item->p<0){
    printf("-");
    if (item->p!=-1)
      printf("%d",-item->p);
  }
  else
    if (item->p!=1)
      printf("%d",item->p);
  if (item->e!=0){
    printf("x");
    if (item->e!=1)
      printf("^%d",item->e);
  }
}
void print_poly(poly poly){
  item *item=poly.head;
  while (item && item->p==0)//忽略开头为0的项
    item=item->next;
  if (item==NULL){//如果全为0项,输出0
    printf("0\n");
    return;
  }
  print_item(item);
  item=item->next;
  while (item){
    if (item->p>0)
      printf("+");
    print_item(item);
    item=item->next;
  }
  printf("\n");
}
int main(void){
  int n;
  ans.head=ans.tail=NULL;//被加多项式初始化
  p.head=p.tail=NULL;//加多项式初始化
  printf("enter the number of polys:\n");
  scanf("%d",&n);//多项式个数
  for (int i=0;i<n;i++){
    init_poly(&p,i);//读取加多项式
    add_poly(&ans,&p);//计算多项式和
    reinit_poly(&p);//释放加多项式空间,重新初始化
  }
  printf("answer: ");
  print_poly(ans);//输出多项式
}
