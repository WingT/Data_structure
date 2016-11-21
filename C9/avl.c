#include<stdio.h>
#include<stdlib.h>
typedef struct node_t{
	int key;
	int h;
	struct node_t *l,*r;
}node_t;
node_t *new_node(int key){
	node_t *new_node=(node_t *)malloc(sizeof(node_t));
	new_node->key=key;
	new_node->l=NULL;
	new_node->r=NULL;
	new_node->h=1;
	return new_node;
}
void avl_print(node_t *t){
	if (t==NULL)
		return;
	printf("%d[%d]",t->key,t->h);
	if (t->l || t->r){
		printf("(");
		avl_print(t->l);
		if (t->r){
			printf(",");
			avl_print(t->r);
		}
		printf(")");
	}
}
void avl_right_lift(node_t **t){
	node_t *pt=*t;
	*t=pt->r;
	pt->r=pt->r->l;
	int lh=pt->l?pt->l->h:0;
	int rh=pt->r?pt->r->h:0;
	pt->h=lh>rh?lh+1:rh+1;
	(*t)->l=pt;
	pt=*t;
	lh=pt->l?pt->l->h:0;
	rh=pt->r?pt->r->h:0;
	pt->h=lh>rh?lh+1:rh+1;
}
void avl_left_lift(node_t **t){
	node_t *pt=*t;
	*t=pt->l;
	pt->l=pt->l->r;
	int lh=pt->l?pt->l->h:0;
	int rh=pt->r?pt->r->h:0;
	pt->h=lh>rh?lh+1:rh+1;
	(*t)->r=pt;
	pt=*t;
	lh=pt->l?pt->l->h:0;
	rh=pt->r?pt->r->h:0;
	pt->h=lh>rh?lh+1:rh+1;
}
int avl_insert(node_t **t,int key){
	if (*t==NULL){
		*t=new_node(key);
		return 1;
	}
	node_t *pt=*t;
	if (pt->key==key)
		return 0;
	if (key<pt->key){
		if  (avl_insert(&(pt->l),key)){
			int lh=pt->l?pt->l->h:0;
			int rh=pt->r?pt->r->h:0;
			pt->h=lh>rh?lh+1:rh+1;
			if (lh-rh>=2){
				lh=pt->l->l?pt->l->l->h:0;
				rh=pt->l->r?pt->l->r->h:0;
				if (lh>rh)
					avl_left_lift(t);
				else{
					avl_right_lift(&pt->l);
					avl_left_lift(t);
				}
			}
			return 1;
		}
		return 0;
	}
	else{
		if  (avl_insert(&(pt->r),key)){
			int lh=pt->l?pt->l->h:0;
			int rh=pt->r?pt->r->h:0;
			pt->h=lh>rh?lh+1:rh+1;
			if (rh-lh>=2){
				lh=pt->r->l?pt->r->l->h:0;
				rh=pt->r->r?pt->r->r->h:0;
				if (rh>lh)
					avl_right_lift(t);
				else{
					avl_left_lift(&pt->r);
					avl_right_lift(t);
				}
			}
			return 1;
		}
		return 0;
	}
}
int avl_delete(node_t **t,int key){
	if (*t==NULL)
		return 0;
	node_t *pt=*t;
	if (key<pt->key){
		if (avl_delete(&pt->l,key)){
			int lh=pt->l?pt->l->h:0;
			int rh=pt->r?pt->r->h:0;
			pt->h=lh>rh?lh+1:rh+1;
			if (rh-lh>=2){
				lh=pt->r->l?pt->r->l->h:0;
				rh=pt->r->r?pt->r->r->h:0;
				if (rh>lh)
					avl_right_lift(t);
				else{
					avl_left_lift(&pt->r);
					avl_right_lift(t);
				}
			}
			return 1;
		}
		return 0;
	}
	if (pt->key<key){
		if (avl_delete(&pt->r,key)){
			int lh=pt->l?pt->l->h:0;
			int rh=pt->r?pt->r->h:0;
			pt->h=lh>rh?lh+1:rh+1;
			if (lh-rh>=2){
				lh=pt->l->l?pt->l->l->h:0;
				rh=pt->l->r?pt->l->r->h:0;
				if (lh>rh)
					avl_left_lift(t);
				else{
					avl_right_lift(&pt->r);
					avl_left_lift(t);
				}
			}
			return 1;
		}
		return 0;
	}
	if (pt->l==NULL){
		*t=pt->r;
		free(pt);
		return 1;
	}
	if (pt->r==NULL){
		*t=pt->l;
		free(pt);
		return 1;
	}
	node_t *pre=pt->l;
	while (pre->r)
		pre=pre->r;
	pt->key=pre->key;
	avl_delete(&pt->l,pt->key);
	int lh=pt->l?pt->l->h:0;
	int rh=pt->r?pt->r->h:0;
	pt->h=lh>rh?lh+1:rh+1;
	if (rh-lh>=2){
		lh=pt->r->l?pt->r->l->h:0;
		rh=pt->r->r?pt->r->r->h:0;
		if (rh>lh)
			avl_right_lift(t);
		else{
			avl_left_lift(&pt->r);
			avl_right_lift(t);
		}
	}
	return 1;
}
node_t *avl_search(node_t *t,int key){
	if (t==NULL || t->key==key)
		return t;
	if (key<t->key)
		return avl_search(t->l,key);
	else
		return avl_search(t->r,key);
}
int main(int argc,char **argv){
	node_t *t=NULL;
	for (int i=1;i<argc;i++){
		int tmp=atoi(argv[i]);
		avl_insert(&t,tmp);
	}
	avl_delete(&t,7);
	avl_print(t);
	printf("\n");
	system("pause");
}
