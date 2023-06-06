 //Proszę napisać program , w którym będzie zaalokowana pamięć na  dynamiczną tablicę liczb całkowitych table o rozmiarze podanym przez
 //użytkownika,   potem należy wypełnić ją liczbami losowymi z zakresu (-5, 5),
// a następnie jej elementy  przepisać  na dwie tablice dynamiczne :
// elementy parzyste do tablicy arg_p, a elementy nieparzyste do tablicy  arg_n, przyjmujemy, że zero jest parzyste. 
//Wszystkie tablice wypisujemy procedurą wypisz_i (w wywołaniach nie używamy  operatora &)
//UWAGA

//Tablice arg_p oraz arg_n mają "rosnąć" wraz z dodawaniem do nich elementów
//przykład dla n= 7
//int table -> -3, 0, 4, 3, -1, 1, 2,
//int arg_p -> 0, 4, 2,
//int arg_n -> -3, 3, -1, 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int main (){
printf("Podaj rozmiar tablicy\n");
int n;
scanf("%d",&n);
int *table=malloc(n*sizeof(int));
int *p=table;
int i=0;
while(i<n){
    *table=i_rand((-5),5);
    table++;
    i++;
}
wypisz_i(p,table);
table=p;
int j=0,k=0;
int *arg_p=malloc(1*sizeof(int));
int *arg_n=malloc(1*sizeof(int));
for(i=0;i<n;i++){
    if(table[i]%2==0){
printf("parzysta %d\n", table[i]);
    j++;
    arg_p=realloc(arg_p,j*sizeof(int));
    arg_p[j-1]=table[i];
    }
    else{
printf("nieparzysta %d\n", table[i]);
    k++;
    arg_n=realloc(arg_n,k*sizeof(int));
    arg_n[k-1]=table[i];
    }
}
//arg_p=realloc(arg_p,j*sizeof(int));
//arg_n=realloc(arg_n,k*sizeof(int));

wypisz_i(arg_p,arg_p+j);

wypisz_i(arg_n,arg_n+k);
free(table);
free(arg_p);
free(arg_n);
 
return 0;
}
