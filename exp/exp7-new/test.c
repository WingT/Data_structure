#include<stdio.h>
int main(void){
  FILE *fin=fopen("test.input","r");
  int count=0;
  char c;
  while (fscanf(fin,"%c",&c)!=EOF){
    count++;
  }
  printf("%d\n",count);
  fclose(fin);
}
