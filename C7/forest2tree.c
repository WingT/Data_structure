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
node_t *tree2btree(node_t *t){
  if (t==NULL || t->stat==-1)
    return t;
  for (int i=0;i<=t->stat;i++)
    tree2btree(t->chld[i]);
  for (int i=t->stat;i>=1;i--){
    t->chld[i-1]->chld[1]=t->chld[i];
    t->chld[i-1]->stat=1;
    t->chld[i]=NULL;
  }
  t->stat=0;
  return t;
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
node_t *merge_tree(node_t *t1,node_t *t2){
  if (t1==NULL)
    return t2;
  if (t2==NULL)
    return t1;
  node_t *p=t1;
  while (p->stat==1)
    p=p->chld[p->stat];
  p->stat=1;
  p->chld[1]=t2;
  return t1;
}
int main(int argc,char **argv){
  node_t *btree=NULL;
  for (int i=1;i<argc;i++){
    btree=merge_tree(btree,tree2btree(str2tree(argv[i])));
  }
  print(btree);
  return 0;
}
