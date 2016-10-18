#include"btree.h"
int ancestor(node *t,char ch){
  if (!t)
    return 0;
  if (t->ch==ch)
    return 1;
  int ans=ancestor(t->l,ch)|| ancestor(t->r,ch);
  if (ans)
    printf("%c",t->ch);
  return ans;
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  char ch=argv[2][0];
  ancestor(t,ch);
}
