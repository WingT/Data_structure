#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
typedef struct tbt_node{
  char ch;
  int ltag,rtag;
  struct tbt_node *l,*r;
}tbt_node;
extern node *str2tree(char s[]);
extern node *find_node(node *tree,char x);
extern void print_tree(node *p);
extern int tree_depth(node *t);
extern tbt_node *btree2inorder_tbtree(node *t);
extern void tb_inorder(tbt_node *t);
