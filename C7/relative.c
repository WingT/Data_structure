#include"union_find.c"
#include<stdio.h>
int main(void){
  int n,m;
  ufs_node ufs[N];
  make_set(ufs);
  scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    union_set(ufs,x,y);
  }
  int q;
  scanf("%d",&q);
  for (int i=0;i<q;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    if (find_set(ufs,x)==find_set(ufs,y))
      printf("Yes\n");
    else
      printf("No\n");
  }
}
