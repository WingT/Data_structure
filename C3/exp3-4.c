#include"algo3-4.c"
int main(void)
{
  queue *q;
  q=create_queue();
  init_queue(q);
  if (queue_empty(q))
    printf("empty\n");
  else
    printf("not empty\n");
  enque(q,'a');
  enque(q,'b');
  enque(q,'c');
  data_t tmp;
  deque(q,&tmp);
  printf("%c\n",tmp);
  printf("length:%d\n",queue_length(q));
  enque(q,'d');
  enque(q,'e');
  enque(q,'f');
  printf("length:%d\n",queue_length(q));
  while (!queue_empty(q))
    {
      deque(q,&tmp);
      printf("%c ",tmp);
    }
  printf("\n");
  free(q);
}
