#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
node *str2tree(char s[]){
  node *st[MAXLINE],*p;
  int top=-1,status=0;
  for (int i=0;s[i];i++){
    node *new_node;
    switch (s[i]){
    case '(':{
      p=new_node;
      st[++top]=new_node;
      status=1;//next node is lchild
    }break;
    case ',':
      status=2;//next node is rchild
      break;
    case ')':
      p=st[--top];
      if (top==-1)
        p=st[0];
      break;
    default:{
      new_node=(node *)malloc(sizeof(node));
      new_node->ch=s[i];
      new_node->l=NULL;
      new_node->r=NULL;
      if (top==-1)
        p=new_node;
      else{
        if (status==1)
          p->l=new_node;
        if (status==2)
          p->r=new_node;
      }
    };
    }
  }
  return p;
}
node *merge_tree(node *t1,node *t2){
  if (t1==NULL)
    return t2;
  if (t2==NULL)
    return t1;
  node *p=t1;
  while (p->r)
    p=p->r;
  p->r=t2;
  return t1;
}
void print(node *p){
  if (p){
    printf("%c",p->ch);
    if (p->l||p->r){
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
}
int main(int argc,char **argv){
  node *btree=NULL;
  for (int i=1;i<argc;i++){
    btree=merge_tree(btree,str2tree(argv[i]));
  }
  print(btree);
  return 0;
}
