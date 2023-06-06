#include <stdio.h>
#include <math.h>
int *podloga(double *x, double *y);
int main(){
double a=7.9999;
double b=3.009;
printf("iloczyn podłoga %d\n",*podloga(&a,&b));
return 0;
}
int *podloga(double *x, double *y){
double il=*x * *y;
int wynik=(int)(il);
int *w=&wynik;
return w;
}

