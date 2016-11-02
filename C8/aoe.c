#include"graph.h"
#include<stdio.h>
#define INF 0x7fffffff
void work_ve(algraph *g,int ve[]){
  int in[MAXV];
  for (int i=0;i<g->n;i++){
    in[i]=0;
    ve[i]=0;
  }
  for (int i=0;i<g->n;i++){
    arcnode *p=g->adjlist[i];
    while (p){
      in[p->adjvex]++;
      p=p->nextarc;
    }
  }
  int st[MAXV],top=-1;
  for (int i=0;i<g->n;i++)
    if (in[i]==0)
      st[++top]=i;
  while (top>=0){
    int n=st[top--];
    arcnode *p=g->adjlist[n];
    while (p){
      int w=p->adjvex;
      ve[w]=ve[n]+p->w>ve[w]?ve[n]+p->w:ve[w];
      in[w]--;
      if (in[w]==0)
        st[++top]=w;
      p=p->nextarc;
    }
  }
}
void work_vl(algraph *g,int vl[],int ve[]){
  algraph tg;
  init_algraph(&tg);
  trans_algraph(g,&tg);
  int in[MAXV];
  for (int i=0;i<tg.n;i++){
    in[i]=0;
    vl[i]=INF;
  }
  for (int i=0;i<tg.n;i++){
    arcnode *p=tg.adjlist[i];
    while (p){
      in[p->adjvex]++;
      p=p->nextarc;
    }
  }
  int st[MAXV],top=-1;
  for (int i=0;i<tg.n;i++)
    if (in[i]==0){
      st[++top]=i;
      vl[i]=ve[i];
    }
  while (top>=0){
    int n=st[top--];
    arcnode *p=tg.adjlist[n];
    while (p){
      int w=p->adjvex;
      vl[w]=vl[n]-p->w<vl[w]?vl[n]-p->w:vl[w];
      in[w]--;
      if (in[w]==0)
        st[++top]=w;
      p=p->nextarc;
    }
  }
  free_algraph(&tg);
}
int main(void){
  int n;
  mgraph mg;
  algraph ag;
  scanf("%d",&n);
  mg.n=n;
  int e=0;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      int tmp;
      scanf("%d",&tmp);
      mg.edges[i][j]=tmp;
      if (tmp && tmp<INF)
        e++;
    }
  mg.e=e;
  mat2list(&mg,&ag);
  int ve[MAXV];
  work_ve(&ag,ve);
  int vl[MAXV];
  work_vl(&ag,vl,ve);
  for (int i=0;i<ag.n;i++){
    arcnode *p=ag.adjlist[i];
    while (p){
      if (ve[i]+p->w==vl[p->adjvex])
        printf("%d->%d:%d\n",i,p->adjvex,p->w);
      p=p->nextarc;
    }
  }
  return 0;
}
