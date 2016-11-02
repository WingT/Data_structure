#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void floyd(mgraph *g,int a[][MAXV],int path[][MAXV]){
  for (int i=0;i<g->n;i++)
    for (int j=0;j<g->n;j++){
      a[i][j]=g->edges[i][j];
      path[i][j]=i;
    }
  for (int k=0;k<g->n;k++)
    for (int i=0;i<g->n;i++)
      for (int j=0;j<g->n;j++)
        if (a[i][k]<INF && a[k][j]<INF && a[i][k]+a[k][j]<a[i][j]){
          a[i][j]=a[i][k]+a[k][j];
          path[i][j]=path[k][j];
        }
}
void print_path(int path[][MAXV],int i,int j){
  if (j==i){
    printf("%d ",i);
    return;
  }
  else{
    print_path(path,i,path[i][j]);
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
  int a[MAXV][MAXV],path[MAXV][MAXV];
  floyd(&g,a,path);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      printf("%d %d:%d:",i,j,a[i][j]);
      print_path(path,i,j);
      printf("\n");
    }
  return 0;
}
