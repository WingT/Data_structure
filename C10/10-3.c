//quickly select the k'th least element from the list
//n+n/2+n/4+n/8+...=O(n)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
int select_k(int data[],int k,int n){
  int l=0,r=n-1;
  while (l<=r){
    int rand_k=rand()%(r-l+1)+l,x=data[l],i=l,j=r;
    data[l]=data[rand_k];
    data[rand_k]=x;
    x=data[l];
    while (i<j){
      while (i<j && data[j]>=x)
        j--;
      data[i]=data[j];
      while (i<j && data[i]<=x)
        i++;
      data[j]=data[i];
    }
    data[i]=x;
    if (l+k-1==i)
      return data[i];
    if (l+k-1<i)
      r=i-1;
    else{
      k-=i-l+1;
      l=i+1;
    }
  }
  if (k<1)
    return data[l];
  else
    return data[r];
}
int main(int argc,char **argv){
  int data[MAX];
  for (int i=0;i<argc-2;i++)
    data[i]=atoi(argv[2+i]);
  time_t t=time(NULL);
  srand((unsigned)t);
  printf("%d\n",select_k(data,atoi(argv[1]),argc-2));
}
