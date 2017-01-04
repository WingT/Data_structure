#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000
typedef struct node_t {
  char c;
  struct node_t *l,*r;
}node_t;
node_t *newnode(char c){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->c=c;
  p->l=p->r=0;
  return p;
}
node_t *str2tree(char *s){
  node_t *p,*root;
  node_t *st[MAXN];
  int top=-1,lr=0;
  for (int i=0;s[i];i++){
    switch (s[i]){
    case '(':st[++top]=p;lr=0;break;
    case ')':top--;break;
    case ',':lr=1;break;
    default:{
      p=newnode(s[i]);
      if (top>-1)
        if (lr)
          st[top]->r=p;
        else
          st[top]->l=p;
      else
        root=p;
    }
    }
  }
  return root;
}
void printtree(node_t *t){
  if (t){
    printf("%c",t->c);
    if (t->l||t->r){
      printf("(");
      printtree(t->l);
      if (t->r){
        printf(",");
        printtree(t->r);
      }
      printf(")");
    }
  }
}
void postorder(node_t *t){
  node_t *st[MAXN];
  int st_stat[MAXN],top=-1;
  st[++top]=t;
  st_stat[top]=0;
  while (top>-1){
    node_t *p=st[top];
    if (st_stat[top]==0){
      st_stat[top]=1;
      if (p->l){
        st[++top]=p->l;
        st_stat[top]=0;
      }
      continue;
    }
    if (st_stat[top]==1){
      st_stat[top]=2;
      if (p->r){
        st[++top]=p->r;
        st_stat[top]=0;
      }
      continue;
    }
    /****************************/
    /* for (int i=0;i<=top;i++) */
    /*   printf("%c",st[i]->c); */
    /* printf("\n");            */
    /****************************/
    printf("%c",p->c);
    top--;
  }
}
void postorder2(node_t *t){
  node_t *st[MAXN],*p;
  int top=-1;
  do {
    while (t){
      st[++top]=t;
      t=t->l;
    }
    p=NULL;
    while (top>-1&&(t=st[top])->r==p){
      top--;
      p=t;
      printf("%c",t->c);//visit t
    }
    t=t->r;
  }while (top!=-1);
}
int main(int argc,char **argv){
  node_t *t=str2tree(argv[1]);
  postorder(t);
  printf("\n");
  postorder2(t);
  printf("\n");
}
