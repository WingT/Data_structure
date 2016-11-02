#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int weight;
  int p,l,r;
}ht_node;
void create_ht(ht_node *ht,int n){
  for (int i=n;i<2*n-1;i++){
    int min1,min2,min1k,min2k;
    min1=min2=(1<<31)-1;
    for (int j=0;j<i;j++){
      if (ht[j].p==-1){
        if (ht[j].weight<min1){
          min2=min1;
          min2k=min1k;
          min1=ht[j].weight;
          min1k=j;
        }
        else
          if (ht[j].weight<min2){
            min2=ht[j].weight;
            min2k=j;
          }
      }
    }
    ht[min1k].p=i;
    ht[min2k].p=i;
    ht[i].weight=ht[min1k].weight+ht[min2k].weight;
    ht[i].l=min1k;
    ht[i].r=min2k;
  }
}
int main(int argc,char **argv){
  int n=argc-1;
  ht_node *ht=(ht_node *)malloc(sizeof(ht_node)*(2*n-1));
  for (int i=0;i<n;i++)
    ht[i].weight=atoi(argv[i+1]);
  for (int i=0;i<2*n-1;i++){
    ht[i].p=-1;
    ht[i].l=-1;
    ht[i].r=-1;
  }
  create_ht(ht,n);
}
