#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 1000
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
int pri(char ch){
  switch (ch){
  case '+':return 1;break;
  case '-':return 1;break;
  case '*':return 2;break;
  case '/':return 2;break;
  }
  return 0;
}
node *new_node(char ch){
  node *new_node=(node *)malloc(sizeof(node));
  new_node->ch=ch;
  new_node->l=NULL;
  new_node->r=NULL;
  return new_node;
}
node *exp2tree(char *exp){
  struct{
    node *data[MAXSTACK];
    int top;
  }st1,st2;
  st1.top=-1;
  st2.top=-1;
  for (int i=0;exp[i];i++){
    if (exp[i]>='0' && exp[i]<='9')
      st2.data[++st2.top]=new_node(exp[i]);
    else{
      while (st1.top>=0 && pri(exp[i])<=pri(st1.data[st1.top]->ch)){
        node *p=st1.data[st1.top--];
        p->r=st2.data[st2.top--];
        p->l=st2.data[st2.top--];
        st2.data[++st2.top]=p;
      }
      st1.data[++st1.top]=new_node(exp[i]);
    }
  }
  while (st1.top>=0){
    node *p=st1.data[st1.top--];
    p->r=st2.data[st2.top--];
    p->l=st2.data[st2.top--];
    st2.data[++st2.top]=p;
  }
  return st2.data[0];
}
int eval(node *t){
  if (t->ch>='0'&&t->ch<='9')
    return t->ch-'0';
  else{
    switch (t->ch){
    case '+':return eval(t->l)+eval(t->r);
    case '-':return eval(t->l)-eval(t->r);
    case '*':return eval(t->l)*eval(t->r);
    case '/':return eval(t->l)/eval(t->r);
    }
  }
}
int main(int argc,char **argv){
  printf("%d",eval(exp2tree(argv[1])));
}
