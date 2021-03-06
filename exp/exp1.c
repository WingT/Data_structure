/**********************/
/* 唐宇奕	      */
/* 2016-10-12	      */
/* 13974454240@qq.com */
/**********************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void add_value(int a){
  a++;
}
void add_ref(int *a){
  *a=*a+1;
}
void illustrate_argument_passing(void){
  int a;
  printf("example:\n");
  printf("routine 1::\n");
  printf("void add_value(int a){\n  a++;\n}\nreturn a;\n");
  printf("routine 2:\n");
  printf("void add_ref(int *a){\n  *a=*a+1;\n}\nreturn a;\n");
  printf("please specify a value to 'a':");
  scanf("%d",&a);
  printf("you have assigned 'a' to %d\n",a);
  add_value(a);
  printf("you have passed argument value to add_value,however the result is: %d\n",a);
  add_ref(&a);
  printf("you have passed argument ref to add_ref,the result %d is correct!\n",a);
}
void illustrate_dynamic_array(){
  int length;
  printf("please specify the length of your integer array:");
  scanf("%d",&length);
  int *old_array=(int *)malloc(sizeof(int)*length),*new_array;
  for (int i=0;i<length;i++)
    scanf("%d",&old_array[i]);
  printf("\nyour new array is:\n");
  for (int i=0;i<length;i++)
    printf("%d ",old_array[i]);
  printf("\ntype '+ count n1 n2 n3 ... nx' to enlarge  the array,type 'q' to exit\n");
  char opt;
  int count;
  while (1){
    scanf("\n%c",&opt);
    switch(opt){
    case '+':{
      scanf("%d",&count);
      new_array=(int *)malloc(sizeof(int)*(length+count));
      for (int i=0;i<length;i++)
        new_array[i]=old_array[i];
      for (int i=0;i<count;i++)
        scanf("%d",&new_array[i+length]);
      length+=count;
      free(old_array);
      old_array=new_array;
      printf("your new array is:\n");
      for (int i=0;i<length;i++)
        printf("%d ",old_array[i]);
      printf("\n");
    }break;
    case 'q':free(old_array);return;
    default :return;
    }
  }
  printf("\n");
}
void display_information(){
  printf("about me:\nID:2015301500046\nname:唐宇奕\nclassa:awesome engineering(卓工)\nemail:13974454240@qq.com\n");
  time_t rawtime;
  time(&rawtime);
  struct tm *timeinfo=localtime(&rawtime);
  printf("about the experiment:\nID:一\nname:IDE的使用及语言复习\ndate:%s",asctime(timeinfo));
}
char *help="1:display menu\n2:illustrate argument passing\n3:illustrate dynamic array\n4:display personal information & experiment information\n5:quit\n";
int main(void){
  int opt;
  printf("%s",help);
  while (1){
    printf("please specify your choice:1-5:");
    scanf("%d",&opt);
    switch (opt){
    case 1:printf("%s",help);break;
    case 2:illustrate_argument_passing();break;
    case 3:illustrate_dynamic_array();break;
    case 4:display_information();break;
    case 5:return 0;
    default:break;
    }
  }
}
