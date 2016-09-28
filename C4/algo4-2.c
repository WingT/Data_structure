#include<stdlib.h>
typedef struct snode{
  char data;
  struct snode *next;
}li_string;
void str_assign(li_string *s,char cstr[])
{
  li_string *r=s;
  for (int i=0;cstr[i]!=0;i++)
    {
      li_string *new_snode=(li_string *)malloc(sizeof(li_string));
      new_snode->data=cstr[i];
      r->next=new_snode;
      r=new_snode;
    }
  r->next=NULL;
}
