#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void dijkstra(mgraph *g,int v,int d[],int pre[]){
  int visited[MAXV];
  for (int i=0;i<g->n;i++){
    d[i]=g->edges[v][i];
    visited[i]=0;
    pre[i]=v;
  }
  visited[v]=1;
  for (int i=0;i<g->n-1;i++){
    int min_cost=INF,min_j;
    for (int j=0;j<g->n;j++)
      if (!visited[j] && min_cost>d[j]){
        min_cost=d[j];
        min_j=j;
      }
    visited[min_j]=1;
    for (int j=0;j<g->n;j++){
      int tmp=g->edges[min_j][j];
      if (!visited[j] && tmp<INF && d[min_j]+tmp<d[j]){
        d[j]=d[min_j]+tmp;
        pre[j]=min_j;
      }
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
  int v;
  int d[MAXV],pre[MAXV];
  scanf("%d",&v);
  dijkstra(&g,v,d,pre);
  for (int i=0;i<g.n;i++)
    printf("%d:%d\n",i,d[i]);
  for (int j=0;j<g.n;j++){
    printf("%d:",j);
    print_path(pre,v,j);
    printf("\n");
  }
  return 0;
}
