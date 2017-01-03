/******************************************************************************************************************************************************************************************************************************************************************************************/
/* this program reads a tree in string form such as "1(2(,3),4(5,6))" from standard input,and then generates information needed by Graphviz to generate a graph,it uses the pointer's value of each node to distinguish them and attach them a label to make the graph readable,enjoy it! */
/******************************************************************************************************************************************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAXP 5
#define MAXN 1000
#define MAXLABEL 10
#define MAXLINE 10000
typedef struct node_t{
  char c[MAXLABEL];
  struct node_t *p[MAXP];
}node_t;
node_t *newnode(void){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->c[0]=0;
  for (int i=0;i<MAXP;i++)
    p->p[i]=NULL;
  return p;
}
node_t *str2tree(char *s){
  node_t *p,*root;
  node_t *st[MAXN];
  int st_idx[MAXN];
  int top=-1;
  for (int i=0;s[i];){
    switch (s[i]){
    case '(':st[++top]=p;st_idx[top]=0;i++;break;
    case ')':top--;i++;break;
    case ',':st_idx[top]++;i++;break;
    default:{
      p=newnode();
      int j=0;
      for (;s[i]&&s[i]!=','&&s[i]!='('&&s[i]!=')';i++,j++)
        p->c[j]=s[i];
      p->c[j]=0;
      if (top>-1)
        st[top]->p[st_idx[top]]=p;
      else
        root=p;
    }
    }
  }
  return root;
}
void gen_dot_content(node_t *t){
  printf("%ld[label=\"%s\"];\n",(long)t,t->c);
  for (int i=0;i<MAXP;i++){
    if (t->p[i]){
      printf("%ld->%ld;//%s->%s\n",(long)t,(long)t->p[i],t->c,t->p[i]->c);
      gen_dot_content(t->p[i]);
    }
  }
}
void gen_dot(node_t *t){
  printf("digraph G{\n");
  gen_dot_content(t);
  printf("}");
}
int main(void){
  char buf[MAXLINE];
  fgets(buf,MAXLINE,stdin);
  node_t *t=str2tree(buf);
  gen_dot(t);
  return 0;
}
