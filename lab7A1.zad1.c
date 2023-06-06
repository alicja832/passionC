#include <stdio.h>
#include <stdarg.h>
#include <string.h>
void przyad(int *a,...){
//int s=1;
va_list args;
va_start(args,a);
while(*a){
printf("a1 %d\n",*a);
    int s=va_arg(args,int);
    //printf("s %d\n",s);
   
++a;
printf("a %d\n",*a);
}
va_end(args);
return;
}
int main(){
int a=4,b=7,c=6,d=9;
przyad(&a,&b,&c,&d);
return 0;
}
