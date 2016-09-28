#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define MAXQUE MAXSIZE*MAXSIZE
typedef struct{
  int i,j;
  int pre;
}data_t;
typedef struct{
  data_t data[MAXQUE];
  int head,tail;
}que;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void print(data_t data[],int loc)
{
  if (data[loc].i==0 && data[loc].j==0)
      printf("(1,1)");
  else
    {
      print(data,data[loc].pre);
      printf("->(%d,%d)",data[loc].i+1,data[loc].j+1);
    }
}
void try(int map[][MAXSIZE],int m,int n)
{
  int k,x,y,loc=0;
  que qu;
  qu.head=0;
  qu.tail=1;
  qu.data[0].i=0;
  qu.data[0].j=0;
  qu.data[0].pre=0;
  while (qu.head!=qu.tail)
    {
      if (qu.data[qu.head].i==m-1 && qu.data[qu.head].j==n-1)
        {
          loc=qu.head;
          break;
        }
      for (k=0;k<4;k++)
        {
          x=qu.data[qu.head].i+di[k];
          y=qu.data[qu.head].j+dj[k];
          if (x>=0 && x<m && y>=0 && y<n && !map[x][y])
            {
              map[x][y]=1;
              qu.data[qu.tail].i=x;
              qu.data[qu.tail].j=y;
              qu.data[qu.tail].pre=qu.head;
              qu.tail++;
            }
        }
      qu.head++;
    }
  if (loc)
    print(qu.data,loc);
  else
    printf("No solution!");
}
int main(void)
{
  int m,n;
  int map[MAXSIZE][MAXSIZE];
  scanf("%d",&m);
  scanf("%d",&n);
  for (int i=0;i<m;i++)
    for (int j=0;j<n;j++)
      scanf("%d",&map[i][j]);
  try(map,m,n);
  return 0;
}
