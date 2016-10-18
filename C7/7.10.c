#include"btree.h"
int trees_resemble(node *t1,node *t2){
  if (!t1 && !t2)
    return 1;
  if (!t1 || !t2)
    return 0;
  return trees_resemble(t1->l,t2->l) && trees_resemble(t1->r,t2->r);
}
int main(int argc,char **argv){
  node *t1=str2tree(argv[1]);
  node *t2=str2tree(argv[2]);
  printf("%d\n",trees_resemble(t1,t2));
}
