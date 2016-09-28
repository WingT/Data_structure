#include"algo4-1.c"
typedef struct{
  int data[MAXSIZE];
  int count;
}index_t;
void get_next(sq_string t,int next[])
{
  int j=0,k=-1;
  next[0]=-1;
  while (j<t.length)
    {
      if (k==-1 || t.data[j]==t.data[k])
        {
          k++;
          j++;
          if (j<t.length && t.data[j]==t.data[k])
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
      if (j==-1 || s.data[i]==t.data[j])
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
int main(int argc, char ** argv)
{
  sq_string s,t;
  str_assign(&s,argv[1]);
  str_assign(&t,argv[2]);
  index_t index=kmp_index(s,t);
  for (int i=0;i<index.count;i++)
    printf("%d ",index.data[i]);
}
