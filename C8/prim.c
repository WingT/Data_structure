#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void prim(mgraph *g,int v){
  int visited[MAXV],lowcost[MAXV],closest[MAXV];
  for (int i=0;i<g->n;i++){
    visited[i]=0;
    lowcost[i]=g->edges[v][i];
    closest[i]=v;
  }
  visited[v]=1;
  for (int i=0;i<g->n-1;i++){
    int min_cost=INF,min_j;
    for (int j=0;j<g->n;j++)
      if (!visited[j]&&lowcost[j]<min_cost){
        min_cost=lowcost[j];
        min_j=j;
      }
    visited[min_j]=1;
    for (int j=0;j<g->n;j++)
      if (!visited[j]&&g->edges[min_j][j]<lowcost[j]){
        lowcost[j]=g->edges[min_j][j];
        closest[j]=min_j;
      }
  }
  int w=0;
  for (int i=0;i<g->n;i++){
    if (i!=v){
      printf("(%d,%d):%d\n",closest[i],i,g->edges[closest[i]][i]);
      w+=g->edges[closest[i]][i];
    }
  }
  printf("total cost:%d\n",w);
}
int main(void){
  int n;
  mgraph mg;
  scanf("%d",&n);
  mg.n=n;
  int e=0;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      scanf("%d",&mg.edges[i][j]);
      e++;
    }
  mg.e=e;
  int v;
  scanf("%d",&v);
  prim(&mg,v);
}
