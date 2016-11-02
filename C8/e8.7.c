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
void dfs(algraph *g,int s){
  int visited[MAXV];
  int st[MAXV],top=-1;
  for (int i=0;i<g->n;i++)
    visited[i]=0;
  st[++top]=s;
  visited[s]=1;
  while (top>=0){
    int v=st[top--];
    printf("%d ",v);
    arcnode *p=g->adjlist[v].firstarc;
    while (p){
      if (!visited[p->adjvex]){
        st[++top]=p->adjvex;
        visited[p->adjvex]=1;
      }
      p=p->nextarc;
    }
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
  int start;
  scanf("%d",&start);
  dfs(&ag,start);
}
