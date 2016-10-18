#include"btree.h"
#define MAXQUE 100
void level_order(node *t){
  if (!t) return;
  node *qu[MAXQUE];
  int head=0,tail=0,count=1;
  qu[tail]=t;
  while (count){
    node *now=qu[head];
    printf("%c",now->ch);
    if (now->l){
      tail=(tail+1)%MAXQUE;
      qu[tail]=now->l;
      count++;
    }
    if (now->r){
      tail=(tail+1)%MAXQUE;
      qu[tail]=now->r;
      count++;
    }
    head=(head+1)%MAXQUE;
    count--;
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  level_order(t);
}
