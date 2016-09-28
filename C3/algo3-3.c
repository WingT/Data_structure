#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct{
  data_t data[MAXSIZE];
  int head,tail,count;
}queue;
queue *create_queue(void)
{
  queue *new_queue=(queue *)malloc(sizeof(queue));
  return new_queue;
}
void init_queue(queue *q)
{
  q->head=0;
  q->tail=-1;
  q->count=0;
}
int queue_empty(queue *q)
{
  return (q->count==0);
}
void free_queue(queue *q)
{
  free(q);
}
int queue_length(queue *q)
{
  return q->count;
}
int enque(queue *q,data_t data)
{
  if (q->count==MAXSIZE)
    return 0;
  else
    {
      q->count++;
      q->tail=(q->tail+1)%MAXSIZE;
      q->data[q->tail]=data;
      return 1;
    }
}
int deque(queue *q,data_t *data)
{
  if (q->count)
    {
      q->count--;
      if (data)
        *data=q->data[q->head];
      q->head=(q->head+1)%MAXSIZE;
      return 1;
    }
  else
    return 0;
}
