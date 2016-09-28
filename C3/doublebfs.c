typedef struct{
  int i,j,num,next,pre;
}data_t;
#include<stdio.h>
int map[6][6];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
data_t que[10000];
void print_backward(int mid)
{
  if (mid==0)
    printf("(%d,%d)",que[mid].i,que[mid].j);
  else
    {
      print_backward(que[mid].pre);
      printf("->(%d,%d)",que[mid].i,que[mid].j);
    }
}
void print_forward(int mid)
{
  if (mid==1)
    printf("(%d,%d)",que[mid].i,que[mid].j);
  else
    {
      printf("(%d,%d)->",que[mid].i,que[mid].j);
      print_forward(que[mid].next);
    }
}
int main(void)
{
  data_t data;
  int m,n,si,sj,ti,tj;
  scanf("%d%d%d%d%d%d",&m,&n,&si,&sj,&ti,&tj);
  for (int i=0;i<m;i++)
    for (int j=0;j<n;j++)
      scanf("%d",&map[i][j]);
  data.i=si;
  data.j=sj;
  data.num=2;
  map[si][sj]=2;
  que[0]=data;
  data.i=ti;
  data.j=tj;
  data.num=3;
  que[1]=data;
  map[ti][tj]=3;
  int head=0,tail=1,mid=-1,done=0;
  data_t mid_data;
  while (head!=tail && !done)
    {
      data=que[head];
      for (int k=0;k<4;k++)
        {
          int X=data.i+di[k];
          int Y=data.j+dj[k];
          if (X>=0 && X<m && Y>=0 && Y<n)
            {
              if (map[X][Y]==5-data.num)
                {
                  mid=head;
                  mid_data.i=X;
                  mid_data.j=Y;
                  done=data.num;
                  break;
                }
              if (map[X][Y]==0)
                {
                  data_t new_data;
                  new_data.i=X;
                  new_data.j=Y;
                  new_data.num=data.num;
                  if (data.num==2)
                    new_data.pre=head;
                  else
                    new_data.next=head;
                  que[++tail]=new_data;
                  map[X][Y]=data.num;
                }
            }
        }
      head++;
    }
  if (done)
    {
      int mid2;
      for (mid2=mid+1;que[mid2].i!=mid_data.i || que[mid2].j!=mid_data.j;mid2++)
        ;
      if (done==3)
        {
          print_backward(mid2);
          printf("->");
          print_forward(mid);
        }
      else
        {
          print_backward(mid);
          printf("->");
          print_forward(mid2);
        }
    }
  return !done;
}
