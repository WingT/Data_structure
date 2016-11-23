#include<stdio.h>
#include<stdlib.h>
#define MAXM 10
typedef struct node_t{
  int n;
  int key[MAXM];
  struct node_t *c[MAXM],*p,*next;
}node_t;
typedef struct result_t{
  int flag,i;
  node_t *p;
}result_t;
typedef struct bptree_t{
  node_t *root,*sqt;
}bptree_t;
int m=4;
int min=2,max=4,lm=3,rm=2;
void bp_print(node_t *t){
  if (t==NULL)
    return;
  printf("[");
  for (int i=0;i<t->n-1;i++)
    printf("%d,",t->key[i]);
  printf("%d]",t->key[t->n-1]);
  printf("{");
  for (int i=0;i<t->n-1;i++){
    bp_print(t->c[i]);
    printf(",");
  }
  bp_print(t->c[t->n-1]);
  printf("}");
}
void bp_print_sqt(node_t *t){
  while (t){
    printf("[");
    for (int i=0;i<t->n-1;i++)
      printf("%d,",t->key[i]);
    printf("%d]",t->key[t->n-1]);
    t=t->next;
  }
}
int search_in_node(node_t *t,int key){
  int i;
  for (i=0;i<t->n && key>t->key[i];i++);
  return i;
}
result_t bp_search(node_t *t,int key){
  node_t *p=t;
  result_t r;
  int k;
  while (p->c[0]){
    k=search_in_node(p,key);
    if (k==p->n)
      k=p->n-1;
    p=p->c[k];
  }
  k=search_in_node(p,key);
  if (k<p->n && p->key[k]==key)
    r.flag=1;
  else
    r.flag=0;
  r.p=p;
  r.i=k;
  return r;
}
node_t *new_node(){
  node_t *p=(node_t *)malloc(sizeof(node_t));
  p->n=0;
  p->p=NULL;
  for (int i=0;i<MAXM;i++)
    p->c[i]=NULL;
  p->next=NULL;
  return p;
}
int bp_insert(bptree_t *bptree,int key){
  node_t *pt=bptree->root;
  if (pt==NULL){
    pt=new_node();
    pt->n=1;
    pt->key[0]=key;
    bptree->root=pt;
    bptree->sqt=pt;
    return 1;
  }
  result_t r=bp_search(pt,key);
  if (r.flag)
    return 0;
  pt=r.p;
  int tmp_key[MAXM+1];
  node_t *tmp_c[MAXM+1];
  node_t *newc=NULL;
  while (1){
    int k=search_in_node(pt,key);
    if (pt->n==max){
      for (int i=0;i<k;i++)
        tmp_key[i]=pt->key[i];
      tmp_key[k]=key;
      for (int i=k;i<max;i++)
        tmp_key[i+1]=pt->key[i];
      for (int i=0;i<k;i++)
        tmp_c[i]=pt->c[i];
      tmp_c[k]=newc;
      for (int i=k;i<max;i++)
        tmp_c[i+1]=pt->c[i];
      pt->n=lm;
      for (int i=0;i<lm;i++){
        pt->key[i]=tmp_key[i];
        pt->c[i]=tmp_c[i];
      }
      if (newc)
        newc->p=pt;
      newc=new_node();
      if (pt->c[0]==NULL){
        newc->next=pt->next;
        pt->next=newc;
      }
      newc->n=rm;
      for (int i=0;i<rm;i++){
        newc->key[i]=tmp_key[lm+i];
        newc->c[i]=tmp_c[lm+i];
        if (tmp_c[lm+i]!=NULL)
          tmp_c[lm+i]->p=newc;
      }
      if (pt->p){
        k=search_in_node(pt->p,pt->key[lm-1]);
        pt->p->key[k]=pt->key[lm-1];
      }
      else{
        node_t *tmp=new_node();
        pt->p=tmp;
        tmp->key[0]=tmp_key[lm-1];
        tmp->c[0]=pt;
        tmp->n=1;
        bptree->root=tmp;
      }
      key=tmp_key[m];
    }
    else{
      for (int i=pt->n-1;i>=k;i--){
        pt->key[i+1]=pt->key[i];
        pt->c[i+1]=pt->c[i];
      }
      pt->key[k]=key;
      pt->c[k]=newc;
      pt->n++;
      if (newc!=NULL)
        newc->p=pt;
      if (k==pt->n-1){
        node_t *tmp=pt->p;
        while (tmp){
          tmp->key[tmp->n-1]=key;
          tmp=tmp->p;
        }
      }
      break;
    }
    pt=pt->p;
  }
  return 1;
}
int bp_delete(bptree_t *bptree,int key){
  node_t *pt=bptree->root;
  result_t r=bp_search(pt,key);
  if (r.flag==0)
    return 0;
  pt=r.p;
  node_t *p=pt->p;
  if (p==NULL){
    if (pt->n==1){
      free(pt);
      bptree->root=bptree->sqt=NULL;
      return 1;
    }
    for (int i=r.i;i<pt->n-1;i++)
      pt->key[i]=pt->key[i+1];
    pt->n--;
    return 1;
  }
  for (int i=r.i;i<pt->n-1;i++)
    pt->key[i]=pt->key[i+1];
  pt->n--;
  while (1){
    if (pt->n>=min)
      break;
    if (p==NULL){
      if (pt->n==1){
        bptree->root=pt->c[0];
        pt->c[0]->p=NULL;
        free(pt);
      }
      break;
    }
    int k=search_in_node(p,key);
    node_t *lb=k>0?p->c[k-1]:NULL;
    node_t *rb=k<p->n-1?p->c[k+1]:NULL;
    if (lb!=NULL && lb->n > min){
      for (int i=pt->n;i>0;i--)
        pt->key[i]=pt->key[i-1];
      pt->key[0]=lb->key[lb->n-1];
      for (int i=pt->n;i>0;i--)
        pt->c[i]=pt->c[i-1];
      pt->c[0]=lb->c[lb->n-1];
      if (pt->c[0])
        pt->c[0]->p=pt;
      pt->n++;
      lb->n--;
      p->key[k-1]=lb->key[lb->n-1];
    }
    else{
      if (rb!=NULL && rb->n > min){
        pt->key[pt->n]=rb->key[0];
        pt->c[pt->n]=rb->c[0];
        if (rb->c[0])
          rb->c[0]->p=pt;
        pt->n++;
        p->key[k]=rb->key[0];
        for (int i=0;i<rb->n-1;i++)
          rb->key[i]=rb->key[i+1];
        for (int i=0;i<rb->n-1;i++)
          rb->c[i]=rb->c[i+1];
        rb->n--;
      }
      else{
        if (lb==NULL){
          lb=pt;
          pt=rb;
          k++;
        }
        for (int i=0;i<pt->n;i++)
          lb->key[lb->n+i]=pt->key[i];
        for (int i=0;i<pt->n;i++){
          lb->c[lb->n+i]=pt->c[i];
          if (pt->c[i])
            pt->c[i]->p=lb;
        }
        lb->n+=pt->n;
        lb->next=pt->next;
        free(pt);
        p->key[k-1]=lb->key[lb->n-1];
        for (int i=k;i<p->n-1;i++){
          p->key[i]=p->key[i+1];
          p->c[i]=p->c[i+1];
        }
        p->n--;
      }
    }
    pt=p;
    p=p->p;
  }
  return 1;
}
int main(int argc,char **argv){
  bptree_t bptree;
  bptree.root=bptree.sqt=NULL;
  int m=atoi(argv[1]);
  for (int i=0;i<m;i++){
    int tmp=atoi(argv[i+2]);
    bp_insert(&bptree,tmp);
  }
  bp_print(bptree.root);
  printf("\n");
  int n=atoi(argv[m+2]);
  for (int i=0;i<n;i++){
    int tmp=atoi(argv[m+3+i]);
    bp_delete(&bptree,tmp);
    bp_print(bptree.root);
    printf("\n");
  }
}
