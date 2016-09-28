#include<stdio.h>
#define MAXLINE 1000
void infix2suffix(char *infix,char *suffix)
{
  struct {
    char data[MAXLINE];
    int top;
  }op;
  op.data[0]='=';
  op.top=0;
  int suffix_len=0;
  int pri_in[128];
  int pri_out[128];
  pri_in['=']=0;
  pri_in['+']=2;
  pri_in['-']=2;
  pri_in['*']=4;
  pri_in['/']=4;
  pri_in['(']=6;
  pri_in[')']=1;
  pri_out['+']=3;
  pri_out['-']=3;
  pri_out['*']=5;
  pri_out['/']=5;
  pri_out['(']=1;
  int i=0;
  while (infix[i])
    {
      if (infix[i]>='0' && infix[i]<='9')
        {
          for (;infix[i]>='0' && infix[i]<='9';i++)
            suffix[suffix_len++]=infix[i];
          suffix[suffix_len++]='#';
        }
      else
        {
          if (pri_in[infix[i]]>pri_out[op.data[op.top]])
            op.data[++op.top]=infix[i++];
          else
            if (pri_in[infix[i]]==pri_out[op.data[op.top]])
              {
                op.top--;
                i++;
              }
            else
              suffix[suffix_len++]=op.data[op.top--];
        }
    }
  while (op.data[op.top]!='=')
    suffix[suffix_len++]=op.data[op.top--];
  suffix[suffix_len]=0;
}
int eval_suffix(char *suffix)
{
  struct {
    int data[MAXLINE];
    int top;
  }operand;
  operand.top=-1;
  int i=0;
  while (suffix[i])
    {
      if (suffix[i]>='0' && suffix[i]<='9')
        {
          int temp=0;
          for (;suffix[i]!='#';i++)
            temp=temp*10+suffix[i]-'0';
          operand.data[++operand.top]=temp;
          i++;
        }
      else
        {
          int num2=operand.data[operand.top--];
          int num1=operand.data[operand.top--],num3;
          switch (suffix[i]) {
          case '+': {
            num3=num1+num2;
            break;
          }
          case '-': {
            num3=num1-num2;
            break;
          }
          case '*': {
            num3=num1*num2;
            break;
          }
          case '/': {
            num3=num1/num2;
            break;
          }
          default:
            break;
          }
          operand.data[++operand.top]=num3;
          i++;
        }
    }
  return operand.data[0];
}
int main(int argc,char **argv)
{
  if (argc != 2)
    {
      printf("usage: %s infix_exp\n",argv[0]);
      return 1;
    }
  else
    {
      char suffix_exp[MAXLINE];
      infix2suffix(argv[1],suffix_exp);
      printf("suffix exp is: %s\n",suffix_exp);
      printf("%d\n",eval_suffix(suffix_exp));
      return 0;
    }
}
