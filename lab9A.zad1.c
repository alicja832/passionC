#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float *x,*y;
//Proszę skonstruować strukturę struct fun do przechowywania nazwy funkcji, oraz
//wskaźnika do funkcji, odpowiadającej nazwie.Wskaźnik ma być do funkcji, która zwraca
//wartość double i przyjmuje jako argumenty dwa wskaźniki typu double*
struct fun{
const char *f;
float (*wskf)(float*,float*);
 };
//Proszę napisać i wywołać funkcję fun_tab , której wywołanie jest następujące:
//wsk_fun = fun_tab(TAB_FUN, names, 4);
//Funkcja ma utworzyć, wypełnić i zwrócić 4-elementową tablicę struktur struct fun.
//Wartości mają pochodzić z tablic, przekazanych jako argumenty funkcji: i-ta struktura ma być
//wypełniona i-tym wskaźnikiem z tablicy TAB_FUN oraz i-tą nazwą z tablicy names

float min (float *f, float *l){
float a = *f++;
while (f < l){
if (a > *f) a = *f;
f++;
}
return a;
}
float max(float *f, float *l){
float a = *f++;
while (f < l){
if (a < *f) a = *f;
f++;
}
return a;
}
float avg (float *f, float *l){
float sum = 0.;
int i = l-f;
while (f < l)
sum += *f++;
return sum/i;
}
float mid (float *f, float *l){
return *(f+(l-f)/2);
}
struct fun *fun_tab(float (**wsk)(float*,float*),char **s,int k){
struct fun *funtab=malloc(k*sizeof(struct fun));
int i;
for(i=0;i<k;i++){
    funtab[i].wskf=*wsk;
    funtab[i].f=*s;
    wsk++;
    s++;
}
return funtab;
};
void fun_prn(struct fun *tab,float (*value)[8],int len_tab, int row){
int i;
for(i=0;i<len_tab;i++){
printf(" %s [%d] = %f",tab[i].f,row,tab[i].wskf(value[row],value[row]+8));
}
return;
}
int icmpf(const void *a, const void *b){
float (*wsk1)(float*,float*)=((struct fun*)a)->wskf;
float (*wsk2)(float*,float*)=((struct fun*)b)->wskf;
float a1=wsk1(x,y);
float a2=wsk2(x,y);
return (a1>a2)-(a1<a2);
}
void sort(struct fun *tab,float (*value)[8],int len_tab, int row){
x=value[row];
y=value[row]+8;
qsort(tab,len_tab,sizeof(struct fun),icmpf);
}

int main(){
int i;
//tablicę stringów zawierającą nazwy funkcji - kolejność odpowiada kolejności funkcji
char* names[]={"min", "max","avg","mid"};
//tablicę liczb rzeczywistych
float data[4][8] = { { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 },
{ 2.5, 3.1, 1.5, 4.2, 2.5, 3.0, 3.5, 4.2 },
{ 1.5, 2.0, 0.5, 2.7, 2.5, 3.0, 1.5, 2.0 },
{ 0.5, 3.0, 0.5, 2.0, 2.0, 3.0, 3.5, 1.0 }};

//a. tablicę wskaźników do funkcji
float (*TAB_FUN[4])(float *,float *);
TAB_FUN[0] = min;
TAB_FUN[1] = max;
TAB_FUN[2] = avg;
TAB_FUN[3] = mid;
struct fun *wsk_fun;
wsk_fun = fun_tab(TAB_FUN, names, 4);
for(i=0; i<4;i++){
fun_prn(wsk_fun, data, 4, i);
printf("\n");
}
sort(wsk_fun,data,4,3);
printf("\n");
fun_prn(wsk_fun, data, 4, 3);
free(wsk_fun);
return 0;
}=
