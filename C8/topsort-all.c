#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void topsort_all(algraph *g,int in[],int path[],int d){
  for (int i=0;i<g->n;i++)
    if (in[i]==0){
      path[d]=i;
      if (d==g->n-1){
        for (int i=0;i<=d;i++)
          printf("%d ",path[i]);
        printf("\n");
      }
      arcnode *p=g->adjlist[i];
      while (p){
        in[p->adjvex]--;
        p=p->nextarc;
      }
      in[i]--;
      topsort_all(g,in,path,d+1);
      p=g->adjlist[i];
      while (p){
        in[p->adjvex]++;
        p=p->nextarc;
      }
      in[i]++;
    }
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
  int in[MAXV];
  for (int i=0;i<n;i++)
    in[i]=0;
  for (int i=0;i<n;i++){
    arcnode *p=ag.adjlist[i];
    while (p){
      in[p->adjvex]++;
      p=p->nextarc;
    }
  }
  int path[MAXV];
  topsort_all(&ag,in,path,0);
  return 0;
}
