#include <stdio.h>
double suma (double *poczatek, double *koniec) {
double ss = 0;
while (poczatek < koniec)
ss+= *poczatek++;
return ss;}
void wypisz_d (double *t, int len) {
for (int i = 0; i < len; i++)
printf ("%6.2f", t[i]);
printf ("\n");
return;}
double suma_Tx(double *tab[], int x, int n);
double *find_tab(double *tab[], int n);
void swap_pointer(double *tab[],int n);
void swap(double **x, double **y);
int main(){

double T_1[4] = {1.0,3.0, 2.0,1.5};
double T_2[4] = {1.8, 2.0, 1.2, 3.8};
double T_3[4] = {5.6, 1.0, 3.3, 3.3};
double T_4[4] = {1.1, 2.1, -6.5, 1.7};
double T_5[4] = {6.7, 7.8, 9.1, 1.0};
double *TAB[5] = {T_1, T_2, T_3, T_4,T_5};
int i, j;
for (i = 0; i<5; i++){
    for (j = 0; j<4; j++)
    printf("  TAB[%d][%d] = %.2f  ",i,j, TAB[i][j]);
printf ("\n");
}
for (i = 0; i<5; i++)
printf(" suma %d tab %.2f\n",i,suma_Tx (TAB, i, 4));
printf("\n");
wypisz_d(find_tab(TAB, 5),4);
swap_pointer(TAB,5);
for (i = 0; i<5; i++){
    for (j = 0; j<4; j++)
    printf("  TAB[%d][%d] = %.2f  ",i,j, TAB[i][j]);
printf ("\n");
}

return 0;
}
double suma_Tx(double *tab[], int x, int n){
double *p=tab[x], suma=0;
int i;
for (i = 0; i<n; i++){
    suma+=*p;
    p++;
}
return suma;
}
double *find_tab(double *tab[], int n){
int min=0;
double *minwsk;
for(int i=0;i<n;i++){
    if(suma_Tx (tab, i, 4)<suma_Tx (tab, min, 4) ){
        min=i;            
    }
}
minwsk=tab[min];
return minwsk;
}
//( 3 ) Proszę napisać odpowiednią procedurę swap_pointer oraz zmienić
//funkcję find_tab ( na find_tab_1) taka, by zwracała wskaźnik do elementu
//tablicy TAB , który wskazuje na tablicę o najmniejszej sumie elementów.
//Wykorzystując find_tab_1 oraz swap_pointer posortować tablicę TAB ze względu na
//sumę elementów "podpiętej" tablicy.
double **find_tab_1(double *tab[], int n){
int min=0;
double **minwsk;
for(int i=0;i<n;i++){
    if(suma_Tx (tab, i, 4)<suma_Tx (tab, min, 4) ){
        min=i;            
    }
}
minwsk=tab+min;
return minwsk;
}
void swap_pointer(double *tab[],int n){
int i;
swap(tab,find_tab_1(tab,n));
for(i=1;i<n;i++){
        swap(tab+i,find_tab_1(tab+i,n-i));
        }
return;

}
void swap(double *x, double *y){
    double *temp;
    temp=*x;
    *x=*y
    *y=temp;
return;
}
