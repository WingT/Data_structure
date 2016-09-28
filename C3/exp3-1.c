#include"algo3-1.c"
int main(int argc,char **argv)
{
  stack *l=create_stack();
  init_stack(l);
  if (stack_empty(l))
    printf("empty\n");
  else
    printf("not empty\n");
  push(l,'a');
  push(l,'b');
  push(l,'c');
  push(l,'d');
  push(l,'e');
  if (stack_empty(l))
    printf("empty\n");
  else
    printf("not empty\n");
  printf("%d\n",l->top+1);
  for (int i=l->top;i>=0;i--)
    printf("%c ",l->data[i]);
  printf("\n");
  while (! stack_empty(l))
    {
      data_t tmp;
      pop(l,&tmp);
      printf("%c ",tmp);
    }
  printf("\n");
  free_stack(l);
}
