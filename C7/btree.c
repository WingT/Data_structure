#include<stdlib.h>
#include<stdio.h>
#define MAXLINE 1000
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
node *str2tree(char s[]){
  node *st[MAXLINE],*root;
  int top=-1,status;
  for (int i=0;s[i];i++){
    node *new_node;
    switch (s[i]){
    case '(':{
      st[++top]=new_node;
      status=1;//next node is lchild
    }break;
    case ',':
      status=2;//next node is rchild
      break;
    case ')':
      top--;
      break;
    default:{
      new_node=(node *)malloc(sizeof(node));
      new_node->ch=s[i];
      new_node->l=NULL;
      new_node->r=NULL;
      if (top==-1)
        root=new_node;
      else{
        if (status==1)
          st[top]->l=new_node;
        if (status==2)
          st[top]->r=new_node;
      }
    };
    }
  }
  return root;
}
node *find_node(node *tree,char x){
  if (!tree || tree->ch==x)
    return tree;
  node  *ans;
  if (ans=find_node(tree->l,x))
    return ans;
  if (ans=find_node(tree->r,x))
    return ans;
  return NULL;
}
void print_tree(node *p){
  if (p){
    printf("%c",p->ch);
    if (p->l||p->r){
      printf("(");
      if (p->l)
        print_tree(p->l);
      if (p->r){
        printf(",");
        print_tree(p->r);
      }
      printf(")");
    }
  }
}
int tree_depth(node *t){
  if (!t)
    return 0;
  int d1=tree_depth(t->l);
  int d2=tree_depth(t->r);
  return d1>d2?d1+1:d2+1;
}
