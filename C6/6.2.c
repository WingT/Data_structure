typedef int data_t;
#include"../C3/algo3-3.c"
void work(int n,int m)
{
  queue *q=create_queue();
  init_queue(q);
  for (int i=1;i<=n;i++)
    enque(q,i);
  for (int i=1;!queue_empty(q);i++)
    {
      int temp;
      deque(q,&temp);
      if (i%m)
        enque(q,temp);
      else
        printf("%d ",temp);
    }
  printf("\n");
}
int main(int argc,char **argv)
{
  if (argc !=3 || atoi(argv[1])==0 || atoi(argv[2])==0)
    return 1;
  else
    work(atoi(argv[1]),atoi(argv[2]));
}
