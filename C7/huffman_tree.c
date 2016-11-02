#include<stdio.h>
#include<stdlib.h>
#define MAXARG 1000
typedef struct node{
  int d;
  struct node *l,*r;
}node;
typedef struct heap_t{
  node *data[MAXARG];
  int heapsize;
}heap_t;
void minheapify(heap_t *heap,int i){
  int j=i,k=heap->data[i]->d;
  while (1){
    int min_i=j;
    int l=(j+1)*2-1;
    if (l<heap->heapsize && heap->data[l]->d<k)
      min_i=l;
    int r=(j+1)*2;
    if (r<heap->heapsize && heap->data[r]->d<heap->data[min_i]->d)
      min_i=r;
    if (min_i==j){
      heap->data[j]->d=k;
      break;
    }
    else{
      heap->data[j]->d=heap->data[min_i]->d;
      j=min_i;
    }
  }
}
void init_heap(heap_t *heap){
  for (int i=heap->heapsize-1;i>=0;i--)
    minheapify(heap,i);
}
node *heap_extract(heap_t *heap){
  node *ans=heap->data[0];
  heap->data[0]=heap->data[--heap->heapsize];
  minheapify(heap,0);
  return ans;
}
void heap_insert(heap_t *heap,node *node){
  heap->data[heap->heapsize++]=node;
  int j=heap->heapsize-1,k=heap->data[j]->d;
  while (1){
    if (j==0){
      heap->data[0]->d=k;
      break;
    }
    int p=(j+1)/2-1;
    if (heap->data[p]->d>k){
      heap->data[j]->d=heap->data[p]->d;
      j=p;
    }
    else{
      heap->data[j]->d=k;
      break;
    };
  }
}
node *huffman_from_heap(heap_t *heap){
  node *t=NULL;
  while (heap->heapsize!=1){
    node *l=heap_extract(heap);
    node *r=heap_extract(heap);
    node *new_node=(node *)malloc(sizeof(node));
    new_node->d=l->d+r->d;
    new_node->l=l;
    new_node->r=r;
    t=new_node;
    heap_insert(heap,new_node);
  }
  return t;
}
void print(node *t){
  if (t){
    printf("%d",t->d);
    if (t->l || t->r){
      printf("(");
      print(t->l);
      if (t->r){
        printf(",");
        print(t->r);
      }
      printf(")");
    }
  }
}
int main(int argc,char **argv){
  heap_t heap;
  for (int i=1;i<argc;i++){
    heap.data[i-1]=(node *)malloc(sizeof(node));
    heap.data[i-1]->d=atoi(argv[i]);
    heap.data[i-1]->l=NULL;
    heap.data[i-1]->r=NULL;
  }
  heap.heapsize=argc-1;
  init_heap(&heap);
  printf("\n");
  print(huffman_from_heap(&heap));
}
