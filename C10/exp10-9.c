#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char s[]="whileifif-elsedo-whileforcase";
struct node{
  int start;
  int length;
}a[]={{0,5},{5,2},{7,7},{14,8},{22,3},{25,4}};
int a_le(struct node a,struct node b,char s[]){
  int i=a.start,j=b.start;
  while (i<a.start+a.length && j<b.start+b.length){
    if (s[i]>s[j])
      return 0;
    if (s[i]<s[j])
      return 1;
    i++;
    j++;
  }
  if (a.length<=b.length)
    return 1;
  else
    return 0;
}
void quick_sort(struct node a[],char s[],int l,int r){
  if (l>r)
    return;
  int i=l,j=r;
  int k=rand()%(r-l+1)+l;
  struct node tmp=a[l];
  a[l]=a[k];
  a[k]=tmp;
  struct node x=a[l];
  while (i<j){
    while (i<j && a_le(x,a[j],s))
      j--;
    a[i]=a[j];
    while (i<j && a_le(a[i],x,s))
      i++;
    a[j]=a[i];
  }
  a[i]=x;
  quick_sort(a,s,l,i-1);
  quick_sort(a,s,i+1,r);
}
int main(void){
  time_t t=time(NULL);
  srand(t);
  quick_sort(a,s,0,5);
  for (int i=0;i<6;i++){
    for (int j=0;j<a[i].length;j++)
      printf("%c",s[a[i].start+j]);
    printf("\n");
  }
}
