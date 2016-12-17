#include<stdio.h>
#include<stdlib.h>
#define WA 750
#define BLOCK_SIZE 250
int RC=0;
int WC=0;
typedef struct buf{
  int data[BLOCK_SIZE];
  int n;
}buf;
buf rd_buf,wr_buf;
void sync(FILE *fout){
  for (int i=0;i<wr_buf.n;i++)
    fprintf(fout,"%d",wr_buf.data[i]);
}
void write_block(FILE *fout){
  sync(fout);
  WC++;
}
void write_buf(FILE *fout,int x){
  if (wr_buf.n==BLOCK_SIZE)
    write_block(fout);
  wr_buf.data[wr_buf.n++]=x;
}
int read_block(FILE *fin){
  RC++;
  for (int i=0;i<BLOCK_SIZE;i++){
    int tmp;
    int stat=fscanf(fin,"%d",&tmp);
    if (stat==EOF)
      return rd_buf.n;
    rd_buf.data[rd_buf.n++]=tmp;
  }
  return BLOCK_SIZE;
}
int read_buf(FILE *fin,int *x){
  if (rd_buf.n==0){
    read_block(fin);
  }
  if (rd_buf.n==0)
    return EOF;
  *x=rd_buf.data[--rd_buf.n];
  return 1;
}
void min_heapify(int data[],int i,int n){
  int x=data[i-1],j=i;
  while (j<=n/2){
    int minj;
    if (j*2<n)
      minj=data[j*2-1]<=data[j*2]?j*2:j*2+1;
    else
      minj=j*2;
    minj=x<=data[minj-1]?j:minj;
    if (minj!=j){
      data[j-1]=data[minj-1];
      j=minj;
    }
    else
      break;
  }
  data[j-1]=x;
}
void make_min_heap(int data[],int n){
  for (int i=n/2;i>=1;i--)
    min_heapify(data,i,n);
}
void sort(char *file){
  int data[WA],n;
  FILE *fin=fopen(file,"r");
  for (n=0;n<WA;n++){
    int tmp;
    int stat=read_buf(fin,&tmp);
    if (stat==EOF)
      break;
    data[n++]=tmp;
  }
  fclose(fin);
  make_min_heap(data,n);
  int count=n;
  while (1){
    while (n>0){
      write_buf()
    }
  }
}
int main(int argc,char **argv){
}
