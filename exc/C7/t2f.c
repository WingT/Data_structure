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
void t2f(node_t *t,node_t *f,int idx){
  if (t){
    t2f(t->p[1],f,idx+1);
    f->p[idx]=t;
    t->p[1]=0;
    t2f(t->p[0],t,0);
  }
}
int main(int argc,char **argv){
  node_t *t=str2tree(argv[1]);
  node_t *f=newnode(0);
  f->p[0]=t;
  t2f(t,f,0);
  for (int i=0;i<MAXP;i++)
    if (f->p[i]){
      printtree(f->p[i]);
      printf("\n");
    }
    else
      break;
  return 0;
}
