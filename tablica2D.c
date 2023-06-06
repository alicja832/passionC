#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void wypisz_i(int tab[][4],int n);
int suma(int *tab, int n);
int *find_min_wsk (int tab[][4], int n);
int row_number(int tab[][4],int n);
int main(){
int abc[4][4];
int *koniec=&abc[3][3];
int *p=&abc[0][0];
time_t czas;
srand ((unsigned int)time(&czas));
for(;p<=koniec;p++){
    *p=rand()%(10-(-10)+1)+(-10);
    }
wypisz_i(abc,4);
int suma_abc[1][4];
int i;
for(i=0;i<4;i++){
    suma_abc[0][i]=suma(abc[i],4);
}
printf("\n");
wypisz_i(suma_abc,1);
int suma_all_1 = suma (abc[0], sizeof(abc)/sizeof(int));
printf("Suma el 1 %d\n",suma_all_1);
int suma_all_2 = suma(suma_abc[0],sizeof(suma_abc)/sizeof(int));
printf("Suma el 2 %d\n",suma_all_2);
printf("\n");
int z=row_number(abc,4);
printf("wiersz row\n");
printf("numer w %d\n",z);
//wypisz_i(abc+z*4,1);
printf("\n");
int *MIN_WSK=find_min_wsk(abc,4);
printf( "%p  %d\n",MIN_WSK,*MIN_WSK);
int d=(MIN_WSK-abc[0]);
for(i=0;i<4;i++){
    if(((d-i*5)>=0)&& ((d-i*5)/5)<1){
    printf("indeks kolumny to %d\n",d-i*4);
    printf("indeks wiersza to %d",i);
    break;
    }
}


return 0;
}
void wypisz_i(int tab[][4],int n){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<4;j++){
    printf("%4d",*(tab[i]+j));
    }
printf("\n");
}
return;
}
int suma(int *tab, int n){
int suma=0;
int i;
for(i=0;i<n;i++){
    suma+=*(tab+i);
}
return suma;
}
int *find_min_wsk (int tab[][4], int n){
int *min = tab[0];
int *s=tab[0];
while ( s<= tab[n-1]+3){
if(*min > *s) min = s;
s++;
}
return min;
}
int row_number(int tab[][4],int n){
    int *max,maxw,j,i;
max=tab[0];
for(i=0;i<n;i++){
    for(j=0;j<4;j++){
    if(*(tab[i]+j)>*max){
    max=tab[i]+j;
    maxw=i;
    }
    }
}
return maxw;
}
