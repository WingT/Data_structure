#include"btree.h"
#define MAXQUE 1000
int complete(node *t){
  typedef struct{
    int level;
    node *t;
  }qu;
  qu que[MAXQUE];
  int head=0,tail=-1,count=0;
  if (t==NULL)
    return 1;
  que[++tail].level=0;
  que[tail].t=t;
  count++;
  int level=0,continuous=1,bad_level=-1;
  while (count){
    node *p=que[head].t;
    if (level!=que[head].level){
      if (bad_level<0 && (2l<<level)!=count)
        bad_level=level+1;
      continuous=1;
    }
    level=que[head].level;
    if (!p->l && p->r)
      return 0;
    if (p->l){
      if (!continuous)
        return 0;
      tail=(tail+1)%MAXQUE;
      que[tail].level=level+1;
      que[tail].t=p->l;
      count++;
    }
    else continuous=0;
    if (p->r){
      if (!continuous)
        return 0;
      tail=(tail+1)%MAXQUE;
      que[tail].level=level+1;
      que[tail].t=p->r;
      count++;
    }
    else continuous=0;
    head=(head+1)%MAXQUE;
    count--;
  }
  if (bad_level>=0 && bad_level!=level)
    return 0;
  else
    return 1;
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  printf("%d",complete(t));
}
