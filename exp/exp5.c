#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAXLINE 1000
#define MAXARG 100
int singletime;
int window=1;
typedef struct person_t{
	int id;
	struct person_t *next;
}person_t;
typedef struct{
	person_t *head,*tail;
	int count;
}queue_t;
queue_t que={NULL,NULL,0}; 
void parse(char *cmd,int *argc,char *argv[]){
	int new_arg=1,count=0,i;
	cmd[strlen(cmd)-1]=0;
	for (i=0;cmd[i];i++)
		if (cmd[i]!=' '){
			if (new_arg){
				new_arg=0;
				argv[count++]=cmd+i;
			}
		}
		else{
			cmd[i]=0;
			new_arg=1;
		}
	*argc=count;
	return;
}
void report(int time){
	int t=time/singletime;
	int ans;
	if (que.count-t*window>=0)
		ans=que.count-t*window;
	else
		ans=0;
	printf("people in que:%d\naverage wait time:%d\nlongest wait time %d\n",ans,(que.count/window+1)*singletime/2,que.count/window*singletime);
	return;
}
void que_insert(int id){
	person_t *person=(person_t *)malloc(sizeof(person_t));
	person->next=NULL;
	person->id=id;
	if (que.count==0)
		que.head=que.tail=person;
	else{
		que.tail->next=person;
		que.tail=person;
	}
	que.count++;
}
void que_ommit(void){
	if (que.head==NULL)
		return;
	if (que.head==que.tail){
		free(que.head);
		que.head=que.tail=NULL;
		que.count--;
		return;
	}
	person_t *p=que.head;
	que.head=p->next;
	que.count--;
	free(p);
	return;
}
void ins(void){
	int n=rand()%10+1;
	for (int i=0;i<n;i++)
		que_insert(que.count);
	return;
}
void howmany(int time){
	int t=time/singletime;
	int new_window=que.count % t?que.count/t+1:que.count/t;
	int ans=new_window>window?new_window-window:0;
	printf("you need to add %d window(s)\n",ans);
	return;
}
void forward(int time){
	int t=time/singletime;
	for (int i=0;i<t;i++)
		for (int j=0;j<window;j++)
			que_ommit();
	return;
}
void add_window(int count){
	window+=count;
}
void eval(char *cmd){
	int argc;
	char *argv[MAXARG];
	parse(cmd,&argc,argv);
	if (!strcmp(argv[0],"r")){
		report(atoi(argv[1]));
		return;
	}
	if (!strcmp(argv[0],"i")){
		ins();
		return;
	}
	if (!strcmp(argv[0],"hmw")){
		howmany(atoi(argv[1]));
		return;
	}
	if (!strcmp(argv[0],"f")){
		forward(atoi(argv[1]));
		return;
	}
	if (!strcmp(argv[0],"a")){
		add_window(atoi(argv[1]));
		return;
	}
	if (!strcmp(argv[0],"s")){
		printf("people in queue:%d\nwindow:%d\n",que.count,window);
	}
}
int main(int argc,char **argv){
	singletime=atoi(argv[1]);
	window=atoi(argv[2]);
	srand((unsigned int)time(NULL));
	while (1){
		printf(">");
		char buf[MAXLINE];
		fgets(buf,MAXLINE,stdin);
		eval(buf);
	}
}
