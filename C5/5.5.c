#include<stdio.h>
#define MAX 10
typedef struct{
  int i,j;
}data_t;
typedef struct{
  data_t data[MAX*MAX];
  int len;
}path;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int try(int map[][MAX],int m,int n,int si,int sj,int ei,int ej,path *path)
{
  data_t data;
  data.i=si;
  data.j=sj;
  map[si][sj]=1;
  path->data[path->len++]=data;
  if (si==ei && sj==ej)
    {
      int i;
      for (i=0;i<path->len-1;i++)
        printf("(%d,%d)->",path->data[i].i,path->data[i].j);
      printf("(%d,%d)\n",path->data[i].i,path->data[i].j);
      map[si][sj]=0;
      path->len--;
      return 1;
    }
  else
    {
      int val=0,k;
      for (k=0;k<4;k++)
        {
          int x=si+di[k],y=sj+dj[k];
          if (x>=0 && x<m && y>=0 && y<n && !map[x][y])
            if (try(map,m,n,x,y,ei,ej,path))
              val=1;
        }
      map[si][sj]=0;
      path->len--;
      return val;
    }
}
int main(void)
{
  int m,n,si,sj,ei,ej;
  int map[MAX][MAX];
  path path;
  path.len=0;
  scanf("%d%d%d%d%d%d",&m,&n,&si,&sj,&ei,&ej);
  for (int i=0;i<m;i++)
    for (int j=0;j<n;j++)
      scanf("%d",&map[i][j]);
  if (try(map,m,n,si,sj,ei,ej,&path))
    return 0;
  else
    {
      printf("No way found!");
      return 1;
    }
}
