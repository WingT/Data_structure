#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_t{
  char c;
  struct node_t *l,*r;
}node_t;
node_t *newnode(char c){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->c=c;
  p->l=p->r=NULL;
  return p;
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
node_t *gfpi(char post[],int pl,int pr,char in[],int il,int ir){
  if (pl>pr)
    return NULL;
  node_t *p=newnode(post[pr]);
  if (pl==pr)
    return p;
  int mid;
  for (mid=il;mid<=ir&&in[mid]!=post[pr];mid++)
    ;
  p->l=gfpi(post,pl,mid-il+pl-1,in,il,mid-1);
  p->r=gfpi(post,mid-il+pl,pr-1,in,mid+1,ir);
  return p;
}
int main(int argc,char **argv){
  int len=strlen(argv[1]);
  node_t *t=gfpi(argv[1],0,len-1,argv[2],0,len-1);
  printtree(t);
}
