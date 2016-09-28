#include"algo4-1.c"
#define CONVERT(x) (unsigned int)x
sq_string str_common(sq_string s,sq_string t)
{
  int mask_s[256];
  int mask_t[256];
  for (int i=0;i<256;i++)
    {
      mask_s[i]=0;
      mask_t[i]=0;
    }
  for (int i=0;i<s.length;i++)
    mask_s[CONVERT(s.data[i])]=1;
  for (int i=0;i<t.length;i++)
    mask_t[CONVERT(t.data[i])]=1;
  sq_string ans;
  ans.length=0;
  for (int i=0;i<256;i++)
    if (mask_s[i] && mask_t[i])
      ans.data[ans.length++]=i;
  return ans;
}
int main(int argc,char **argv)
{
  sq_string s,t,ans;
  str_assign(&s,argv[1]);
  str_assign(&t,argv[2]);
  ans=str_common(s,t);
  disp_str(ans);
  printf("\n");
}
