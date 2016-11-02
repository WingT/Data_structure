#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000
char *helpmsg="q:exit\nh:help\nexp:eval\n";
int pri(char c){
  switch (c){
  case '+':return 1;
  case '-':return 1;
  case '*':return 2;
  case '/':return 2;
  case '(':return 0;
  }
}
void infix2suffix(char *infix,char *suffix){
  char s1[MAXLINE];
  int t1=-1,t2=-1;
  int i=0;
  while (infix[i]){
    if (infix[i]>='0' && infix[i]<='9'){
      while (infix[i] && infix[i]>='0' && infix[i]<='9')
        suffix[++t2]=infix[i++];
      suffix[++t2]='#';
    }
    else{
      switch (infix[i]){
      case '(':s1[++t1]='(';break;
      case ')':{
        while (s1[t1]!='(')
          suffix[++t2]=s1[t1--];
        t1--;
      }break;
      default:{
        if (t1>=0 && pri(infix[i])<=pri(s1[t1]))
          suffix[++t2]=s1[t1--];
        s1[++t1]=infix[i];
      }
      }
      i++;
    }
  }
  while (t1>=0)
    suffix[++t2]=s1[t1--];
  suffix[++t2]=0;
}
int eval_suffix(char suffix[]){
  int i=0;
  int st[MAXLINE],top=-1;
  while (suffix[i]){
    if (suffix[i]>='0'&&suffix[i]<='9'){
      int tmp=0;
      while (suffix[i] && suffix[i]>='0'&&suffix[i]<='9')
        tmp=tmp*10+suffix[i++]-'0';
      st[++top]=tmp;
    }
    else{
      int n2=st[top--];
      int n1=st[top--];
      switch (suffix[i]){
      case '+':st[++top]=n1+n2;break;
      case '-':st[++top]=n1-n2;break;
      case '*':st[++top]=n1*n2;break;
      case '/':st[++top]=n1/n2;break;
    }
    }
    i++;
  }
  return st[0];
}
void eval(char buf[]){
  if (buf[0]==0 || !strcmp(buf,"h")){
    printf("%s",helpmsg);
    return;
  }
  if (!strcmp(buf,"q"))
    exit(0);
  else {
    char suffix_exp[MAXLINE];
    infix2suffix(buf,suffix_exp);
    printf("the sffix exp is:\n%s\n",suffix_exp);
    printf("the answer is:%d\n",eval_suffix(suffix_exp));
  }
}
void reg(char buf[]){
  buf[strlen(buf)-1]=0;
  int jmp=0,i;
  for (i=0;buf[i];i++)
    if (buf[i]==' ' || buf[i]=='\t')
      jmp++;
    else
      buf[i-jmp]=buf[i];
  buf[i-jmp]=0;
}
int main(void){
  char buf[MAXLINE];
  while (1){
    printf(">");
    fgets(buf,MAXLINE,stdin);
    reg(buf);
    eval(buf);
  }
}
