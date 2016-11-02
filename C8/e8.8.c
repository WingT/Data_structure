#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
typedef struct{
  int edges[MAXV][MAXV];
  int n,e;
}mgraph;
typedef struct anode{
  int adjvex;
  struct anode *nextarc;
}arcnode;
typedef struct{
  int i;
  arcnode *firstarc;
}vnode;
typedef vnode adjlist[MAXV];
typedef struct{
  adjlist adjlist;
  int n,e;
}algraph;
void dfs(algraph *ag,int u,int v,int visited[],int path[],int d){
  if (u==v){
    for (int i=0;i<d;i++)
      printf("%d ",path[i]);
    printf("%d\n",v);
  }
  else{
    visited[u]=1;
    path[d]=u;
    arcnode *p=ag->adjlist[u].firstarc;
    while (p){
      if (!visited[p->adjvex])
        dfs(ag,p->adjvex,v,visited,path,d+1);
      p=p->nextarc;
    }
    visited[u]=0;
  }
}
int main(void){
  int n;
  mgraph mg;
  algraph ag;
  scanf("%d",&n);
  int e=0;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      scanf("%d",&mg.edges[i][j]);
      e++;
    }
  mg.n=n;mg.e=e;
  ag.n=n;ag.e=e;
  for (int i=0;i<n;i++){
    ag.adjlist[i].i=i;
    ag.adjlist[i].firstarc=NULL;
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++)
      if (mg.edges[i][j]){
        arcnode *p=(arcnode *)malloc(sizeof(arcnode));
        p->adjvex=j;
        p->nextarc=ag.adjlist[i].firstarc;
        ag.adjlist[i].firstarc=p;
      }
  }
  int u,v;
  int path[MAXV];
  int visited[MAXV];
  for (int i=0;i<ag.n;i++)
    visited[i]=0;
  scanf("%d%d",&u,&v);
  dfs(&ag,u,v,visited,path,0);
}
