#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
node *gentree_post_in(char *post,int post_l,int post_r,char *in,int in_l,int in_r){
  node *p=(node *)malloc(sizeof(node));
  p->ch=post[post_r];
  p->l=NULL;
  p->r=NULL;
  if (post_l==post_r)
    return p;
  else{
    int mid;
    for (mid=in_l;mid<=in_r && post[post_r]!=in[mid];mid++)
      ;
    if (mid!=in_r)
      p->r=gentree_post_in(post,post_r-in_r+mid,post_r-1,in,mid+1,in_r);
    if (mid!=in_l)
      p->l=gentree_post_in(post,post_l,post_r-in_r+mid-1,in,in_l,mid-1);
  }
  return p;
}
void print(node *p){
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
int main(int argc,char **argv){
  if (argc!=3){
    printf("usage: %s postorder inorder",argv[0]);
  }
  else
    print(gentree_post_in(argv[1],0,strlen(argv[1])-1,argv[2],0,strlen(argv[2])-1));
  printf("\n");
  return 0;
}
