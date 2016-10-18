#include"btree.h"
#define MAXSTACK 100
void inorder_norec(node *t){
    if (!t)
    return;
  typedef struct st_t{
    node *p;
    int status;
  }st_t;
  st_t st[MAXSTACK];
  int top=-1;
  st[++top].p=t;
  st[top].status=1;
  while (top>=0){
    switch (st[top].status){
    case 1:{
      st[top].status=2;
      if (st[top].p->l){
        st[top+1].p=st[top].p->l;
        st[top+1].status=1;
        top++;
      }
    }break;
    case 2:{
      printf("%c",st[top].p->ch);
      st[top].status=3;
      if (st[top].p->r){
        st[top+1].p=st[top].p->r;
        st[top+1].status=1;
        top++;
      }
    }break;
    case 3:top--;
    }
  }
}
int main(int argc,char **argv){
  node *t=str2tree(argv[1]);
  inorder_norec(t);
}
