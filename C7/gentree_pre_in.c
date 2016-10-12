#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
  char ch;
  struct node *l,*r;
}node;
node *gentree_pre_in(char *pre,int pre_l,int pre_r,char *in,int in_l,int in_r){
  node *p=(node *)malloc(sizeof(node));
  p->ch=pre[pre_l];
  p->l=NULL;
  p->r=NULL;
  if (pre_l==pre_r)
    return p;
  else{
    int mid;
    for (mid=in_l;mid<=in_r && pre[pre_l]!=in[mid];mid++)
      ;
    if (mid!=in_l)
      p->l=gentree_pre_in(pre,pre_l+1,pre_l+mid-in_l,in,in_l,mid-1);
    if (mid!=in_r)
      p->r=gentree_pre_in(pre,pre_l+mid-in_l+1,pre_r,in,mid+1,in_r);
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
    printf("usage: %s preorder inorder",argv[0]);
  }
  else
    print(gentree_pre_in(argv[1],0,strlen(argv[1])-1,argv[2],0,strlen(argv[2])-1));
  printf("\n");
  return 0;
}
