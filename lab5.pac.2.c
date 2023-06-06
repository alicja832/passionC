//W zadaniu proszę korzystać z identyfikatorów array_1, array_2 oraz nie korzystać z operatora &
//Proszę zaalokować i wyzerować zawartość ( calloc) dwóch implementacjidynamicznej tablicy dwuwymiarowej array_1, array_2 o
//elementach typu int
//Każdą tablicę należy wypisać wierszami z wykorzystaniem procedury wypis_i, a następnie zwolnić pamięć.
//rows i columns zdefiniowane przez #define
//( 1.5 ) dynamiczna tablica array_1, która ma rows elementów. Do każdego elementu tablicy array_1 przypięty jest (dynamiczny)
//wiersz o długości columns. Wiersze nie tworzą spójnego obszaru pamięci.
#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 5
#define ROWS 4
int main(){
int **arr1=calloc(ROWS,ROWS*sizeof(int));
int i,j;
int **arr2=malloc(ROWS*sizeof(int));
//int *s;
//for(i=0;i<COLUMNS;i++)
    //arr2[i]=i;
for(i=0;i<ROWS;i++){
    arr1[i]=calloc(COLUMNS,COLUMNS*sizeof(int));
}
for(i=0;i<ROWS;i++){
    for(j=0;j<COLUMNS;j++)
    printf("%d",arr1[i][j]);
    printf("\n");
}
for(i=0;i<ROWS;i++){
   free(arr1[i]);
}

free(arr1);

int *r=malloc(COLUMNS*sizeof(int));
for(i=0;i<COLUMNS*ROWS;i++)
r[i]=i;
arr2[0]=r;
for(i=1;i<ROWS;i++){
    arr2[i]=arr2[0]+i*COLUMNS;
}
for(i=0;i<ROWS;i++){
    for(j=0;j<COLUMNS;j++)
    printf("%d",arr2[i][j]);
    printf("\n");
}

free(arr2[0]);
free(arr2);


return 0;

}
//( 1.5 ) dynamiczna tablica array_2, która ma rows elementów. Do pierwszego elementu tablicy array_2 przypięty jest (dynamiczny)
//spójny obszar pamięci dla wszystkich wierszy. Każdy wiersz ma długość columns. Kolejny element tablicy array_2 wskazuje na
//pierwszy element kolejnego wiersza.
