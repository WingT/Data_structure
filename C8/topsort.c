#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void topsort(algraph *g){
  int in[MAXV];
  for (int i=0;i<g->n;i++)
    in[i]=0;
  for (int i=0;i<g->n;i++){
    arcnode *p=g->adjlist[i];
    while (p){
      in[p->adjvex]++;
      p=p->nextarc;
    }
  }
  int st[MAXV],top=-1;
  for (int i=0;i<g->n;i++)
    if (in[i]==0)
      st[++top]=i;
  while (top>=0){
    int n=st[top--];
    printf("%d ",n);
    arcnode *p=g->adjlist[n];
    while (p){
      in[p->adjvex]--;
      if (in[p->adjvex]==0)
        st[++top]=p->adjvex;
      p=p->nextarc;
    }
  }
  printf("\n");
}
int main(void){
  int n;
  mgraph mg;
  algraph ag;
  scanf("%d",&n);
  mg.n=n;
  int e=0;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      int tmp;
      scanf("%d",&tmp);
      mg.edges[i][j]=tmp;
      if (!(i==j && tmp==0) && tmp<INF)
        e++;
    }
  mg.e=e;
  mat2list(&mg,&ag);
  topsort(&ag);
  return 0;
}
