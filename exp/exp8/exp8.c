#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXQLEN 1000
#define MAXALEN 1000
#define MAXLINE 1000
#define MAXARG 10
typedef struct prob_t{
  char q[MAXQLEN];
  char a[MAXALEN];
  struct prob_t*next;
  int stat,score;
}prob_t;
typedef struct level_t{
  int level;
  prob_t *head,*tail;
  prob_t *now;
  int rn,wn,n,score;
  struct level_t *p,*l,*r;
}level_t;
level_t *paper=NULL;
char filename[MAXLINE];
prob_t *new_prob(void){
  prob_t *p=(prob_t *)malloc(sizeof(prob_t));
  p->q[0]=0;
  p->a[0]=0;
  p->next=NULL;
  p->stat=-1;
  p->score=0;
  return p;
}
level_t *new_level(void){
  level_t *p=(level_t *)malloc(sizeof(level_t));
  p->level=0;
  p->head=p->tail=p->now=NULL;
  p->rn=p->wn=p->n=p->score=0;
  p->p=p->l=p->r=NULL;
  return p;
}
level_t *find_level(int l){
  level_t *p=paper;
  while (p && p->level!=l){
    if (l<p->level)
      p=p->l;
    else
      p=p->r;
  }
  return p;
}
void insert_level(level_t *nl){
  level_t *p=paper,*pre=NULL;
  while (p && p->level!=nl->level){
    pre=p;
    if (nl->level<p->level)
      p=p->l;
    else
      p=p->r;
  }
  if (pre){
    if (nl->level<pre->level)
      pre->l=nl;
    else
      pre->r=nl;
    nl->p=pre;
  }
  else
    paper=nl;
}
void insert_p(level_t *l,prob_t *np){
  if (l->tail){
    l->tail->next=np;
    l->tail=np;
    if (l->now==NULL)
      l->now=np;
  }
  else
    l->head=l->tail=l->now=np;
  l->n++;
}
void load(char *filein){
  FILE *fin=fopen(filein,"r");
  strcpy(filename,filein);
  if (fin==NULL){
    printf("No such file or directory!\n");
    return;
  }
  char buf[MAXALEN];
  level_t *newl=NULL;
  prob_t *newp=NULL;
  while (fgets(buf,MAXALEN,fin)!=NULL){
    switch(buf[0]){
    case'{':newp=new_prob();break;
    case'l':{
      int l=atoi(buf+2);
      newl=find_level(l);
      if (!newl){
        newl=new_level();
        newl->level=l;
        insert_level(newl);
      }
      else
        newl->level=l;
      insert_p(newl,newp);
      break;
    }
    case'q':strcpy(newp->q,buf+2);break;
    case'a':strcpy(newp->a,buf+2);break;
    case's':newp->score=atoi(buf+2);
    case'}':break;
    default:break;
    }
  }
  fclose(fin);
  printf("load paper successfully!\n");
}
level_t *predecessor(level_t *l){
  if (l->l){
    level_t *tmp=l->l;
    while (tmp->r)
      tmp=tmp->r;
    return tmp;
  }
  else{
    level_t *tmp=l;
    while (tmp->p && tmp->p->r!=tmp)
      tmp=tmp->p;
    tmp=tmp->p;
    return tmp;
  }
}
level_t *easier(level_t *l){
  level_t *p=l;
  p=predecessor(l);
  while (p!=NULL && p->now==NULL)
    p=predecessor(p);
  if (p)
    return p;
  else
    if (l->now==NULL)
      return NULL;
    else
      return l;
}
level_t *successor(level_t *l){
  if (l->r){
    level_t *tmp=l->r;
    while (tmp->l)
      tmp=tmp->l;
    return tmp;
  }
  else{
    level_t *tmp=l;
    while (tmp->p && tmp->p->l!=tmp)
      tmp=tmp->p;
    tmp=tmp->p;
    return tmp;
  }
}
level_t *moredifficult(level_t *l){
  level_t *p=l;
  p=successor(l);
  while (p!=NULL && p->now==NULL)
    p=successor(p);
  if (p)
    return p;
  else
    if (l->now==NULL)
      return NULL;
    else
      return l;
}
void summarize(void){
  char fileout[MAXLINE];
  strcpy(fileout,filename);
  strcat(fileout,".sum.txt");
  FILE *fout=fopen(fileout,"w");
  int n=0,wn=0,rn=0,score=0;
  level_t *pl=paper,*pre;
  while ((pre=predecessor(pl))!=NULL)
    pl=pre;
  while (pl){
    fprintf(fout,"level:%d,wn:%d,rn:%d,total:%d,score:%d\n",pl->level,pl->wn,pl->rn,pl->n,pl->score);
    n+=pl->n;
    wn+=pl->wn;
    rn+=pl->rn;
    score+=pl->score;
    pl=successor(pl);
  }
  fprintf(fout,"total:wn:%d,rn:%d,total:%d,total score:%d\n",wn,rn,n,score);
  fclose(fout);
  printf("the result has been stored in %s!\n",fileout);
  return;
}
void test(void){
  level_t *level_now=paper,*pre=NULL,*suc=NULL;
  char ans[MAXALEN];
  printf("type :q to exit!\n");
  while (level_now){
    printf("Q:\n%s\nyour ans:",level_now->now->q);
    fgets(ans,MAXALEN,stdin);
    if (!strcmp(ans,":q\n")){
      summarize();
      return;
    }
    if (strcmp(ans,level_now->now->a)){
      level_now->wn++;
      level_now->now->stat=0;
      level_now->now=level_now->now->next;
      printf("WA!");
      pre=easier(level_now);
      if (pre){
        printf("starting from an easier one...\n");
        level_now=pre;
      }
      else{
        suc=moredifficult(level_now);
        if (suc){
          printf("no more easier one!starting from a more difficult one...\n");
          level_now=suc;
        }
        else{
          printf("no more problems!\n");
          summarize();
          return;
        }
      }
    }
    else{
      level_now->rn++;
      level_now->now->stat=1;
      level_now->score+=level_now->now->score;
      level_now->now=level_now->now->next;
      printf("AC!");
      suc=moredifficult(level_now);
      if (suc){
        printf("starting from a more difficult one...\n");
        level_now=suc;
      }
      else{
        pre=easier(level_now);
        if (pre){
          printf("no more more difficult one!starting from an easier one...\n");
          level_now=pre;
        }
        else{
          printf("no more problems!\n");
          summarize();
          return;
        }
      }
    }
  }
}
void delete_level(level_t **pl){
  level_t *pt=*pl;
  if (pt==NULL)
    return;
  delete_level(&(pt->l));
  delete_level(&(pt->r));
  prob_t *pre,*p=pt->head;
  while (p){
    pre=p;
    p=p->next;
    free(pre);
  }
  free(pt);
  *pl=NULL;
}
void reload(void){
  delete_level(&paper);
}
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
void eval(char *cmd){
  int argc;
  char *argv[MAXARG];
  parse(cmd,&argc,argv);
  if (argc==0){
    printf("load file --load test paper\nreload --reinit\nstart --start test\nq --quit\n");
    return;
  }
  if (!strcmp(argv[0],"load")){
    if (argc!=2){
      printf("load filename\n");
    }
    else
      load(argv[1]);
    return;
  }
  if (!strcmp(argv[0],"start")){
    test();
    return;
  }
  if (!strcmp(argv[0],"reload")){
    reload();
    return;
  }
  if (!strcmp(argv[0],"q")){
    exit(0);
  }
  printf("load file --load test paper\nreload --reinit\nstart --start test\nq --quit\n");
}
int main(void){
  while (1){
    printf(">");
    char buf[MAXLINE];
    fgets(buf,MAXLINE,stdin);
    eval(buf);
  }
}
