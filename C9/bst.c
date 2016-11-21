#include<stdio.h>
#include<stdlib.h>
typedef struct node_t{
	int key;
	struct node_t *l,*r;
}node_t;
node_t *new_node(int key){
	node_t *new_node=(node_t *)malloc(sizeof(node_t));
	new_node->key=key;
	new_node->l=NULL;
	new_node->r=NULL;
	return new_node;
}
void bst_print(node_t *t){
	if (t==NULL)
		return;
	printf("%d",t->key);
	if (t->l || t->r){
		printf("(");
		bst_print(t->l);
		if (t->r){
			printf(",");
			bst_print(t->r);
		}
		printf(")");
	}
}
int bst_insert(node_t **t,int key){
	if (*t==NULL){
		*t=new_node(key);
		return 1;
	}
	if ((*t)->key==key)
		return 0;
	if (key<(*t)->key)
		return bst_insert(&((*t)->l),key);
	else
		return bst_insert(&((*t)->r),key);
}
node_t *bst_search(node_t *t,int key){
	if (t==NULL || t->key==key)
		return t;
	if (key<t->key)
		return bst_search(t->l,key);
	else
		return bst_search(t->r,key);
}
int bst_delete(node_t **t,int key){
	if (*t==NULL)
		return 0;
	if (key<(*t)->key)
		return bst_delete(&(*t)->l,key);
	if (key>(*t)->key)
		return bst_delete(&(*t)->r,key);
	if ((*t)->l==NULL){
		node_t *tmp=*t;
		*t=(*t)->r;
		free(tmp);
		return 1;
	}
	if ((*t)->r==NULL){
		node_t *tmp=*t;
		*t=(*t)->l;
		free(tmp);
		return 1;
	}
	node_t **p=&(*t)->l;
	while ((*p)->r)
		p=&(*p)->r;
	node_t *tmp=*p;
	*p=tmp->l;
	tmp->l=(*t)->l;
	tmp->r=(*t)->r;
	free(*t);
	*t=tmp;
	return 1;
}
int main(void){
	int n;
	node_t *t=NULL;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		bst_insert(&t,tmp);
	}
	bst_print(t);
	printf("\n");
	bst_delete(&t,2);
	bst_print(t);
}
