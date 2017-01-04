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
int lca(node_t *t,char r,int *ra,char s,int *sa,node_t **ans){
  int lra,lsa,mra,msa,rra,rsa;
  if (t){
    int stat=lca(t->l,r,&lra,s,&lsa,ans);
    if (stat)
      return 1;
    stat=lca(t->r,r,&rra,s,&rsa,ans);
    if (stat)
      return 1;
    mra=t->c==r?1:0;
    msa=t->c==s?1:0;
    *ra=lra||mra||rra;
    *sa=lsa||msa||rsa;
    if (*ra&&*sa){
      *ans=t;
      return 1;
    }
    else
      return 0;
  }
  else{
    *ra=*sa=0;
    return 0;
  }
}
int main(int argc,char **argv){
  node_t *t=str2tree(argv[1]);
  char r=argv[2][0],s=argv[3][0];
  node_t *ans;
  int ra,sa;
  lca(t,r,&ra,s,&sa,&ans);
  printf("%c",ans->c);
}
