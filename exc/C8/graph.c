#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
#define INF 0x7fffffff
typedef struct mgraph_t{
  int n,e;
  int di,we;
  int edges[MAXV][MAXV];
}mgraph_t;
typedef struct arcnode_t{
  int adjvex;
  int w;
  struct arcnode_t *next;
}arcnode_t;
typedef struct vnode_t{
  arcnode_t *firstarc;
}vnode_t;
typedef vnode_t adjlist_t[MAXV];
typedef struct algraph_t{
  adjlist_t adjlist;
  int n,e;
  int di,we;
}algraph_t;
void init_mg(mgraph_t *mg){
  int n,e,di,we;
  scanf("%d%d%d%d",&n,&e,&di,&we);
  mg->n=n;
  mg->e=e;
  mg->di=di;
  mg->we=we;
  if (we){
    for (int i=0;i<n;i++){
      for (int j=0;j<i;j++)
        mg->edges[i][j]=INF;
      for (int j=i+1;j<n;j++)
        mg->edges[i][j]=INF;
    }
  }
  for (int i=0;i<e;i++){
    int x,y,w=1;
    scanf("%d%d",&x,&y);
    if (we)
      scanf("%d",&w);
    mg->edges[x][y]=w;
    if (!di)
      mg->edges[y][x]=w;
  }
}
arcnode_t *newarcnode(int adjvex,int w){
  arcnode_t *p=(arcnode_t *)malloc(sizeof(arcnode_t));
  p->adjvex=adjvex;
  p->w=w;
  p->next=NULL;
  return p;
}
void m2al(mgraph_t *mg,algraph_t *ag){
  ag->n=mg->n;
  ag->e=mg->e;
  ag->di=mg->di;
  ag->we=mg->we;
  for (int i=0;i<mg->n;i++){
    ag->adjlist[i].firstarc=NULL;
    for (int j=0;j<i;j++)
      if (mg->edges[i][j]!=INF){
        arcnode_t *tmp=newarcnode(j,mg->edges[i][j]);
        tmp->next=ag->adjlist[i].firstarc;
        ag->adjlist[i].firstarc=tmp;
      }
    for (int j=i+1;j<mg->n;j++)
      if (mg->edges[i][j]!=INF){
        arcnode_t *tmp=newarcnode(j,mg->edges[i][j]);
        tmp->next=ag->adjlist[i].firstarc;
        ag->adjlist[i].firstarc=tmp;
      }
  }
}
void print_ag(algraph_t *ag){
  for (int i=0;i<ag->n;i++){
    printf("%d->",i);
    arcnode_t *tmp=ag->adjlist[i].firstarc;
    while(tmp){
      printf("%d ",tmp->adjvex);
      tmp=tmp->next;
    }
    printf("\n");
  }
}
void DFS(algraph_t *ag,int u,int visited[]){
  printf("%d ",u);
  visited[u]=1;
  arcnode_t *tmp=ag->adjlist[u].firstarc;
  while(tmp){
    if (!visited[tmp->adjvex])
      DFS(ag,tmp->adjvex,visited);
    tmp=tmp->next;
  }
}
void BFS(algraph_t *ag,int u,int visited[]){
  int h=0,t=1,q[MAXV];
  q[0]=u;
  visited[u]=1;
  while (t!=h){
    u=q[h];
    printf("%d ",u);
    h=(h+1)%MAXV;
    arcnode_t *tmp=ag->adjlist[u].firstarc;
    while(tmp){
      if (!visited[tmp->adjvex]){
        q[t]=tmp->adjvex;
        t=(t+1)%MAXV;
        visited[tmp->adjvex]=1;
      }
      tmp=tmp->next;
    }
  }
}
void prim(mgraph_t *mg,int u,int lowcost[],int closest[]){
  int sum=0;
  for (int j=0;j<mg->n;j++){
    lowcost[j]=mg->edges[u][j];
    closest[j]=u;
  }
  for (int i=0;i<mg->n-1;i++){
    int min=INF,minj;
    for (int j=0;j<mg->n;j++)
      if (lowcost[j]&&lowcost[j]<min){
        min=lowcost[j];
        minj=j;
      }
    sum+=min;
    lowcost[minj]=0;
    for (int k=0;k<mg->n;k++)
      if (mg->edges[minj][k]<lowcost[k]){
        lowcost[k]=mg->edges[minj][k];
        closest[k]=minj;
      }
  }
  //print result
  for (int i=0;i<u;i++)
    printf("(%d,%d):%d\n",i,closest[i],mg->edges[i][closest[i]]);
  for (int i=u+1;i<mg->n;i++)
    printf("(%d,%d):%d\n",i,closest[i],mg->edges[i][closest[i]]);
  printf("total:%d\n",sum);
}
typedef struct edge_t{
  int x,y,w;
}edge_t;
void quicksort(edge_t edge[],int l,int r){
  if (l<r){
    int i=l,j=r;
    edge_t x=edge[l];
    while (i<j&&x.w<=edge[j].w)
      j--;
    edge[i]=edge[j];
    while (i<j&&edge[i].w<=x.w)
      i++;
    edge[j]=edge[i];
    edge[i]=x;
    quicksort(edge,l,i-1);
    quicksort(edge,i+1,r);
  }
}
typedef struct ufsnode_t{
  int p,r;
}ufsnode_t;
void mkset(ufsnode_t ufs[],int n){
  for (int i=0;i<n;i++){
    ufs[i].p=i;
    ufs[i].r=0;
  }
}
int findset(ufsnode_t ufs[],int x){
  if (ufs[x].p==x)
    return x;
  else{
    int p=findset(ufs,ufs[x].p);
    ufs[x].p=p;
    return p;
  }
}
void unionset(ufsnode_t ufs[],int x,int y){
  int px=findset(ufs,x),py=findset(ufs,y);
  if (ufs[px].r>ufs[py].r)
    ufs[py].p=px;
  else{
    ufs[px].p=py;
    if (ufs[px].r==ufs[py].r)
      ufs[py].r++;
  }
}
void kruskal(mgraph_t *mg){
  edge_t edge[(MAXV-1)*MAXV/2];
  int e=0;
  for (int i=0;i<mg->n;i++){
    for (int j=i+1;j<mg->n;j++)
      if (mg->edges[i][j]!=INF){
        edge[e].x=i;
        edge[e].y=j;
        edge[e++].w=mg->edges[i][j];
      }
  }
  quicksort(edge,0,e-1);
  ufsnode_t ufs[MAXV];
  mkset(ufs,mg->n);
  int sum=0;
  for (int i=0;i<e;i++){
    int px=findset(ufs,edge[i].x);
    int py=findset(ufs,edge[i].y);
    if (px!=py){
      sum+=edge[i].w;
      printf("(%d,%d):%d\n",edge[i].x,edge[i].y,edge[i].w);
      unionset(ufs,px,py);
    }
  }
  printf("total:%d\n",sum);
}
void printpath(int path[],int u,int i){
  if (i!=u){
    printpath(path,u,path[i]);
    printf("%d->",path[i]);
  }
}
void dijkstra(mgraph_t *mg,int u,int d[],int path[]){
  int s[MAXV];
  for (int j=0;j<mg->n;j++){
    d[j]=mg->edges[u][j];
    s[j]=0;
    path[j]=u;
  }
  s[u]=1;
  for (int i=0;i<mg->n-1;i++){
    int min=INF,minj;
    for (int j=0;j<mg->n;j++){
      if (!s[j]&&d[j]<min){
        min=d[j];
        minj=j;
      }
    }
    s[minj]=1;
    for (int k=0;k<mg->n;k++)
      if (!s[k]&&mg->edges[minj][k]!=INF&&mg->edges[minj][k]+d[minj]<d[k]){
        d[k]=mg->edges[minj][k]+d[minj];
        path[k]=minj;
      }
  }
  for (int i=0;i<mg->n;i++){
    printf("%d->%d:%d:",u,i,d[i]);
    printpath(path,u,i);
    printf("%d\n",i);
  }
}
void printpath2(int path[][MAXV],int u,int v){
  if (path[u][v]!=u){
    printpath2(path,u,path[u][v]);
    printf("%d->",path[u][v]);
  }
}
void floyd(mgraph_t *mg,int d[][MAXV],int path[][MAXV]){
  for (int i=0;i<mg->n;i++)
    for (int j=0;j<mg->n;j++){
      d[i][j]=mg->edges[i][j];
      path[i][j]=i;
    }
  for (int k=0;k<mg->n;k++)
    for (int i=0;i<mg->n;i++)
      for (int j=0;j<mg->n;j++)
        if (d[i][k]!=INF && d[k][j]!=INF && d[i][k]+d[k][j]<d[i][j]){
          d[i][j]=d[i][k]+d[k][j];
          path[i][j]=path[k][j];
        }
  for (int i=0;i<mg->n;i++)
    for (int j=0;j<mg->n;j++){
      if (d[i][j]!=INF){
        printf("%d->%d:%d:",i,j,d[i][j]);
        printpath2(path,i,j);
        printf("%d\n",j);
      }
    }
}
void topsort(mgraph_t *mg){
  int in[MAXV];
  for (int j=0;j<mg->n;j++){
    in[j]=0;
    for (int i=0;i<mg->n;i++)
      in[j]+=mg->edges[i][j];
  }
  int st[MAXV],top=-1;
  for (int i=0;i<mg->n;i++)
    if (!in[i])
      st[++top]=i;
  while (top>-1){
    int i=st[top--];
    printf("%d ",i);
    for (int j=0;j<mg->n;j++)
      if (mg->edges[i][j]){
        in[j]--;
        if (!in[j])
          st[++top]=j;
      }
  }
}
void topsort_all(mgraph_t *mg,int visited[],int in[],int path[],int len){
  for (int i=0;i<mg->n;i++){
    if (in[i]==0&&!visited[i]){
      visited[i]=1;
      for (int j=0;j<mg->n;j++)
        if (mg->edges[i][j])
          in[j]--;
      path[len]=i;
      if (len==mg->n-1){
        for (int i=0;i<mg->n;i++)
          printf("%d ",path[i]);
        printf("\n");
      }
      topsort_all(mg,visited,in,path,len+1);
      visited[i]=0;
      for (int j=0;j<mg->n;j++)
        if (mg->edges[i][j])
          in[j]++;
    }
  }
}
void AOE(mgraph_t *mg){
  int ve[MAXV],vl[MAXV],in[MAXV],x,y;
  for (int j=0;j<mg->n;j++){
    ve[j]=0;
    in[j]=0;
    for (int i=0;i<mg->n;i++)
      in[j]+=mg->edges[i][j]!=INF&&mg->edges[i][j];
    if (in[j]==0)
      x=j;
  }
  for (int i=0;i<mg->n;i++){
    int flag=1;
    for (int j=0;j<mg->n;j++)
      if (mg->edges[i][j]!=INF&&mg->edges[i][j]){
        flag=0;
        break;
      }
    if (flag){
      y=i;
      break;
    }
  }
  int st[MAXV],top=-1;
  st[++top]=x;
  while (top>-1){
    int i=st[top--];
    for (int j=0;j<mg->n;j++)
      if (mg->edges[i][j]!=INF&&mg->edges[i][j]){
        in[j]--;
        ve[j]=ve[i]+mg->edges[i][j]>ve[j]?ve[i]+mg->edges[i][j]:ve[j];
        if (!in[j])
          st[++top]=j;
      }
  }
  //compute vl,trans the matrix
  for (int j=0;j<mg->n;j++){
    in[j]=0;
    vl[j]=INF;
    for (int i=0;i<mg->n;i++)
      in[j]+=mg->edges[j][i]!=INF&&mg->edges[j][i];;
  }
  top=-1;
  st[++top]=y;
  vl[y]=ve[y];
  while (top>-1){
    int i=st[top--];
    for (int j=0;j<mg->n;j++)
      if (mg->edges[j][i]!=INF&&mg->edges[j][i]){
        in[j]--;
        vl[j]=vl[i]-mg->edges[j][i]<vl[j]?vl[i]-mg->edges[j][i]:vl[j];
        if (!in[j])
          st[++top]=j;
      }
  }
  for (int i=0;i<mg->n;i++)
    for (int j=0;j<mg->n;j++)
      if (mg->edges[i][j]&&mg->edges[i][j]!=INF&&ve[i]==vl[j]-mg->edges[i][j])
        printf("(%d,%d)\n",i,j);
}
int main(void){
  mgraph_t mg;
  init_mg(&mg);
  algraph_t ag;
  m2al(&mg,&ag);
  /****************************/
  /* int visited[MAXV];       */
  /* for (int i=0;i<mg.n;i++) */
  /*   visited[i]=0;          */
  /* BFS(&ag,0,visited);      */
  /****************************/
  /********************************/
  /* int lowcost[MAXV];           */
  /* int closest[MAXV];           */
  /* prim(&mg,0,lowcost,closest); */
  /********************************/
  /*****************/
  /* kruskal(&mg); */
  /*****************/
  /***************************/
  /* int path[MAXV],d[MAXV]; */
  /* dijkstra(&mg,0,d,path); */
  /***************************/
  /***************************************/
  /* int d[MAXV][MAXV],path[MAXV][MAXV]; */
  /* floyd(&mg,d,path);                  */
  /***************************************/
  /*****************/
  /* topsort(&mg); */
  /*****************/
  /******************************************/
  /* int visited[MAXV],in[MAXV],path[MAXV]; */
  /* for (int i=0;i<mg.n;i++){              */
  /*   visited[i]=0;                        */
  /*   in[i]=0;                             */
  /*   for (int j=0;j<mg.n;j++)             */
  /*     in[i]+=mg.edges[j][i];             */
  /* }                                      */
  /* topsort_all(&mg,visited,in,path,0);    */
  /******************************************/
  /*************/
  /* AOE(&mg); */
  /*************/
}
