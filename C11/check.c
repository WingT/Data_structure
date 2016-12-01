#include<stdio.h>
#define INF 0x80000000
int main(void){
  int a=INF,b;
  while (scanf("%d",&b)!=EOF){
    if (a>b){
      printf("wrong answer!\n");
      return 1;
    }
    a=b;
  }
  printf("right answer!\n");
  return 0;
}
