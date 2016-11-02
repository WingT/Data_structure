#include<stdlib.h>
#include<stdio.h>
#define MAXLINE 1000
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
typedef struct tbt_node{
  char ch;
  int ltag,rtag;
  struct tbt_node *l,*r;
}tbt_node;
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
static tbt_node *btree2half_tbtree(node *t){//copy btree elements to thread btree
  if (!t)
    return NULL;
  tbt_node *root=(tbt_node *)malloc(sizeof(tbt_node));
  root->ch=t->ch;
  root->l=btree2half_tbtree(t->l);
  root->r=btree2half_tbtree(t->r);
  return root;
}
static void thread_inorder(tbt_node *b,tbt_node **pre){
  if (b){
    if (b->l){
      b->ltag=0;
      thread_inorder(b->l,pre);
    }
    else b->ltag=1;
    if (b->ltag)
      b->l=(*pre);
    if ((*pre)->rtag)
      (*pre)->r=b;
    (*pre)=b;
    if (b->r){
      b->rtag=0;
      thread_inorder(b->r,pre);
    }
    else b->rtag=1;
  }
}
tbt_node *btree2inorder_tbtree(node *t){
  tbt_node *root=(tbt_node *)malloc(sizeof(tbt_node));
  root->ltag=0;
  root->rtag=1;
  tbt_node *b=btree2half_tbtree(t);
  root->r=b;
  if (!b)
    root->l=root;
  else{
    tbt_node *pre=root;
    root->l=b;
    thread_inorder(b,&pre);
    pre->r=root;
    pre->rtag=1;
    root->r=pre;
  }
  return root;
}
void tb_inorder(tbt_node *t){
  tbt_node *p=t->l;
  while (!p->ltag)
    p=p->l;
  while (1){
    printf("%c",p->ch);
    if (p->rtag){
      p=p->r;
      if (p==t)
        break;
    }
    else{
      p=p->r;
      if (p==t)
        break;
      while (!p->ltag)
        p=p->l;
    }
  }
}
void thread_preorder(tbt_node *p,tbt_node **pre){
  if (p==NULL){
    if ((*pre)->r==NULL)
      (*pre)->rtag=1;
    else
      (*pre)->rtag=0;
    return;
  }
  if (p->l==NULL){
    p->ltag=1;
    p->l=*pre;
  }
  else
    p->ltag=0;
  if ((*pre)->r==NULL){
    (*pre)->rtag=1;
    (*pre)->r=p;
  }
  else
    (*pre)->rtag=0;
  (*pre)=p;
  if (p->ltag==0)
    thread_preorder(p->l,pre);
  if (p->rtag==0)
    thread_preorder(p->r,pre);
}
tbt_node *btree2preorder_tbtree(node *t){
  tbt_node *root=(tbt_node *)malloc(sizeof(tbt_node));
  root->ltag=0;
  root->rtag=1;
  tbt_node *b=btree2half_tbtree(t);
  root->r=NULL;
  if (b==NULL)
    root->l=root;
  else{
    tbt_node *pre=root;
    root->l=b;
    thread_preorder(b,&pre);
    root->r=pre;
    pre->rtag=1;
    pre->r=root;
  }
  return root;
}
void tb_preorder(tbt_node *t){
  tbt_node *p=t->l;
  while (p!=t){
    while (!p->ltag){
      printf("%c",p->ch);
      p=p->l;
    };
    printf("%c",p->ch);
    p=p->r;
  }
}
void thread_postorder(tbt_node *p,tbt_node **pre){
  if (p==NULL)
    return;
  thread_postorder(p->l,pre);
  thread_postorder(p->r,pre);
  if (p->l==NULL){
    p->ltag=1;
    p->l=*pre;
  }
  else
    p->ltag=0;
  if ((*pre)->r==NULL){
    (*pre)->rtag=1;
    (*pre)->r=p;
  }
  else
    (*pre)->rtag=0;
  (*pre)=p;
}
tbt_node *btree2post_tbtree(node *t){
  tbt_node *root=(tbt_node *)malloc(sizeof(tbt_node));
  root->ltag=0;
  root->rtag=1;
  tbt_node *b=btree2half_tbtree(t);
  root->r=NULL;
  if (b==NULL)
    root->l=root;
  else{
    tbt_node *pre=root;
    root->l=b;
    thread_postorder(b,&pre);
    root->r=pre;
    if (pre->r)
      pre->rtag=0;
    else{
      pre->rtag=1;
      pre->r=root;
    }
  }
  return root;
}
