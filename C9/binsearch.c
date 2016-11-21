#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000
int binsearch(int data[],int key,int n){
	int l=0,r=n-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (data[mid]==key)
			return mid;
		if (key<data[mid])
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}
int main(void){
	int data[MAXN],key,n;
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	scanf("%d",&key);
	printf("%d",binsearch(data,key,n));
	system("pause");
}
