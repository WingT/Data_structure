#include<stdio.h>
#include<string.h>
#define MAX 1000
int main(int argc,char **argv){
  char *s=argv[1],*t=argv[2];
  int max=0,maxi,f[2][MAX],s_len=strlen(s),t_len=strlen(t);
  for (int i=0;i<s_len;i++)
    f[1][i]=0;
  for (int i=0;i<t_len;i++){
    f[i%2][0]=t[i]==s[0]?1:0;
    for (int j=1;j<s_len;j++){
      f[i%2][j]=t[i]==s[j]?f[(i-1)%2][j-1]+1:0;
      if (max<f[i%2][j]){
        max=f[i%2][j];
        maxi=i;
      }
    }
  }
  for (int i=maxi-max+1;i<=maxi;i++)
    printf("%c",t[i]);
  printf("\n");
}
