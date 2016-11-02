#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void dijkstra(algraph *g,int u,int d[],int pre[]){
  int visited[MAXV];
  for (int i=0;i<g->n;i++){
    visited[i]=0;
    d[i]=INF;
    pre[i]=i;
  }
  arcnode *p=g->adjlist[u];
  while (p){
    pre[p->adjvex]=u;
    d[p->adjvex]=p->w;
    p=p->nextarc;
  }
  visited[u]=1;
  d[u]=0;
  for (int i=0;i<g->n-1;i++){
    int min_cost=INF,min_j;
    for (int j=0;j<g->n;j++)
      if (!visited[j] && min_cost>d[j]){
        min_cost=d[j];
        min_j=j;
      }
    visited[min_j]=1;
    p=g->adjlist[min_j];
    while (p){
      if (!visited[p->adjvex] && d[min_j]+p->w<d[p->adjvex]){
        d[p->adjvex]=d[min_j]+p->w;
        pre[p->adjvex]=min_j;
      }
      p=p->nextarc;
    }
  }
}
void print_path(int pre[],int v,int j){
  if (j==v){
    printf("%d ",v);
    return;
  }
  else{
    print_path(pre,v,pre[j]);
    printf("%d ",j);
  }
}
int main(void){
  int n;
  mgraph g;
  scanf("%d",&n);
  g.n=n;
  int e=0;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      int tmp;
      scanf("%d",&tmp);
      g.edges[i][j]=tmp;
      if (!(i==j && tmp==0) && tmp<INF)
        e++;
    }
  g.e=e;
  algraph ag;
  mat2list(&g,&ag);
  int u,v;
  int d[MAXV],pre[MAXV];
  scanf("%d%d",&u,&v);
  dijkstra(&ag,u,d,pre);
  for (int i=0;i<g.n;i++)
    printf("%d:%d\n",i,d[i]);
  for (int j=0;j<g.n;j++){
    printf("%d:",j);
    print_path(pre,u,j);
    printf("\n");
  }
  return 0;
}
