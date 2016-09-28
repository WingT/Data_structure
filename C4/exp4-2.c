#include"algo4-1.c"
int main(void)
{
  sq_string s,s1,s2;
  str_assign(&s,"abcdefghijklmn");
  str_assign(&s1,"xyz");
  disp_str(s);
  printf("\n%d\n",str_length(s));
  s2=ins_str(s,9,s1);
  disp_str(s2);
  printf("\n");
  s2=del_str(s,2,5);
  disp_str(s2);
}
