#include <stdio.h>
int add2(int *, int *);
int comp2(int *, int *);
int add2_or_comp2(int a1, int b2, int (*f)(int*,int*));
int main(){
int a=3, b=6;
printf("suma to %d roznica %d", add2_or_comp2(a,b,add2),add2_or_comp2(a,b,comp2));
return 0;}
int add2(int *a, int *b){
    int suma=*a+*b;
return suma;}
int comp2(int *a, int *b){
 int roznica=*b-*a;
return roznica;}
int add2_or_comp2(int a1, int b2, int (*f)(int*a,int*b)){
int s=f(&a1,&b2);
return s;}
