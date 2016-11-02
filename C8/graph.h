#include<stdlib.h>
#define MAXV 100
typedef struct{
  int edges[MAXV][MAXV];
  int e,n;
}mgraph;
typedef struct arcnode{
  int adjvex;
  int w;
  struct arcnode *nextarc;
}arcnode;
typedef struct{
  arcnode *adjlist[MAXV];
  int e,n;
}algraph;
extern void mat2list(mgraph *mg,algraph *ag);
extern void init_algraph(algraph *g);
extern void trans_algraph(algraph *src,algraph *des);
extern void free_algraph(algraph *g);
