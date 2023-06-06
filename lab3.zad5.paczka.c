// 3 ) Proszę napisać program, w którym zostanie zdefiniowana tablica TAB typu int,
//tablica TAB_P wskaźników do int. Obie tablice mają mieć po 7 elementów. Tablicę TAB należy

//wypełnić dowolnymi liczbami, natomiast i-ty element tablicy TAB_P ma wskazywać i-
//ty element tablicy TAB (jak na rysunku poniżej). Dodatkowo należy zdefiniować

//wskaźniki WSK oraz MIN, tak aby można było poprawnie dokonać podstawienia WSK = MIN =
//TAB_P

//o Wykorzystując wskaźnik WSK, proszę wypisać wartości tablicy TAB, oraz TAB_P
//Wynik
//o TAB[0] = 5, TAB_P[0] = 000000000062FE00
//o TAB[1] = 34, TAB_P[1] = 000000000062FE04
//o TAB[2] = 78, TAB_P[2] = 000000000062FE08
//o TAB[3] = 23, TAB_P[3] = 000000000062FE0C
//o TAB[4] = 6, TAB_P[4] = 000000000062FE10
//o TAB[5] = 11, TAB_P[5] = 000000000062FE14

//o TAB[6] = 78, TAB_P[6] = 000000000062FE18
//o Wykorzystując wskaźniki WSK oraz MIN, proszę znaleźć wartość minimalną w
//tablicy TAB, i wypisać tę wartość oraz indeks pod którym znajduje się ona w
//tablicy TAB - indeks należy "wyliczyć" wyrażeniem wykorzystując stosowny wskaźnik.
//Wynik
//minimum = 5 indeks = 0
//!!! W programie nie używamy "bezpośrednich" wskaźników do tablicy TAB - do wartości
//tablicy TAB odwołujemy się tylko przy pomocy wskaźników WSK oraz MIN.
#include <stdio.h>
int main(){
int TAB[7]={5,34,78,23,2,11,78};
int i;
int *TAB_P[7];
for(i=0;i<7;i++){
    TAB_P[i]=&TAB[i];
    }
int **WSK,**MIN;
WSK=MIN=TAB_P;
for(;WSK<(MIN+7);WSK++){

    printf("TAB[%ld] = %d, TAB_P[%ld]=%p",WSK-MIN,*(TAB_P[WSK-MIN]),WSK-MIN,TAB_P[WSK-MIN]);
    printf("\n");
    }
int *min=TAB_P[0];
WSK=MIN=TAB_P;
for(;WSK<(MIN+7);WSK++){
    if(*(TAB_P[WSK-MIN])<*min)
    min=TAB_P[WSK-MIN];
}
printf("minimum to %d, indeks %ld",*min, min-*MIN);
return 0;
}
