#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
extern node *str2tree(char s[]);
extern node *find_node(node *tree,char x);
extern void print_tree(node *p);
extern int tree_depth(node *t);


