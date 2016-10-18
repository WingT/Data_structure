#include"btree.h"
#define MAXSTACK 100
void preorder_norec(node *t){
  if (!t)
    return;
  node *st[MAXSTACK];
  int top=-1;
  st[++top]=t;
  while (top>=0){
    node *p=st[top];
    printf("%c",p->ch);
    top--;
    if (p->r)
      st[++top]=p->r;
    if (p->l)
      st[++top]=p->l;
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  preorder_norec(t);
}
