#include<stdio.h>
#define MAX 1000
int check(int a[],int b[],int n){
  int i=0,j=0,top=-1,st[MAX];
  while (i<n){
    if (top==-1||st[top]!=b[j])
      st[++top]=a[i++];
    else{
      top--;
      j++;
    }
  }
  while (j<n&&st[top]==b[j]){
    top--;
    j++;
  }
  return j==n;
}
int main(void){
  int n,a[MAX],b[MAX];
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
  for (int i=0;i<n;i++)
    scanf("%d",&b[i]);
  printf("a:");
  for (int i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  printf("b:");
  for (int i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  printf("%d\n",check(a,b,n));
}
