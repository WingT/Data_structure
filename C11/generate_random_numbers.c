#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(int argc,char **argv){
  int n=atoi(argv[1]);
  time_t t=time(NULL);
  srand((unsigned)t);
  for (int i=0;i<n;i++)
    printf("%d ",rand());
}
