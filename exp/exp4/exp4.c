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
void infix2suffix(char *infix,char *suffix){//将表达式转化为后缀表达式保存在suffix_exp中
  char s1[MAXLINE];
  int t1=-1,t2=-1;
  int i=0;
  while (infix[i]){
    if (infix[i]>='0' && infix[i]<='9'){
      while (infix[i] && infix[i]>='0' && infix[i]<='9')
        suffix[++t2]=infix[i++];
      suffix[++t2]='#';
    }//数字直接输出到suffix中，并在数字结尾处加上'#'
    else{
      switch (infix[i]){
      case '(':s1[++t1]='(';break;//'('直接入栈
      case ')':{
        while (s1[t1]!='(')
          suffix[++t2]=s1[t1--];
        t1--;//将最近的‘(’之前的操作符出栈
      }break;
      default:{
        if (t1>=0 && pri(infix[i])<=pri(s1[t1]))
          suffix[++t2]=s1[t1--];
        s1[++t1]=infix[i];
      }//如果是运算符，则需要比较优先级决定是否出栈之前的运算符，再将此操作符如栈
      }
      i++;
    }
  }
  while (t1>=0)
    suffix[++t2]=s1[t1--];
  suffix[++t2]=0;//栈中可能还有操作符
}
int eval_suffix(char suffix[]){//求值后缀表达式
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
  if (buf[0]==0 || !strcmp(buf,"h")){//显示帮助信息
    printf("%s",helpmsg);
    return;
  }
  if (!strcmp(buf,"q"))//退出
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
    reg(buf);//将输入的字符串转化为没有空白字符的连续形式
    eval(buf);//根据用户的输入执行相应的操作
  }
}
