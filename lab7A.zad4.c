#include <stdio.h>
#include <math.h>
double f1(double x);
int zero(double (*f)(double), double a, double b, double* m_z, double eps);
int main(){
double a,b;
a=0;
b=8;
printf("wynik   %d\n",zero(f1,a,b,&a,0.1));
a=-1;
b=1;
//printf("wynik   %d\n",zero(sin,a,b,&a,0.1));
return 0;
}
int zero(double (*f)(double), double a, double b, double* m_z, double eps){
double pierwiastek;
int wynik;
if(f(a)*f(b)<0){
    pierwiastek=*m_z;
//printf("msc zerowe %f\n",pierwiastek);
while((b-a)>=eps){
    pierwiastek=(a+b)/2;
    if(f(a)*f(pierwiastek)<=0)
        b=pierwiastek;
    else if(f(b)*pierwiastek<0)
        a=pierwiastek;
}
printf("msc zerowe %f\n",pierwiastek);
wynik=1;
}
else
wynik=0;
return wynik;
}
double f1(double x){
    return (-(x*x) + 3*x +11);
}
