#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc,char **argv)
{
  double a=atof(argv[1]),b=atof(argv[2]),c=atof(argv[3]),d=b*b-4*a*c;
  if (d==0)
      printf("The only root is %lf\n",-b/(2*a));
  else
    if (d<0)
      printf("There's no root\n");
    else
      {
        double sd=sqrt(d);
        printf("Root1:%lf\nRoot2:%lf\n",(-b-sd)/(2*a),(-b+sd)/(2*a));
      }
  return 0;
}
