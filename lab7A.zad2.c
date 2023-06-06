#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int*a, int*b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
};
void swap_tab(int*a, int*b, int n){
int i=0;
while(i<n){
swap(a,b);
a++;
b++;
i++;
}//procedura wymieniająca zawartość tablic a i b (o tym samym rozmiarze) przy użyciu
//procedury swap
return;
};
void swap_row(int n, int (*a)[n], int x, int y){
swap_tab(a[x],a[y],n);
//procedura wymieniająca wiersz x z wierszem y w tablicy a
// przy użyciu procedury swap_tab
return;
};
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int main(){
int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}}; //- wymiana
//wiersza 1 z wierszem 3 przy użyciu procedury swap_row}
int i,j;
srand((unsigned int)time(NULL));
swap_row(5,tab_1,1,3);
for(i=0;i<4;i++)
    wypisz_i(tab_1[i],tab_1[i]+5);
printf("druga tablica\n");
int **tab_3 = malloc( 6*sizeof(int*));
for(i = 0; i < 6; i++)
    tab_3[i] = malloc(3 * sizeof(int));//[6][3]
for(i = 0; i < 6; i++)
    for(j = 0; j < 3; j++)
    tab_3[i][j] = rand() % 21;
for(i=0;i<6;i++)
    wypisz_i(tab_3[i],tab_3[i]+3);
swap_tab(tab_3[1],tab_3[5],3);
printf("po zamianie\n");
for(i=0;i<6;i++)
    wypisz_i(tab_3[i],tab_3[i]+3);
for(i=0;i<6;i++)
    free(tab_3[i]);
free(tab_3);
int **tab_33= malloc( 6*sizeof(int*));
tab_33[0] = malloc(6*3 * sizeof(int));
for(i = 1; i < 6; i++)
tab_33[i] = tab_33[i-1]+3;
for(i = 0; i < 6; i++)
for(j = 0; j < 3; j++)
tab_33[i][j] = rand() % 21;
printf("33 tablica\n");
for(i=0;i<6;i++)
    wypisz_i(*tab_33+i*3,*tab_33+(i+1)*3);
swap_tab(*tab_33+1*3,*tab_33+3*3,3);
printf("po zamianie\n");
for(i=0;i<6;i++)
    wypisz_i(*tab_33+i*3,*tab_33+(i+1)*3);
free(*tab_33);
free(tab_33);
return 0;
}

