#include<stdio.h>
#include<stdlib.h>
#define MAXM 10
typedef struct node_t{
	int n;
	int key[MAXM];
	struct node_t *c[MAXM],*p;
}node_t;
typedef struct result{
	int flag,i;
	node_t *p;
}result;
int m=5;
int min=2,max=4;
int search_in_node(node_t *t,int key){
	int i;
	for (i=0;i<t->n && key>=t->key[i+1];i++);
	return i;
}
result bm_search(node_t *t,int key){
	node_t *p=t,*pre;
	result r;
	if (t==NULL){
		r.flag=0;
		r.i=0;
		r.p=NULL;
	}
	int i;
	while (p){
		i=search_in_node(t,key);
		if (i>0 && t->key[i]==key){
			r.flag=1;
			r.i=i;
			r.p=p;
			return r;
		}
		pre=p;
		p=p->c[i];
	}
	r.flag=0;
	r.i=i;
	r.p=pre;
	return r;
}
node_t *new_node(){
	node_t *p=(node_t *)malloc(sizeof(node_t));
	p->n=0;
	p->p=NULL;
	for (int i=0;i<MAXM;i++)
		p->c[i]=NULL;
	return p;
}
int bm_insert(node_t **t,int key){
	node_t *pt=*t;
	if (pt==NULL){
		pt=new_node();
		pt->n=1;
		pt->key[1]=key;
		*t=pt;
		return 1;
	}
	result r=bm_search(pt,key);
	if (r.flag)
		return 0;
	pt=r.p;
	int tmp_key[MAXM];
    node_t *tmp_c[MAXM+1];
	node_t *newc=NULL;
	while (1){
		int k=search_in_node(pt,key);
		if (pt->n==max){
			for (int i=1;i<=k;i++)
				tmp_key[i-1]=pt->key[i];
			tmp_key[k]=key;
			for (int i=k+1;i<=max;i++)
				tmp_key[i]=pt->key[i];
			for (int i=0;i<=k;i++)
				tmp_c[i]=pt->c[i];
			tmp_c[k+1]=newc;
			for (int i=k+1;i<=max;i++)
				tmp_c[i+1]=pt->c[i];
			pt->n=min;
			for (int i=1;i<=min;i++){
				pt->key[i]=tmp_key[i-1];
				pt->c[i-1]=tmp_c[i-1];
			}
			pt->c[min]=tmp_c[min];
			newc=new_node();
			newc->n=m-min-1;
			for (int i=1;i<=newc->n;i++){
				newc->key[i]=tmp_key[min+i];
				newc->c[i-1]=tmp_c[min+i];
				if (tmp_c[min+i]!=NULL)
					tmp_c[min+i]->p=newc;
			}
			newc->c[newc->n]=tmp_c[m];
			if (tmp_c[m]!=NULL)
				tmp_c[m]->p=newc;
			key=tmp_key[min];
			if (pt->p==NULL){
				node_t *tmp=new_node();
				pt->p=tmp;
				tmp->c[0]=pt;
				*t=tmp;
			}
		}
		else{
			for (int i=pt->n;i>k;i--){
				pt->key[i+1]=pt->key[i];
				pt->c[i+1]=pt->c[i];
			}
			pt->key[k+1]=key;
			pt->c[k+1]=newc;
			pt->n++;
			if (newc!=NULL)
				newc->p=pt;
			break;
		}
		pt=pt->p;
	}
	return 1;
}
int bm_delete(node_t **t,int key){
	node_t *pt=*t;
	result r=bm_search(pt,key);
	if (r.flag==0)
		return 0;
	pt=r.p;
	if (pt->c[r.i]!=NULL){
		node_t **succ=&pt->c[r.i];
		while ((*succ)->c[0])
			succ=&(*succ)->c[0];
		pt->key[r.i]=(*succ)->key[0];
		bm_delete(succ,pt->key[r.i]);
		return 1;
	}
	node_t *p=pt->p;
	if (p==NULL){
		if (p->n==1){
			free(pt);
			*t=NULL;
			return 1;
		}
		for (int i=r.i;i<pt->n;i++)
			pt->key[i]=pt->key[i+1];
		pt->n--;
		return 1;
	}
	if (pt->n>min){
		for (int i=r.i;i<pt->n;i++)
			pt->key[i]=pt->key[i+1];
		pt->n--;
		return 1;
	}
	int k=search_in_node(p,key);
	node_t *lb=k>0?p->c[k-1]:NULL;
	node_t *rb=k<p->n?p->c[k+1]:NULL;
	if (lb!=NULL && lb->n > min){
		for (int i=r.i;i>0;i--)
			pt->key[i]=pt->key[i-1];
		pt->key[0]=p->key[k];
		p->key[k]=lb->key[lb->n];
		lb->n--;
		return 1;
	}
	if (rb!=NULL && rb->n > min){
		for (int i=r.i;i<pt->n;i++)
			pt->key[i]=pt->key[i+1];
		pt->key[pt->n]=p->key[k+1];
		p->key[k+1]=rb->key[0];
		for (int i=1;i<=rb->n;i++)
			rb->key[i-1]=rb->key[i];
		rb->n--;
		return 1;
	}
	for (int i=r.i;i<pt->n;i++)
		pt->key[i]=pt->key[i+1];
	pt->n--;
	while (1){
		if (pt->n>=min)
			break;
		if (p==NULL){
			if (pt->n==0){
				*t=pt->c[0];
				pt->c[0]->p=NULL;
				free(pt);
			}
			break;
		}
		k=search_in_node(p,pt->key[0]);
		lb=k>0?p->c[k-1]:NULL;
		rb=k<p->n?p->c[k+1]:NULL;
		if (lb!=NULL){
			lb->key[lb->n+1]=p->key[k];
			for (int i=1;i<=pt->n;i++)
				lb->key[lb->n+i+1]=pt->key[i];
			for (int i=0;i<=pt->n;i++){
				lb->c[lb->n+1+i]=pt->c[i];
				if (pt->c[i])
					pt->c[i]->p=lb;
			}
			lb->n+=pt->n+1;
			free(pt);
			for (int i=k;i<p->n;i++){
				p->key[i]=p->key[i+1];
				p->c[i]=p->c[i+1];
			}
			p->n--;
		}
		else{
			pt->key[pt->n+1]=p->key[k+1];
			for (int i=1;i<=rb->n;i++)
				pt->key[pt->n+i+1]=rb->key[i];
			for (int i=0;i<=rb->n;i++){
				pt->c[pt->n+1+i]=rb->c[i];
				if (rb->c[i])
					rb->c[i]->p=pt;
			}
			pt->n+=rb->n+1;
			free(rb);
			for (int i=k+1;i<p->n;i++){
				p->key[i]=p->key[i+1];
				p->c[i]=p->c[i+1];
			}
			p->n--;
		}
		pt=p;
		p=p->p;
	}
	return 1;
}
void bm_print(node_t *t){
	if (t==NULL)
		return;
	printf("[");
	for (int i=1;i<t->n;i++)
		printf("%d,",t->key[i]);
	printf("%d]",t->key[t->n]);
	printf("{");
	for (int i=0;i<t->n;i++){
		printf("%d",i);
		bm_print(t->c[i]);
		printf(",");
	}
	printf("%d",t->n);
	bm_print(t->c[t->n]);
	printf("}");
}
int main(int argc,char **argv){
	node_t *t=NULL;
	for (int i=1;i<argc;i++){
		int tmp=atoi(argv[i]);
		bm_insert(&t,tmp);
		bm_print(t);
		printf("\n");
	}
}
