#include"btree.h"
#define MAXSTACK 100
void inorder_norec(node *t){
  if (!t)
    return;
  node *st[MAXSTACK];
  int top=-1;
  node *p=t;
  while (top>=0 || p!=NULL){
    while (p){
      st[++top]=p;
      p=p->l;
    }
    p=st[top];
    printf("%c",p->ch);
    top--;
    p=p->r;
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  inorder_norec(t);
}
