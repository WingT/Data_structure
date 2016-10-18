#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 1000
#define MAXTITLE 40
#define MAXARG 4
char *file_in,*file_out;
char *help_msg="1:find-ISBN ISBN查找ISBN号\n2:find-title title查找书名\n3:ins插入\n4:modify ISBN修改\n5:sort排序\n6:count计数\n7:disp显示书目\n8:exit\n9:help\n";
typedef struct book_t{
  char ISBN[14];
  char title[MAXTITLE];
  int price;
  struct book_t*next;
}book_t;
typedef struct lib_t{
  book_t *head,*tail;
}lib_t;
lib_t lib={NULL,NULL};
book_t *new_book_entry(){
  book_t *new_book=(book_t *)malloc(sizeof(book_t));
  if (new_book){
    new_book->ISBN[0]=0;
    new_book->title[0]=0;
    new_book->price=-1;
    new_book->next=NULL;
  }
  else printf("no enough memory!\n");
  return new_book;
}
void init_lib(FILE *fin,lib_t *lib){
  char buf[MAXLINE];
  book_t *new_book;
  while (fgets(buf,MAXLINE,fin)){
    if (buf[0]=='{'){
      new_book=new_book_entry();
      continue;
    }
    if (buf[0]=='}'){
      if (!lib->head)
        lib->head=lib->tail=new_book;
      else{
        lib->tail->next=new_book;
        lib->tail=new_book;
      }
      continue;
    }
    char *delim=strchr(buf,':');
    char *property=buf,*value=delim+1;
    *delim=0;
    value[strlen(value)-1]=0;
    if (!strcmp(property,"ISBN")){
      strcpy(new_book->ISBN,value);
      continue;
    }
    if (!strcmp(property,"title")){
      strcpy(new_book->title,value);
      continue;
    }
    if (!strcmp(property,"price"))
      new_book->price=atoi(value);
  }
}
void print_book(book_t *book);
void store_lib(lib_t *lib){
  book_t *p=lib->head;
  FILE *fout=fopen(file_out,"w");
  if (!fout){
    printf("error\n");
    return ;
  }
  while (p){
    fprintf(fout,"{\n");
    fprintf(fout,"ISBN:%s\n",p->ISBN);
    fprintf(fout,"title:%s\n",p->title);
    fprintf(fout,"price:%d\n",p->price);
    fprintf(fout,"}\n");
    p=p->next;
  }
  fclose(fout);
}
void parse_cmd(char cmd[],int *argc,char *argv[]){
  int new_arg=1,count=0,i,len=strlen(cmd);
  cmd[len-1]=0;
  for (i=0;i<len;i++){
    if (cmd[i]==' '){
      cmd[i]=0;
      new_arg=1;
    }
    else{
      if (new_arg){
        argv[count++]=cmd+i;
        new_arg=0;
      }
    }
  }
  *argc=count;
}
void print_book(book_t *book){
  printf("{\n");
  printf("ISBN:%s\n",book->ISBN);
  printf("title:%s\n",book->title);
  printf("price:%d\n",book->price);
  printf("}\n");
}
void print_lib(lib_t lib){
  book_t *p=lib.head;
  int i=0;
  while (p){
    i++;
    printf("book %d:\n",i);
    print_book(p);
    p=p->next;
  }
}
book_t *find_by_ISBN(lib_t *lib,char *ISBN,int *index){
  book_t *p=lib->head;
  int i=0;
  while (p && strcmp(ISBN,p->ISBN)){
    p=p->next;
    i++;
  }
  *index=p?i+1:0;
  return p;
}
book_t *find_by_title(lib_t *lib,char *title,int *index){
  book_t *p=lib->head;
  int i=0;
  while (p && strcmp(title,p->title)){
    p=p->next;
    i++;
  }
  *index=p?i+1:0;
  return p;
}
book_t *find_by_index(lib_t *lib,int index){
  book_t *p=lib->head;
  int i=1;
  if (index<=0)
    return NULL;
  while (p && i<index){
    p=p->next;
    i++;
  }
  return p;
}
void swap(book_t *a,book_t *b){
  char buf[MAXTITLE];
  int tmp;
  strcpy(buf,a->ISBN);
  strcpy(a->ISBN,b->ISBN);
  strcpy(b->ISBN,buf);
  strcpy(buf,a->title);
  strcpy(a->title,b->title);
  strcpy(b->title,buf);
  tmp=a->price;
  a->price=b->price;
  b->price=tmp;
}
void quick_sort(book_t *lp,book_t *rp){
  book_t *ip,*jp=NULL,*pre;
  if (lp==rp)
    return;
  for (ip=lp;ip!=rp;ip=ip->next)
    if (ip->price < rp->price){
      jp=jp?jp->next:lp;
      swap(jp,ip);
    }
  pre=jp;
  jp=jp?jp->next:lp;
  swap(jp,rp);
  if (jp!=lp)
    quick_sort(lp,pre);
  if (jp!=rp)
    quick_sort(jp->next,rp);
}
void disp_help_msg(){
  printf("%s",help_msg);
}
void eval(char *cmd){
  int argc;
  char *argv[MAXARG];
  parse_cmd(cmd,&argc,argv);
  if (argc==0)
    return;
  if (!strcmp(argv[0],"find-ISBN")){
    if (argc != 2){
      printf("usage:find-ISBN ISBN-number\n");
      return;
    }
    int index;
    book_t *book=find_by_ISBN(&lib,argv[1],&index);
    if (book){
      printf("book %d:\n",index);
      print_book(book);
    }
    else
      printf("no such book!\n");
    return;
  }
  if (!strcmp(argv[0],"find-title")){
    if (argc == 1){
      printf("usage:find-title title\n");
      return;
    }
    char title[MAXTITLE];
    int len=strlen(argv[1]);
    title[0]=0;
    strcpy(title,argv[1]);
    for (int i=2;i<argc;i++){
      title[len]=' ';
      title[len+1]=0;
      strcat(title,argv[i]);
      len+=strlen(argv[i])+1;
    }
    int index;
    book_t *book=find_by_title(&lib,title,&index);
    if (book){
      printf("book %d:\n",index);
      print_book(book);
    }
    else
      printf("no such book!\n");
    return;
  }
  if (!strcmp(argv[0],"ins")){
    book_t *new_book=new_book_entry();
    printf("ISBN:");
    fgets(new_book->ISBN,14,stdin);
    printf("title:");
    fgetc(stdin);
    fgets(new_book->title,MAXTITLE,stdin);
    new_book->title[strlen(new_book->title)-1]=0;
    printf("price:");
    scanf("%d",&new_book->price);
    int index;
    book_t *old_book=find_by_ISBN(&lib,new_book->ISBN,&index);
    if (old_book){
      printf("book with the same ISBN exists:\n");
      print_book(old_book);
      printf("replace it?N/y:");
      fgetc(stdin);
      char op=fgetc(stdin);
      if (op=='y'){
        strcpy(old_book->title,new_book->title);
        old_book->price=new_book->price;
        store_lib(&lib);
        printf("book %d updated!\n",index);\
        fgetc(stdin);
        free(new_book);
        return;
      }
      printf("change discarded!\n");
    }
    else{
      new_book->next=lib.head;
      lib.head=new_book;
      if (!lib.tail)
        lib.tail=new_book;
      store_lib(&lib);
      printf("book added!\n");
    }
  }
  if (!strcmp(argv[0],"disp")){
      print_lib(lib);
      return;
  }
  if (!strcmp(argv[0],"del")){
    if (argc!=2){
      printf("usage:del index\n");
      return;
    }
    int index=atoi(argv[1]);
    book_t *book=find_by_index(&lib,index);
    if (!book){
      printf("book %d doesn't exist!\n",index);
      return;
    }
    book_t *pre=find_by_index(&lib,index-1);
    if (book==lib.head){
      lib.head=book->next;
      if (book==lib.tail)
        lib.tail=NULL;
      free(book);
    }
    else{
      pre->next=book->next;
      if (book==lib.tail)
        lib.tail=pre;
      free(book);
    }
    store_lib(&lib);
    printf("done!\n");
    return;
  }
  if (!strcmp(argv[0],"modify")){
    if (argc!=2){
      printf("usage:modify ISBN\n");
      return;
    }
    int index;
    book_t *book=find_by_ISBN(&lib,argv[1],&index);
    if (!book){
      printf("book with ISBN=%s doesn't exit!\n",argv[1]);
      return;
    }
    printf("title:");
    fgets(book->title,MAXTITLE,stdin);
    book->title[strlen(book->title)-1]=0;
    printf("price:");
    scanf("%d",&book->price);
    store_lib(&lib);
    printf("book updated!\n");
  }
  if (!strcmp(argv[0],"sort")){
    quick_sort(lib.head,lib.tail);
    store_lib(&lib);
    printf("done!\n");
    return;
  }
  if (!strcmp(argv[0],"count")){
    int count=0;
    book_t *p=lib.head;
    while (p){
      count++;
      p=p->next;
    }
    printf("total number:%d\n",count);
    return;
  }
  if (!strcmp(argv[0],"exit"))
    exit(0);
  if (!strcmp(argv[0],"help")){
    disp_help_msg();
    return;
  }
  printf("command not found!\n");
  disp_help_msg();
}
int main(int argc,char **argv){
  if (argc!=2){
    printf("usage:%s data\n",argv[0]);
    return 0;
  }
  else{
    FILE *fin=fopen(argv[1],"r");
    file_in=argv[1];
    file_out=argv[1];
    if (!fin){
      printf("%s:no such file or directory!\n",argv[1]);
      return 0;
    }
    init_lib(fin,&lib);
    fclose(fin);
    char cmd[MAXLINE];
    while (1){
      printf(">");
      if (fgets(cmd,MAXLINE,stdin))
        eval(cmd);
      else break;
    }
  }
}
