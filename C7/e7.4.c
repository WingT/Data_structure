#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
node *str2tree(char data[]){
  int n=strlen(data);
  node *tree[MAXLINE];
  for (int i=0;i<n;i++){
    if (data[i]!='#'){
      tree[i]=(node *)malloc(sizeof(node));
      tree[i]->ch=data[i];
    }
    else
      tree[i]=NULL;
  }
  for (int i=0;i<n;i++)
    if (tree[i]){
      if ((i+1)*2-1 < n)
        tree[i]->l=tree[(i+1)*2-1];
      else
        tree[i]->l=NULL;
      if ((i+1)*2 < n)
        tree[i]->r=tree[(i+1)*2];
      else
        tree[i]->r=NULL;
    }
  return tree[0];
}
void print(node *p){
  printf("%c",p->ch);
  if (p->l || p->r){
    printf("(");
    if (p->l)
      print(p->l);
    if (p->r){
      printf(",");
      print(p->r);
    }
    printf(")");
  }
}
int main(int argc,char **argv){
  print(str2tree(argv[1]));
  return 0;
}
