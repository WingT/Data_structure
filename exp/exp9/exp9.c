#include<stdio.h>
#include<math.h>
#define MAXV 100
#define INF (1L<<63)-1
void prim(int s,long d[][MAXV],int n){
  int closest[MAXV];
  long lowcost[MAXV];
  for (int i=0;i<n;i++){
    lowcost[i]=d[s][i];
    closest[i]=s;
  }
  for (int i=0;i<n-1;i++){
    long min=INF;
    int min_j;
    for (int j=0;j<n;j++){
      if (lowcost[j] && lowcost[j]<min){
        min=lowcost[j];
        min_j=j;
      }
    }
    lowcost[min_j]=0;
    for (int j=0;j<n;j++){
      if (lowcost[j]>d[min_j][j]){
        lowcost[j]=d[min_j][j];
        closest[j]=min_j;
      }
    }
  }
  double w=0;
  for (int i=0;i<n;i++)
    if (i!=s){
      printf("(%d,%d)\n",closest[i],i);
      w+=sqrt(d[closest[i]][i]);
    }
  printf("total:%lf\n",w);
}
int main(void){
  int n;
  int x[MAXV],y[MAXV];
  long d[MAXV][MAXV];
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    scanf("%d%d",&x[i],&y[i]);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  prim(0,d,n);
}
