#include"graph.h"
void mat2list(mgraph *mg,algraph *ag){
  ag->n=mg->n;
  ag->e=mg->e;
  for (int i=0;i<ag->n;i++){
    ag->adjlist[i]=NULL;
    for (int j=0;j<ag->n;j++){
      if (mg->edges[i][j] && mg->edges[i][j]<0x7fffffff){
        arcnode *new_arc=(arcnode *)malloc(sizeof(arcnode));
        new_arc->adjvex=j;
        new_arc->nextarc=ag->adjlist[i];
        new_arc->w=mg->edges[i][j];
        ag->adjlist[i]=new_arc;
      }
    }
  }
}
void init_algraph(algraph *g){
  g->n=g->e=0;
  for (int i=0;i<MAXV;i++)
    g->adjlist[i]=NULL;
}
void trans_algraph(algraph *src,algraph *des){
  des->n=src->n;
  des->e=src->e;
  for (int i=0;i<src->n;i++){
    arcnode *p=src->adjlist[i];
    while (p){
      arcnode *new_arc=(arcnode *)malloc(sizeof(arcnode));
      new_arc->adjvex=i;
      new_arc->w=p->w;
      new_arc->nextarc=des->adjlist[p->adjvex];
      des->adjlist[p->adjvex]=new_arc;
      p=p->nextarc;
    }
  }
}
void free_algraph(algraph *g){
  for (int i=0;i<g->n;i++){
    arcnode *p=g->adjlist[i],*pre;
    while (p){
      pre=p;
      p=p->nextarc;
      free(pre);
    }
    g->adjlist[i]=NULL;
  }
}
