#include"graph.h"
#include<stdio.h>
void dfs(algraph *ag,int s,int visited[]){
  printf("%d ",s);
  visited[s]=1;
  arcnode *p=ag->adjlist[s];
  while (p){
    if (!visited[p->adjvex])
      dfs(ag,p->adjvex,visited);
    p=p->nextarc;
  }
}
int main(void){
  mgraph mg;
  algraph ag;
  int n;
  scanf("%d",&n);
  mg.n=n;
  mg.e=0;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      scanf("%d",&mg.edges[i][j]);
      if (mg.edges[i][j])
        mg.e++;
    }
  mat2list(&mg,&ag);
  int start;
  scanf("%d",&start);
  int visited[MAXV];
  for (int i=0;i<n;i++)
    visited[i]=0;
  dfs(&ag,start,visited);
}
