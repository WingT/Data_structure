#include<stdio.h>
#include<stdlib.h>
#define MAXQUE 8
typedef struct que{
  int data[MAXQUE];
  int head,tail,count;
}que;
int enque(que * qu,int key)
{
  if (qu->count==MAXQUE)
    return 1;
  else
    {
      qu->count++;
      qu->tail=(qu->tail+1)%MAXQUE;
      qu->data[qu->tail]=key;
      return 0;
    }
}
int deque(que * qu,int *key)
{
  if (qu->count==0)
    return 1;
  else
    {
      qu->count--;
      *key=qu->data[qu->head];
      qu->head=(qu->head+1)%MAXQUE;
      return 0;
    }
}
void initque(que *qu)
{
  qu->head=0;
  qu->tail=-1;
  qu->count=0;
}
int main(int argc,char ** argv)
{
  int n=atoi(argv[1]);
  que qu;
  initque(&qu);
  for (int i=1;i<=n;i++)
    enque(&qu,i);
  int count=1,tmp;
  while (qu.count)
    {
      deque(&qu,&tmp);
      if (count%2)
        {
          printf("%d ",tmp);
          count++;
        }
      else
        {
          count++;
          enque(&qu,tmp);
        }
    }
  return 0;
}
