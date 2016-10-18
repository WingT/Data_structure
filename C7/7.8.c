#include"btree.h"
void disp_leaf(node *t){
  if (!t)
    return;
  if (!t->l && !t->r){
    printf("%c",t->ch);
    return;
  }
  disp_leaf(t->l);
  disp_leaf(t->r);
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  disp_leaf(t);
  return 0;
}
