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
void link(node_t *t,node_t **pre,node_t **h){
  if (!t->l&&!t->r){
    if (*pre==NULL)
      *h=*pre=t;
    else{
      (*pre)->r=t;
      (*pre)=t;
    }
  }
  else{
    if (t->l)
      link(t->l,pre,h);
    if (t->r)
      link(t->r,pre,h);
  }
}
int main(int argc,char **argv){
  node_t *t=str2tree(argv[1]);
  node_t *h=NULL,*pre=NULL;
  link(t,&pre,&h);
  for (node_t *tmp=h;tmp;tmp=tmp->r)
    printf("%c",tmp->c);
}
