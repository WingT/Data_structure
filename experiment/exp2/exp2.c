#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXLINE 1000
int prio(char op){
  switch(op){
  case '+':return 1;break;
  case '-':return 1;break;
  case '*':return 2;break;
  case '/':return 2;break;
  case '^':return 3;break;
  default:return 4;break;
  }
}
void infix2suffix(char infix[],char suffix[]){
  char st[MAXLINE][7];
  int top=-1,top2=0,i=0,openning_bracket=1;
  while (infix[i]){
    if (infix[i]>='0'&&infix[i]<='9'){
      while (infix[i]&&((infix[i]>='0'&&infix[i]<='9')||infix[i]=='.'))
        suffix[top2++]=infix[i++];
      suffix[top2++]='#';
      openning_bracket=0;
    }
    else{
      if (infix[i]>='a'&&infix[i]<='z'){
        int l=0;
        top++;
        while (infix[i]!='(')
          st[top][l++]=infix[i++];
        st[top][l]=0;
      }
      else{
        switch(infix[i]){
        case '(':openning_bracket=1;top++;st[top][0]='(';st[top][1]=0;break;
        case ')':
          while (st[top][0]!='('){
            for (int l=0;st[top][l];l++)
              suffix[top2++]=st[top][l];
            suffix[top2++]='#';
            top--;
          }top--;openning_bracket=0;break;
        case '-':
          if (openning_bracket){
            suffix[top2++]='0';
            suffix[top2++]='#';
          }
          while (top>=0 && st[top][0]!='(' && prio(st[top][0])>=prio('-')){
            for (int l=0;st[top][l];l++)
              suffix[top2++]=st[top][l];
            suffix[top2++]='#';
            top--;
          }
          top++;
          st[top][0]='-';
          st[top][1]=0;
          openning_bracket=0;break;
        case '+':
          if (openning_bracket){
            suffix[top2++]='0';
            suffix[top2++]='#';
          }
          while (top>=0 && st[top][0]!='(' && prio(st[top][0])>=prio('+')){
            for (int l=0;st[top][l];l++)
              suffix[top2++]=st[top][l];
            suffix[top2++]='#';
            top--;
          }
          top++;
          st[top][0]='+';
          st[top][1]=0;
          openning_bracket=0;break;
         default:
           while (top>=0 && st[top][0]!='(' &&prio(infix[i])<=prio(st[top][0])){
             for (int l=0;st[top][l];l++)
               suffix[top2++]=st[top][l];
             suffix[top2++]='#';
             top--;
           }
           top++;
           st[top][0]=infix[i];
           st[top][1]=0;
           openning_bracket=0;
           break;
        }
        i++;
      }
    }
  }
  while (top>=0){
    for (int l=0;st[top][l];l++)
      suffix[top2++]=st[top][l];
    suffix[top2++]='#';
    top--;
  }
  suffix[top2]=0;
  return;
}
double eval_suffix(char suffix[]){
  double ans=0.0,st[MAXLINE];
  int i=0,top=-1;
  while (suffix[i]){
    if (suffix[i]>='0'&&suffix[i]<='9'){
      double tmp=0;
      while (suffix[i]>='0'&&suffix[i]<='9'){
        tmp=tmp*10+suffix[i]-'0';
        i++;
      }
      if (suffix[i]=='.'){
        double scale=0.1;
        i++;
        while (suffix[i]>='0'&&suffix[i]<='9'){
          tmp+=scale*(suffix[i]-'0');
          scale*=0.1;
          i++;
        }
      }
      st[++top]=tmp;
    }
    else{
      double op1=top>0?st[top-1]:0.0;
      double op2=st[top];
      switch (suffix[i]){
      case '+':st[--top]=op1+op2;break;
      case '-':st[--top]=op1-op2;break;
      case '*':st[--top]=op1*op2;break;
      case '/':st[--top]=op1/op2;break;
      case '^':st[--top]=pow(op1,op2);break;
      default :{
        if (strncmp(suffix+i,"abs",3)==0){
          st[top]=abs(op2);
          i+=3;
          break;
        }
        if (strncmp(suffix+i,"sqrt",4)==0){
          st[top]=sqrt(op2);
          i+=4;
          break;
        }
        if (strncmp(suffix+i,"exp",3)==0){
          st[top]=exp(op2);
          i+=3;
          break;
        }
        if (strncmp(suffix+i,"ln",2)==0){
          st[top]=log(op2);
          i+=2;
          break;
        }
        if (strncmp(suffix+i,"log10",5)==0){
          st[top]=log10(op2);
          i+=5;
          break;
        }
        if (strncmp(suffix+i,"sin",3)==0){
          st[top]=sin(op2);
          i+=3;
          break;
        }
        if (strncmp(suffix+i,"cos",3)==0){
          st[top]=cos(op2);
          i+=3;
          break;
        }
        if (strncmp(suffix+i,"tanh",4)==0){
          st[top]=tanh(op2);
          i+=4;
          break;
        }
      }
      }
    }
    i++;
  }
  return st[0];
}
int main(int argc,char **argv){
  char suffix[MAXLINE];
  infix2suffix(argv[1],suffix);
  printf("%s$\n",suffix);
  double ans=eval_suffix(suffix);
  printf("%f\n",ans);
}
