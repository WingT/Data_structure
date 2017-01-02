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
  node_t *p=h;
  do{
    node_t *q=p->next;
    p->next=p->pre;
    p->pre=q;
    p=q;
  }while (p!=h);
}
void print_list(node_t *h){
  node_t *p=h->next;
  while (p!=h){
    printf("%d ",p->n);
    p=p->next;
  }
}
void print_list_anticlockwise(node_t *h){
  node_t *p=h->pre;
  while (p!=h){
    printf("%d ",p->n);
    p=p->pre;
  }
}
int main(int argc,char **argv){
  node_t h={0,&h,&h};
  for (int i=1;i<argc;i++){
    node_t *p=new_node(atoi(argv[i]));
    h.pre->next=p;
    p->next=&h;
    p->pre=h.pre;
    h.pre=p;
  }
  print_list(&h);
  printf("\n");
  print_list_anticlockwise(&h);
  printf("\n");
  reverse_list(&h);
  print_list(&h);
  printf("\n");
  print_list_anticlockwise(&h);
  printf("\n");
  return 0;

}
