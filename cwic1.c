
// PRATA  rozdzial 10 zmntab2d.c -- funkcje stosujace VLA --troszke przerobione
#include <stdio.h>
#define WIERSZE 3
#define KOLUMNY 4
int sumuj2d(int wiersze, int kolumny, int tab[wiersze][kolumny]);//jezeli definiujemy w deklatracji tablicy ilosc wierszy i ilosc kolumn przez zmienne to deklracje tych zmiennych musza byc przed deklracja tablicy      licy
int sumuj2d_a( int kolumny, int tab[][kolumny], int wiersze);//jezeli definiujemy w deklatracji tablicy tylko ilosc kolumn  przez zmienna to deklracja tej zmiennej musi byc przed deklracja tablicy, ilosc wierszy moze byc zadeklarowana w dowolnym miejscu
int sumuj2d_b(int  , int  , int tab[*][*]);//w prototypie mozna pominac nazwy zmiennych wtedy w deklaracji tablicy pojawiaja sie *

int main(void)
{
     int i, j;
     int rw = 3;
     int rk = 10;
     int graty[WIERSZE][KOLUMNY] = {
            {2,4,6,8},
            {3,5,7,9},
            {12,10,8,6}
     };
     
     int wiecejgratow[WIERSZE-1][KOLUMNY+2] = {
            {20,30,40,50,60,70},
            {5,6,7,8,9,10}
     };
     
     int zmtab[rw][rk];  // VLA
     
     for (i = 0; i < rw; i++)
         for (j = 0; j < rk; j++)
             zmtab[i][j] = i * j + j;
     printf("-------sumuj2d\n");
     printf("tablica 3x4\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d(WIERSZE, KOLUMNY, graty));
     printf("tablica 2x6\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d(WIERSZE-1, KOLUMNY+2, wiecejgratow));
     printf("VLA 3x10\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d(rw, rk, zmtab));
     
     printf("-------sumuj2d_b\n");
     printf("tablica 3x4\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d_b(WIERSZE, KOLUMNY, graty));
     printf("tablica 2x6\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d_b(WIERSZE-1, KOLUMNY+2, wiecejgratow));
     printf("VLA 3x10\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d_b(rw, rk, zmtab));
     
     printf("-------sumuj2d_a\n");
     printf("tablica 3x4\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d_a(KOLUMNY, graty, WIERSZE));
     printf("tablica 2x6\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d_a(KOLUMNY+2, wiecejgratow,WIERSZE-1));
     printf("VLA 3x10\n");
     printf("Suma wszystkich elementow = %d\n", sumuj2d_a(rk, zmtab, rw));
     
     return 0;
}
// funkcje z parametrem VLA

int sumuj2d(int wiersze, int kolumny, int tab[wiersze][kolumny])
{
    int w;
    int k;
    int suma = 0;
    for (w = 0; w < wiersze; w++)
        for (k = 0; k < kolumny; k++)
            suma += tab[w][k];
            
    return suma;
}


int sumuj2d_a(int kolumny, int tab[ ][kolumny], int wiersze)
{
    int w;
    int k;
    int suma = 0;
    for (w = 0; w < wiersze; w++)
        for (k = 0; k < kolumny; k++)
            suma += tab[w][k];
            
    return suma;
}
int sumuj2d_b(int wiersze, int kolumny, int tab[wiersze][kolumny])
{
    int w;
    int k;
    int suma = 0;
    for (w = 0; w < wiersze; w++)
        for (k = 0; k < kolumny; k++)
            suma += tab[w][k];
            
    return suma;
}

