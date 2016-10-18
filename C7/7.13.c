#include"btree.h"
#define MAXQUE 1000
void level_order(node *t){
  if (!t) return;
  typedef struct qu_t{
    node *pnode;
    int p;
  }qu_t;
  qu_t qu[MAXQUE];
  int head=0,tail=0,count=1;
  qu[tail].pnode=t;
  while (count){
    node *now=qu[head].pnode;
    if (!now->l && !now->r){
      int i=head;
      while (i){
        printf("%c",qu[i].pnode->ch);
        i=qu[i].p;
      }
      printf("%c\n",qu[0].pnode->ch);

    }
    if (now->l){
      qu[++tail].pnode=now->l;
      qu[tail].p=head;
      count++;
    }
    if (now->r){
      qu[++tail].pnode=now->r;
      qu[tail].p=head;
      count++;
    }
    head++;
    count--;
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  level_order(t);
}
