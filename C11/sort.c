#include<stdio.h>
#define WA 750
#define BLOCK_SIZE 250
int RC=0;
int WC=0;
int read_buf(FILE *fin,int buf[],int size){
  int n=0;
  for (int i=0;i<size;i+=BLOCK_SIZE){
    for (int j=0;j<BLOCK_SIZE && n<size;j++){
      int tmp;
      if (fscanf(fin,"%d",&tmp)!=EOF){
        buf[i+j]=tmp;
        n++;
      }
      else
        break;
    }
  }
  return n;
}
int main(int argc,char **argv){

}
