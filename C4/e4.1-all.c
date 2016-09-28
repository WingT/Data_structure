#include"algo4-1.c"
typedef struct{
  int data[MAXSIZE];
  int count;
}index_t;
int eq_char(char a,char b)
{
  return (a==b || a=='?' || b=='?');
}
void get_next(sq_string t,int next[])
{
  int j=0,k=-1;
  next[0]=-1;
  while (j<t.length)
    {
      if (k==-1 || eq_char(t.data[j],t.data[k]))
        {
          k++;
          j++;
          if (j<t.length && eq_char(t.data[j],t.data[k]))
            {
              next[j]=next[k];
            }
          else
            next[j]=k;
        }
      else
        k=next[k];
    }
}
index_t kmp_index(sq_string s,sq_string t)
{
  int i=0,j=0,next[MAXSIZE];
  index_t index;
  index.count=0;
  get_next(t,next);
  while (i<s.length)
    {
      if (j==-1 || eq_char(s.data[i],t.data[j]))
        {
          i++;
          j++;
          if (j==t.length)
            {
              index.data[index.count++]=i-j;
              j=next[j];
            }
        }
      else
        j=next[j];
    }
  return index;
}
index_t pattern_index(char s[],char t[])
{
  sq_string sq_s,sq_t;
  str_assign(&sq_s,s);
  str_assign(&sq_t,t);
  index_t index=kmp_index(sq_s,sq_t);
  return index;
}
int main(int argc, char ** argv)
{
  index_t index=pattern_index(argv[1],argv[2]);
  for (int i=0;i<index.count;i++)
    printf("%d ",index.data[i]);
}
