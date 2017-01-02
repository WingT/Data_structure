#include<stdio.h>
#include<stdlib.h>
typedef struct node_t{
  int n;
  struct node_t *next,*pre;
}node_t;
node_t *new_node(int n){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->n=n;
  p->next=p->pre=NULL;
  return p;
}
void reverse_list(node_t *h){
  node_t *p=h->next;
  h->next=NULL;
  while (p){
    node_t *q=p->next;
    p->next=h->next;
    p->pre=h;
    if (h->next)
      h->next->pre=p;
    h->next=p;
    p=q;
  }
}
void print_list(node_t *p){
  p=p->next;
  while (p){
    printf("%d ",p->n);
    p=p->next;
  }
}
int main(int argc,char **argv){
  node_t h={0,NULL,NULL},*tail;
  h.next=new_node(atoi(argv[1]));
  h.next->pre=&h;
  tail=h.next;
  for (int i=2;i<argc;i++){
    tail->next=new_node(atoi(argv[i]));
    tail->next->pre=tail;
    tail=tail->next;
  }
  print_list(&h);
  printf("\n");
  reverse_list(&h);
  print_list(&h);
  printf("\n");
  return 0;

}
