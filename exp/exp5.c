#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 100
typedef struct node {
  struct node *next;
}node;
typedef struct{
  node *head,*tail;
  int count;
}que;
int single_time;
int main(int argc,char **argv){
  if (argc!=2){
    printf("usage:%s time\n",argv[0]);
    return 0;
  }
  char buf[MAXLINE];
  while (1){
    fgets(buf,MAXLINE,stdin);
  }
}
