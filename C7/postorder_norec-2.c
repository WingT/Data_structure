#include"btree.h"
#define MAXSTACK 1000
void postorder_norec(node *t){
  if (!t)
    return;
  node *st[MAXSTACK];
  int top=-1;
  node *next=t,*pre=NULL;
  while (top>=0 || next){
    while (next){
      st[++top]=next;
      next=next->l;
    }
    if (st[top]->r != pre && st[top]->r)
      next=st[top]->r;
    else{
      pre=st[top];
      top--;
      printf("%c",pre->ch);
    }
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  postorder_norec(t);
}
