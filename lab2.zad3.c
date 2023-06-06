//Proszę napisać program, w którym zostanie zdefiniowana tablica TAB typu int,
//tablica TAB_P wskaźników do int. Obie tablice mają mieć po 7 elementów. Tablicę TAB należy

//wypełnić dowolnymi liczbami, natomiast i-ty element tablicy TAB_P ma wskazywać i-
//ty element tablicy TAB (jak na rysunku poniżej). Dodatkowo należy zdefiniować

//wskaźniki WSK oraz MIN, tak aby można było poprawnie dokonać podstawienia WSK = MIN =
//TAB_PWSK = MIN =
//TAB_P

//o Wykorzystując wskaźnik WSK, proszę wypisać wartości tablicy TAB, oraz TAB_P
//Wynik
//o TAB[0] = 5, TAB_P[0] = 000000000062FE00
//TAB[1] = 34, TAB_P[1] = 000000000062FE04
//TAB[2] = 78, TAB_P[2] = 000000000062FE08
//TAB[3] = 23, TAB_P[3] = 000000000062FE0C
//TAB[4] = 6, TAB_P[4] = 000000000062FE10
//TAB[5] = 11, TAB_P[5] = 000000000062FE14
//TAB[6] = 78, TAB_P[6] = 000000000062FE18
//Wykorzystując wskaźniki WSK oraz MIN, proszę znaleźć wartość minimalną w
//tablicy TAB, i wypisać tę wartość oraz indeks pod którym znajduje się ona w
//tablicy TAB - indeks należy "wyliczyć" wyrażeniem wykorzystując stosowny wskaźnik.
//Wynik
//minimum = 5 indeks = 0
//W programie nie używamy "bezpośrednich" wskaźników do tablicy TAB - do wartości
//tablicy TAB odwołujemy się tylko przy pomocy wskaźników WSK oraz MIN.
#include <stdio.h>
int main(){
int TAB[7]={5,34,78,23,6,11,78};
int **wsk,**MIN;
int *TAB_P[7];
wsk=MIN=TAB_P;
for(int i=0; i<7; i++){
    TAB_P[i]=TAB+i;
}
for(;wsk<TAB_P+7;wsk++){
    printf("TAB[%ld] = %d, TAB_P[%ld] = %p", wsk-MIN, *(TAB_P[wsk-MIN]), wsk-MIN, TAB_P[wsk-MIN]);
    printf("\n");
}
wsk=MIN=TAB_P;
for(;wsk<TAB_P+7;wsk++){
if(**wsk<**MIN)
    MIN=wsk;
}
printf("minimum to %d, indeks %ld",**MIN,MIN-TAB_P);
return 0;}
