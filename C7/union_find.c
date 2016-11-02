#define N 100
typedef struct{
  int rank;
  int p;
}ufs_node;
void make_set(ufs_node ufs[]){
  for (int i=0;i<N;i++){
    ufs[i].rank=0;
    ufs[i].p=i;
  }
}
int find_set(ufs_node ufs[],int x){
  int p;
  if (x!=ufs[x].p){
    p=find_set(ufs,ufs[x].p);
    ufs[x].p=p;
  }
  return ufs[x].p;
}
void union_set(ufs_node ufs[],int x,int y){
  int px=find_set(ufs,x);
  int py=find_set(ufs,y);
  if (px == py)
    return;
  if (ufs[px].rank > ufs[py].rank)
    ufs[py].p=px;
  else{
    ufs[px].p=py;
    if (ufs[px].rank == ufs[py].rank)
      ufs[py].rank++;
  }
}
