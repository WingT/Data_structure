#include"btree.h"
#define MAXSTACK 100
void all_path(node *t){
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
    if (st[top]->r && st[top]->r != pre)
      next=st[top]->r;
    else{
      pre=st[top];
      if (!pre->l && !pre->r){
        for (int i=top;i>0;i--)
          printf("%c->",st[i]->ch);
        printf("%c",st[0]->ch);
        printf("\n");
      }
      top--;
    }
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  all_path(t);
}
