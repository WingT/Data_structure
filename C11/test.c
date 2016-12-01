#include<stdio.h>
int main(int argc,char **argv){
  int n=0;
  FILE *fin=fopen(argv[1],"r");
  for (int i=0;i<10;i++){
    int tmp;
    int stat=fscanf(fin,"%d",&tmp);
    if (stat==EOF)
      break;
    else
      n++;
  }
  fclose(fin);
  printf("%d",n);
}
