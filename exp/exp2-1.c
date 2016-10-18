#include<stdio.h>
#define MAX 1000
typedef struct poly{
  int p[MAX],n;
}poly;
poly ans,p;
void init_poly(poly *poly,int i){
  int n;
  printf("enter the degree of poly %d:\n",i+1);
  scanf("%d",&n);
  printf("enter the coefficients of poly %d:\n",i+1);
  for (int i=0;i<=n;i++)
    scanf("%d",&poly->p[i]);
  poly->n=n;
}
void add_poly(poly *a,poly *b){
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
  ans.n=0;
  printf("enter the number of polys:\n");
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    init_poly(&p,i);
    add_poly(&ans,&p);
  }
  printf("answer:\n");
  printf("degree: %d\ncoefficients:",ans.n);
  for (int i=0;i<=ans.n;i++)
    printf("%d ",ans.p[i]);
  printf("\n");
  return 0;
}
