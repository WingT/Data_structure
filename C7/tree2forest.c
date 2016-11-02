#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000
#define MAXCHLD 10
typedef struct node{
  char ch;
  int stat;
  struct node *chld[MAXCHLD];
}node_t;
node_t *new_node(){
  node_t *node=(node_t *)malloc(sizeof(node_t));
  node->stat=-1;
  for (int i=0;i<MAXCHLD;i++)
    node->chld[i]=NULL;
  return node;
}
node_t *str2tree(char s[]){
  node_t *root,*st[MAXLINE];
  int top=-1;
  for (int i=0;s[i];i++){
    node_t *node;
    switch (s[i]){
    case '(':
      st[++top]=node;
      st[top]->stat=0;
      break;
    case ',':
      st[top]->stat++;
      break;
    case ')':
      top--;
      break;
    default:{
      node=new_node();
      node->ch=s[i];
      if (top==-1)
        root=node;
      else
        st[top]->chld[st[top]->stat]=node;
    };
    }
  }
  return root;
}
void print(node_t *p){
  if (p==NULL)
    return;
  else{
    printf("%c",p->ch);
    if (p->stat==-1)
      return;
    printf("(");
    print(p->chld[0]);
    for (int i=1;i<=p->stat;i++){
      printf(",");
      print(p->chld[i]);
    }
    printf(")");
  }
}
void tree2forest(node_t *now,node_t *pa,int stat){
  if (now==NULL)
    return;
  now->stat=-1;
  tree2forest(now->chld[1],pa,stat+1);
  pa->chld[stat]=now;
  if (stat>pa->stat)
    pa->stat=stat;
  tree2forest(now->chld[0],now,0);
}
int main(int argc,char **argv){
  node_t *forest=new_node(),*tree=str2tree(argv[1]);
  forest->stat=0;
  forest->chld[0]=tree;
  tree2forest(tree,forest,0);
  for (int i=0;i<=forest->stat;i++){
    print(forest->chld[i]);
    printf("\n");
  }
  return 0;
}
