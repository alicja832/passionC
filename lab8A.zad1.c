#include <stdio.h>
#include <math.h>
double fun0(double x) { return log(x); }
double fun1(double x) { return x*x; }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }
void printf_fun(double (*f)(double),const char *s,double *tab,int n);
double (**f3(double x, double (**TAB_FUN)(double)))(double);
int main(){
//b. tablicę stringów zawierającą nazwy funkcji - kolejność odpowiada kolejności funkcji
char* nazwy[]={"log", "pow","sin","cos"};
//c. tablicę liczb rzeczywistych
double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };
double (*(TAB_FUN[5]))(double);
TAB_FUN[0] = fun0;
TAB_FUN[1] = fun1;
TAB_FUN[2] = fun2;
TAB_FUN[3] = fun3;
TAB_FUN[4] = NULL;
printf_fun(fun0,"log",data,8);
double (**wsk)(double);
wsk=TAB_FUN;
char **str;
str=nazwy;
while(*wsk){
    printf_fun(*wsk,*str,data,8);
    wsk++;
    str++;
    printf("\n");
}
double d;
printf("prosze podac argument \n");
scanf("%lf",&d);
double (**wsk2)(double);
wsk2=f3(d,TAB_FUN);
long int ind;
ind=wsk2-TAB_FUN;
printf("max wart to %.3f dla f %s",TAB_FUN[ind](d),nazwy[ind]);
return 0;
}
void printf_fun(double (*f)(double),const char *s,double *tab,int n){
int i;
    for(i=0;i<n;i++){
    printf(" %s(%.1f)=%.3f ",s,tab[i],f(tab[i])); 
      
}
return;}
double (**f3(double x, double (**TAB_FUN)(double)))(double){
double (**max)(double);
max=TAB_FUN;
TAB_FUN++;
    while(*TAB_FUN){
    if((**TAB_FUN)(x)>(**max)(x))
    max=TAB_FUN;
TAB_FUN++;
}
return max;
}



