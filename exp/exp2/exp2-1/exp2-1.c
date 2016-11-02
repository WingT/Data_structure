#include<stdio.h>
#define MAX 1000
typedef struct poly{
  int p[MAX],n;
}poly;
poly ans,p;
void init_poly(poly *poly,int i){//读取多项式
  int n;
  printf("enter the degree of poly %d:\n",i+1);
  scanf("%d",&n);
  printf("enter the coefficients of poly %d:\n",i+1);
  for (int i=0;i<=n;i++)
    scanf("%d",&poly->p[i]);
  poly->n=n;
}
void add_poly(poly *a,poly *b){//加多项式
  int min=a->n<b->n?a->n:b->n;
  int max=a->n>b->n?a->n:b->n;
  for (int i=0;i<=min;i++)
    a->p[i]+=b->p[i];
  if (a->n<b->n)
    for (int i=min+1;i<=max;i++)
      a->p[i]=b->p[i];
  a->n=max;
}
int main(void){
  int n;
  printf("enter the number of polys:\n");
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    init_poly(&p,i);
    add_poly(&ans,&p);
  }
  printf("answer:\n");
  int i;
  for (i=0;i<=ans.n && ans.p[i]==0;i++)
    ;//忽略开头的系数为0的项
  if (i==ans.n+1){
    printf("0\n");
    return 0;
  }//所有的系数都是0,结果为0
  if (i==0)
    printf("%d",ans.p[i]);//指数为0,直接输出系数
  else{
    if (ans.p[i]>0){
      if (ans.p[i]!=1)
        printf("%d",ans.p[i]);//系数为1时,不输出1,下同
      printf("x");
      if (i!=1)
        printf("^%d",i);//指数为1时,不输出,下同
    }
    else{
      printf("-");
      if (ans.p[i]!=-1)
        printf("%d",-ans.p[i]);
      printf("x");
      if (i!=1)
        printf("^%d",i);
    }
  }
  i++;
  for (;i<=ans.n;i++){
    if (ans.p[i]!=0){
      if (ans.p[i]>0){
        printf("+");
        if (ans.p[i]!=1)
          printf("%d",ans.p[i]);
        printf("x");
        if (i!=1)
          printf("^%d",i);
      }
      else{
        printf("-");
        if (ans.p[i]!=-1)
          printf("%d",-ans.p[i]);
        printf("x");
        if (i!=1)
          printf("^%d",i);
      }
    }
  }
  printf("\n");
  return 0;
}
