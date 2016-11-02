#include"btree.h"
#define MAXSTACK 100
void preorder_norec(node *t){
  if (!t)
    return;
  node *st[MAXSTACK],*next=t;
  int top=-1;
  while (top>=0 || next){
    while (next){
      printf("%c",next->ch);
      st[++top]=next;
      next=next->l;
    }
    next=st[top--]->r;
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  preorder_norec(t);
}
