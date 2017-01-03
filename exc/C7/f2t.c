#include<stdio.h>
#include<stdlib.h>
#define MAXP 5
#define MAXN 1000
typedef struct node_t{
  char c;
  struct node_t *p[MAXP];
}node_t;
node_t *newnode(char c){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->c=c;
  for (int i=0;i<MAXP;i++)
    p->p[i]=NULL;
  return p;
}
node_t *str2tree(char *s){
  node_t *p,*root;
  node_t *st[MAXN];
  int st_idx[MAXN];
  int top=-1;
  for (int i=0;s[i];i++){
    switch (s[i]){
    case '(':st[++top]=p;st_idx[top]=0;break;
    case ')':top--;break;
    case ',':st_idx[top]++;break;
    default:{
      p=newnode(s[i]);
      if (top>-1)
        st[top]->p[st_idx[top]]=p;
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
    int last=-1;
    for (int i=MAXP-1;i>=0;i--)
      if (t->p[i]){
        last=i;
        break;
      }
    if (last!=-1){
      printf("(");
      for (int i=0;i<last;i++){
        printtree(t->p[i]);
        printf(",");
      }
      printtree(t->p[last]);
      printf(")");
    }
  }
}
node_t *tree2btree(node_t *t){
  if (t){
    for (int i=0;i<MAXP;i++)
      tree2btree(t->p[i]);
    node_t *p=NULL,*first=NULL;
    for (int i=0;i<MAXP;i++){
      if (t->p[i]){
        if (p){
          p->p[1]=t->p[i];
          p=t->p[i];
        }
        else{
          p=t->p[i];
          first=p;
        }
        t->p[i]=NULL;
      }
    }
    t->p[0]=first;
  }
  return t;
}
node_t *mergetree(node_t *a,node_t *b){
  if (a==NULL)
    return b;
  node_t *p=a;
  while (p->p[1])
    p=p->p[1];
  p->p[1]=b;
  return a;
}
int main(int argc,char **argv){
  node_t *t=NULL;
  for (int i=1;i<argc;i++)
    t=mergetree(t,tree2btree(str2tree(argv[i])));
  printtree(t);
}
