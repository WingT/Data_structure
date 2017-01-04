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
void preorder(node_t *t){
  typedef struct st_e{
    node_t *p;
    int stat;
  }st_e;
  st_e st[MAXN];
  int top=-1;
  st[++top].p=t;
  st[top].stat=0;
  while (top>-1){
    if (st[top].stat==0){
      printf("%c",st[top].p->c);
      st[top].stat=1;
      if (st[top].p->l){
        st[top+1].p=st[top].p->l;
        st[top+1].stat=0;
        top++;
      }
    }
    else{
      node_t *p=st[top--].p;
      if (p->r){
        st[top+1].p=p->r;
        st[top+1].stat=0;
        top++;
      }
    }
  }
}
void preorder2(node_t *t){
  node_t *st[MAXN],*p=t;
  int top=0;
  st[0]=NULL;
  while (p){
    printf("%c",p->c);
    if (p->r)
      st[++top]=p->r;
    if (p->l)
      p=p->l;
    else
      p=st[top--];
  }
}
void preorder3(node_t *t){
  node_t *st[MAXN];
  int top=-1;
  st[++top]=t;
  while (top>-1){
    node_t *p=st[top--];
    printf("%c",p->c);
    if (p->r)
      st[++top]=p->r;
    if (p->l)
      st[++top]=p->l;
  }
}
int main(int argc,char **argv){
  node_t *t=str2tree(argv[1]);
  preorder(t);
  printf("\n");
  preorder2(t);
  printf("\n");
  preorder3(t);
}
