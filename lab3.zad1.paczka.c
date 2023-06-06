//1. W funkcji main proszę utworzyć dwuwymiarową tablicę liczb całkowitych abc o pięciu wierszach i
//czterech kolumnach,
//( 0.5 ) zainicjować ją wartościami z przedziału od <-10, 10> i wypisać wierszami
//procedurą wypisz_i (każdy wiersz w nowej linii) .
//( 1 ) Wykorzystując funkcję suma, policzyć sumę z poszczególnych wierszy tablicy abc.
//Wyliczone wartości zapisać do tablicy suma_abc, która ma być zadeklarowana w funkcji main,
//tablicę suma_abc wypisać procedurą wypisz_i.
//( 0.5 ) Policzyć i wypisać sumę elementów z całej tablicy abc wykorzystać identyfikator abc
//int suma_all = suma (..............., sizeof............/sizeof.........);
//Policzyć i wypisać sumę elementów z całej tablicy abc wykorzystać identyfikator suma_abc
//int suma_all_abc = suma (..............., sizeof............/sizeof.........);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void wypisz_i(int *tab, int n, int m);
int suma(int *tab, int n);
int main(){
int abc[5][4],i,j;
time_t czas;
srand((unsigned int)time(&czas));
int *p=&abc[0][0];
    for(;p<=&abc[4][3];p++){
     *p=rand()%(10-(-10)+1)+(-10);   
    }
}
wypisz_i(&abc[0][0],5,4);
//printf(" adres %p indeks w sensie numer miejsa w tab %ld", abc[0], &abc[1][2]-abc[0]);
int suma_abc[1][5];
for(i=0;i<5;i++){
    //printf(" dana %d\n",*(abc[0]+i));
    suma_abc[0][i]=suma(abc[0]+i,4);    
}
printf("\n");
printf("sumy poszczegolnych wierszy\n");
wypisz_i(&suma_abc[0][0],5,1);
int suma_all_abc = suma (&suma_abc[0][0], sizeof(suma_abc)/sizeof(int));
printf("suma all %d   ",suma_all_abc);
int max=abc[0][0],maxw=0;
for(i=0;i<5;i++){
    for(j=0;j<4;j++){
     if(abc[i][j]>max)
        {
        max=abc[i][j];
        //printf("Max %d , %d ,%d\n",max,i,j);
        maxw=i;
        }
    }
}
printf("wiersz z max %d\n",maxw);
wypisz_i(abc[0]+maxw,1,4);
int *T_F=&abc[0][0];
int *min = T_F;
while (T_F < &abc[4][3]){
    if(*min > *T_F) min = T_F;
    T_F++;
}
printf("warosc minimalna jaka %d \n",*min);
return 0;
}
int suma(int *tab,int n){
int i,j;
int suma=0;
    for(j=0;j<n;j++){
     suma+=*(tab+j);   
    }
return suma;

}
void wypisz_i(int *tab, int n, int m){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
     printf("%4d",*(*(tab+i)+j));   
    }
printf("\n");
}
return;
}
//( 2 ) Zaimplementować, wyszukiwanie numeru wiersza, w którym znajduje się maksymalny
//element w tablicy abc - wypisać ten numer, a potem procedurą wypisz_i wypisać wartości
//elementów wyznaczonego wiersza. Proszę ograniczyć ilość wykorzystywanych zmiennych do
//niezbędnego minimum
//( 2 ) Mamy funkcję z poprzedniego laboratorium, zwracającą wskaźnik do elementu
//minimalnego w tablicy
//int *find_min_wsk (int *T_F, int *T_L){ //poczatek i koniec obszaru tablicy gdzie
//szukamy minimum
//int *min = T_F++;
//while (T_F < T_L){
//if(*min > *T_F) min = T_F;
//T_F++;
//}
//return min;}
//Znaleźć wskaźnik do elementu minimalnego w całej tablicy abc, na podstawie wskaźnika
//wyliczyć oba indeksy (numer wiersza i numer kolumny) znalezionego elementu.
//Następnie zaimplementować, wyszukiwanie elementów minimalnych w kolejnych wierszach
//tablicy abc, dla każdego znalezionego elementu na podstawie wskaźnika wyliczyć oba indeksy
//(numer wiersza i numer kolumny).
