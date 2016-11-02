#include"btree.h"
#define MAXQUE 1000
int isComplete(node *t){
  node *que[MAXQUE];
  int head=0,tail=-1,count=0;
  if (t==NULL)
    return 1;
  que[++tail]=t;
  count++;
  int continuous=1;
  while (count){
    node *p=que[head];
    if (!p->l && p->r)
      return 0;
    if (p->l){
      if (!continuous)
        return 0;
      tail=(tail+1)%MAXQUE;
      que[tail]=p->l;
      count++;
    }
    else continuous=0;
    if (p->r){
      if (!continuous)
        return 0;
      tail=(tail+1)%MAXQUE;
      que[tail]=p->r;
      count++;
    }
    else continuous=0;
    head=(head+1)%MAXQUE;
    count--;
  }
  return 1;
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  printf("%d",isComplete(t));
}
