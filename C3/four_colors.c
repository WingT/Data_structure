typedef struct{
  int i,k;
}data_t;
#include"algo3-2.c"
#include<stdio.h>
int map[100][100];
int colors[100];
int main(void)
{
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      scanf("%d",&map[i][j]);
  stack *st=create_stack();
  init_stack(st);
  data_t data={-1,0};
  push(st,data);
  while (!stack_empty(st))
    {
      data_t *cur_datap=get_top_ptr(st);
      if (cur_datap->i==n-1)
        {
          for (int i=0;i<n;i++)
            printf("%d ",colors[i]);
          printf("\n");
          colors[n-1]=0;
          pop(st,NULL);
        }
      else
        {
          int k,cur_i=cur_datap->i;
          for (k=cur_datap->k+1;k<=4;k++)
            {
              int flag=1;
              for (int j=0;j<=cur_i;j++)
                if (map[cur_i+1][j] && k == colors[j])
                  {
                    flag=0;
                    break;
                  }
              if (flag)
                {
                  cur_datap->k=k;
                  data_t new_data={cur_i+1,0};
                  colors[cur_i+1]=k;
                  push(st,new_data);
                  break;
                }
            }
          if (k>4)
            {
              if (cur_i>=0)
                colors[cur_i]=0;
              pop(st,NULL);
            }
        }
    }
  free_stack(st);
  return 0;
}
