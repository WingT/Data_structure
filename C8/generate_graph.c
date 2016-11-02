#include<stdio.h>
#define INF 0x7fffffff
int e[1000][1000];
int main(void){
  int n,digraph,weight;
  scanf("%d%d%d",&n,&digraph,&weight);
  if (weight){
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        e[i][j]=INF;
    for (int i=0;i<n;i++)
      e[i][i]=0;
    int i,j,w;
    while (scanf("%d%d%d",&i,&j,&w)!=EOF){
      e[i][j]=w;
      if (!digraph)
        e[j][i]=w;
    }
  }
  else{
    int i,j;
    while (scanf("%d%d",&i,&j)!=EOF){
      e[i][j]=1;
      if (!digraph)
        e[j][i]=1;
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++)
      printf("%d ",e[i][j]);
    printf("\n");
  }
  return 0;
}
