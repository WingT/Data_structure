typedef struct{
  int i,j;
}data_t;
#include"algo3-2.c"
#define MAX 20
int check(int map[],int x,int y)
{
  for (int k=0;k<y;k++)
    if (x==map[k] || x+y==map[k]+k || x-y==map[k]-k)
      return 0;
  return 1;
}
void print(int map[],int n)
{
  for (int i=0;i<n;i++)
    printf("%d ",map[i]);
  printf("\n");
}
void try(int n)
{
  int map[MAX];
  stack *st=create_stack();
  init_stack(st);
  data_t next;
  next.j=-1;
  next.i=-1;
  push(st,next);
  while (!stack_empty(st))
    {
      data_t *current;
      current=get_top_ptr(st);
      if (current->j==n-1)
        {
          print(map,n);
          pop(st,NULL);
        }
      else
        {
          int i;
          for (i=current->i+1;i<n;i++)
            if (check(map,i,current->j+1))
              {
                current->i=i;
                next.i=-1;
                next.j=current->j+1;
                map[current->j+1]=i;
                push(st,next);
                break;
              }
          if (i==n)
            pop(st,NULL);
        }
    }
  free_stack(st);
}
int main(int argc,char **argv)
{
  int n=atoi(argv[1]);
  try(n);
  return 0;
}
