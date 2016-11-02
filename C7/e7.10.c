#include"btree.h"
int is_alike(node *t1,node *t2){
  if (!t1 && !t2)
    return 1;
  if (!(t1 && t2))
    return 0;
  return is_alike(t1->r,t2->l)&&is_alike(t1->l,t2->r);
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  printf("%d",is_alike(t->l,t->r));
}
