#include"btree.h"
int level(node *t,char ch,int h){
  if (!t)
    return 0;
  if (t->ch==ch)
    return h;
  int h1=level(t->l,ch,h+1);
  if (h1)
    return h1;
  else
    return level(t->r,ch,h+1);
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  char ch;
  while (1){
    scanf("%c",&ch);
    if (ch!='\n')
      printf("level:%d\n",level(t,ch,1));
  }
}
