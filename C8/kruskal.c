#include"graph.h"
#include<stdio.h>
#define MAXV 100
#define INF 0x7fffffff
typedef struct{
  int u,v,w;
}edge_t;
typedef struct{
  int p;
  int rank;
}ufsnode_t;
void Qsort(edge_t edge[],int l,int r){
  int i,j=l-1,x=edge[r].w;
  if (l>=r)
    return;
  for (i=l;i<r;i++)
    if (edge[i].w<=x){
      j++;
      edge_t tmp=edge[j];
      edge[j]=edge[i];
      edge[i]=tmp;
    }
  j++;
  edge_t tmp=edge[j];
  edge[j]=edge[r];
  edge[r]=tmp;
  Qsort(edge,l,j-1);
  Qsort(edge,j+1,r);
}
int findset(ufsnode_t f[],int x){
  int p=x;
  if (x!=f[x].p)
    p=findset(f,f[x].p);
  f[x].p=p;
  return p;
}
void unionset(ufsnode_t f[],int x,int y){
  int px=findset(f,x);
  int py=findset(f,y);
  if (px!=py)
    if (f[px].rank>f[py].rank)
      f[py].p=px;
    else{
      f[px].p=py;
      if (f[px].rank==f[py].rank)
        f[py].rank++;
    }
}
void kruskal(mgraph *g){
  edge_t edge[MAXV*(MAXV-1)/2];
  int e=0;
  for (int i=0;i<g->n;i++)
    for (int j=i;j<g->n;j++)
      if (g->edges[i][j]&&g->edges[i][j]<INF){
        edge[e].u=i;
        edge[e].v=j;
        edge[e].w=g->edges[i][j];
        e++;
      }
  Qsort(edge,0,e-1);
  ufsnode_t f[MAXV];
  for (int i=0;i<g->n;i++){
    f[i].p=i;
    f[i].rank=0;
  }
  int k=0;
  for (int i=0;i<e;i++){
    int pu=findset(f,edge[i].u);
    int pv=findset(f,edge[i].v);
    if (pu!=pv){
      unionset(f,pu,pv);
      printf("(%d,%d):%d\n",edge[i].u,edge[i].v,edge[i].w);
      k++;
      if (k==g->n-1)
        break;
    }
  }
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
  kruskal(&mg);
}
