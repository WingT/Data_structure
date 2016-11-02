#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct{
  char data;
  double weight;
  int p,l,r;
}ht_node;
typedef struct{
  char ch;
  char cd[N];
  int start;
}hcode;
void create_ht(ht_node *ht,int n){
  for (int i=n;i<2*n-1;i++){
    double min1,min2;
    int min1k,min2k;
    min1=min2=(double)((1<<31)-1);
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
void create_hcode(ht_node *ht,int n,hcode *hcd){
  for (int i=0;i<n;i++){
    int hp=i;
    while (hp!=2*n-2){
      if (ht[ht[hp].p].l==hp)
        hcd[i].cd[--hcd[i].start]='0';
      else
        hcd[i].cd[--hcd[i].start]='1';
      hp=ht[hp].p;
    }
  }
}
int main(int argc,char **argv){
  int n=(argc-1)/2;
  ht_node *ht=(ht_node *)malloc(sizeof(ht_node)*(2*n-1));
  for (int i=0;i<n;i++){
    ht[i].data=argv[2*i+1][0];
    ht[i].weight=atof(argv[2*i+2]);
  }
  for (int i=0;i<2*n-1;i++){
    ht[i].p=-1;
    ht[i].l=-1;
    ht[i].r=-1;
  }
  create_ht(ht,n);
  hcode *hcd=(hcode *)malloc(sizeof(hcode)*n);
  for (int i=0;i<n;i++){
    hcd[i].ch=argv[2*i+1][0];
    hcd[i].cd[N-1]=0;
    hcd[i].start=N-1;
  }
  create_hcode(ht,n,hcd);
  for (int i=0;i<n;i++)
    printf("%c:%s\n",hcd[i].ch,hcd[i].cd+hcd[i].start);
}
