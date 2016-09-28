#include"algo4-2.c"
#include<stdio.h>
int main(int argc,char **argv)
{
  li_string s,*p;
  str_assign(&s,argv[1]);
  p=s.next;
  while (p)
    {
      if (p->data=='a' && p->next && p->next->data=='b')
        break;
      else
        p=p->next;
    }
  li_string *new_snode=malloc(sizeof(li_string));
  p->data='x';
  p->next->data='y';
  new_snode->data='z';
  new_snode->next=p->next->next;
  p->next->next=new_snode;
  p=s.next;
  while (p)
    {
      printf("%c",p->data);
      p=p->next;
    }
}
