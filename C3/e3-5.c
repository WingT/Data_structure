#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct{
  int data[MAXSIZE];
  int front,rear,count;
}que;
int enque(que *q,int data)
{
  if (q->count==MAXSIZE)
    return 1;
  else
    {
      q->rear=(q->rear+1)%MAXSIZE;
      q->data[q->rear]=data;
      q->count++;
      return 0;
    }
}
int deque(que *q,int *data)
{
  if (q->count==0)
    return 1;
  else
    {
      *data=q->data[q->front];
      q->front=(q->front+1)%MAXSIZE;
      q->count--;
      return 0;
    }
}
void swap(int *a,int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
void reverse(que *q)
{
  int i=1,mid=(MAXSIZE-1)/2;
  for (i=0;i<=mid;i++)
    swap(&q->data[i],&q->data[MAXSIZE-1-i]);
  if (q->count)
    {
      q->front=MAXSIZE-1-q->rear;
      q->rear=MAXSIZE-1-q->front;
    }
}
void print(que q)
{
  int j=1,count=q.count,p=q.front;
  while (j<=count)
    {
      printf("%d ",q.data[p]);
      p=(p+1)%MAXSIZE;
      j++;
    }
}
int main(int argc,char **argv)
{
  que q;
  q.count=0;
  q.front=0;
  q.rear=-1;
  for (int i=1;i<argc;i++)
    enque(&q,atoi(argv[i]));
  reverse(&q);
  print(q);
  return 0;
}
