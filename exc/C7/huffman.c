#include<stdio.h>
#include<stdlib.h>
#define MAXN 100
typedef struct node_t{
  int f;
  struct node_t *l,*r;
}node_t;
node_t *newnode(int f){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->f=f;
  p->l=p->r=NULL;
  return p;
}
void minheapify(node_t *h[],int i,int n){
  node_t *x=h[i-1];
  int j=i;
  while (j<=n/2){
    int minj=j*2;
    if (j*2<n)
      minj=h[minj-1]->f<=h[j*2]->f?minj:j*2+1;
    minj=x->f<=h[minj-1]->f?j:minj;
    if (minj==j)
      break;
    else{
      h[j-1]=h[minj-1];
      j=minj;
    }
  }
  h[j-1]=x;
}
void initheap(node_t *h[],int n){
  for (int i=n/2;i>=1;i--)
    minheapify(h,i,n);
}
node_t *huffman(node_t *h[],int n){
  for (int i=n;i>1;i--){
    node_t *p1=h[0];
    h[0]=h[i-1];
    minheapify(h,1,i-1);
    node_t *p2=h[0];
    node_t *p3=newnode(p1->f+p2->f);
    p3->l=p1;
    p3->r=p2;
    h[0]=p3;
    minheapify(h,1,i-1);
  }
  return h[0];
}
void printtree(node_t *t){
  if (t){
    printf("%d",t->f);
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
int main(int argc,char **argv){
  node_t *node[MAXN*2-1];
  for (int i=1;i<argc;i++)
    node[i-1]=newnode(atoi(argv[i]));
  initheap(node,argc-1);
  node_t *t=huffman(node,argc-1);
  printtree(t);
}
