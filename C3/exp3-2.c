#include"algo3-2.c"
int main(void)
{
  stack *st;
  st=create_stack();
  init_stack(st);
  if (stack_empty(st))
    printf("empty\n");
  else
    printf("not empty\n");
  push(st,'a');
  push(st,'b');
  push(st,'c');
  push(st,'d');
  push(st,'e');
  if (stack_empty(st))
    printf("empty\n");
  else
    printf("not empty\n");
  printf("length:%d\n",stack_length(st));
  node *p=st->head;
  while (p)
    {
      printf("%c ",p->data);
      p=p->next;
    }
  printf("\n");
  while (!stack_empty(st))
    {
      data_t tmp;
      pop(st,&tmp);
      printf("%c ",tmp);
    }
  printf("\n");
  if (stack_empty(st))
    printf("empty\n");
  else
    printf("not empty\n");
  free(st);
}
