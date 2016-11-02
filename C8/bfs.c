#include"graph.h"
#include<stdio.h>
void bfs(algraph *ag,int s,int visited[]){
  int que[MAXV],head=0,tail=-1,count=0;
  printf("%d ",s);
  que[0]=s;
  visited[s]=1;
  tail++;
  count++;
  while (count>0){
    arcnode *p=ag->adjlist[que[head]];
    head=(head+1)%MAXV;
    count--;
    while (p){
      if (visited[p->adjvex]==0){
        printf("%d ",p->adjvex);
        visited[p->adjvex]=1;
        tail=(tail+1)%MAXV;
        que[tail]=p->adjvex;
        count++;
      }
      p=p->nextarc;
    }
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
  bfs(&ag,start,visited);
}
