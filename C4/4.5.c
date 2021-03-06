#include"algo4-1.c"
void get_next(sq_string t,int next[])
{
  int j,k=-1;
  next[0]=-1;
  while (j<t.length-1)
    {
      if (k==-1 || t.data[j]==t.data[k])
        {
          k++;
          j++;
          next[j]=k;
        }
      else
        k=next[k];
    }
}
int kmp_index(sq_string s,sq_string t)
{
  int i=0,j=0,next[MAXSIZE];
  get_next(t,next);
  while (i<s.length)
    {
      if (j==-1 || s.data[i]==t.data[j])
        {
          if (j==t.length-1)
            return i-j;
          i++;
          j++;
        }
      else
        j=next[j];
    }
  return -1;
}
int main(int argc, char ** argv)
{
  sq_string s,t;
  str_assign(&s,argv[1]);
  str_assign(&t,argv[2]);
  printf("%d\n",kmp_index(s,t));
}
