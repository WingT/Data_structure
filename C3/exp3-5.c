typedef struct{
  int i,j,k;
}data_t;
#include"algo3-2.c"
#define MAX 100
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void print_iter(node *p)
{
  if (p==NULL)
    return;
  else
    {
      print_iter(p->next);
      printf("(%d,%d)->",p->data.i,p->data.j);
    }
}
void print(stack *st)
{
  print_iter(st->head->next);
  printf("(%d,%d)",st->head->data.i,st->head->data.j);
  printf("\n");
}
stack *stack_copy(stack *src)
{
  stack *tmp_st=create_stack(),*des=create_stack();
  init_stack(tmp_st);
  init_stack(des);
  node *p=src->head;
  while (p)
    {
      push(tmp_st,p->data);
      p=p->next;
    }
  p=tmp_st->head;
  while (p)
    {
      push(des,p->data);
      p=p->next;
    }
  free_stack(tmp_st);
  return des;
}
int try(int map[][MAX],int m,int n,int si,int sj,int ei,int ej)
{
  stack *st=create_stack(),*shortest_st=create_stack();
  int val=0,min_length=20;
  init_stack(st);
  init_stack(shortest_st);
  data_t next;
  next.i=si;
  next.j=sj;
  next.k=0;
  map[si][sj]=1;
  push(st,next);
  while (!stack_empty(st))
    {
      data_t *current=get_top_ptr(st);
      if (current->i==ei && current->j==ej)
        {
          val=1;
          print(st);
          if (stack_length(st)<min_length)
            {
              free_stack(shortest_st);
              shortest_st=stack_copy(st);
              min_length=stack_length(st);
            }
          map[current->i][current->j]=0;
          pop(st,NULL);
        }
      else
        {
          int k;
          for (k=current->k+1;k<4;k++)
            {
              int x=current->i+di[k],y=current->j+dj[k];
              if (x>=0 && x<m && y>=0 && y<n && !map[x][y])
                {
                  current->k=k;
                  next.i=x;
                  next.j=y;
                  next.k=0;
                  map[x][y]=1;
                  push(st,next);
                  break;
                }
            }
          if (k==4)
            {
              map[current->i][current->j]=0;
              pop(st,NULL);
            }
        }
    }
  if (val)
    {
      printf("----shortest-----\n");
      print(shortest_st);
    }
  free_stack(st);
  free_stack(shortest_st);
  return val;
}
int main(void)
{
  int m,n,si,sj,ei,ej;
  int map[MAX][MAX];
  scanf("%d%d%d%d%d%d",&m,&n,&si,&sj,&ei,&ej);
  for (int i=0;i<m;i++)
    for (int j=0;j<n;j++)
      scanf("%d",&map[i][j]);
  if (try(map,m,n,si,sj,ei,ej))
    return 0;
  else
    {
      printf("no way found\n");
      return 1;
    }
}
