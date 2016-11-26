#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void radix_sort(char **s,int n){
  char **a1=s,**a2=(char **)malloc(sizeof(char *)*n);
  int *len1=(int *)malloc(sizeof(int)*n),
    *len2=(int *)malloc(sizeof(int)*n),base=-1;
  int count[256],exchanged=0;
  for (int i=0;i<n;i++){
    len1[i]=strlen(s[i]);
    base=base<len1[i]?len1[i]:base;
  }
  for (base=base-1;base>=0;base--){
    for (int i='a';i<='z';i++)
      count[i]=0;
    count[0]=0;
    count[' ']=0;
    for (int i=0;i<n;i++){
      int idx=base>len1[i]-1?0:a1[i][base];
      count[idx]++;
    }
    count[' ']+=count[0];
    count['a']+=count[' '];
    for (int i='b';i<='z';i++)
      count[i]+=count[i-1];
    for (int i=n-1;i>=0;i--){
      int idx=base>len1[i]-1?0:a1[i][base];
      a2[--count[idx]]=a1[i];
      len2[count[idx]]=len1[i];
    }
    char **tmp=a1;
    a1=a2;
    a2=tmp;
    int *tmp_len=len1;
    len1=len2;
    len2=tmp_len;
    exchanged=!exchanged;
  }
  if (exchanged){
    for (int i=0;i<n;i++)
      s[i]=a1[i];
    free(a1);
  }
  else
    free(a2);
}
int main(int argc,char **argv){
  radix_sort(argv+1,argc-1);
  for (int i=0;i<argc-1;i++)
    printf("%s\n",argv[i+1]);
}
