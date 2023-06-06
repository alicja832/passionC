#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLUMNS 4
double *tab_avg(int tab[][COLUMNS],int n);
int i_rand(int min, int max){
    //time_t czas;
    //srand((unsigned int)time(&czas));
    return rand() % (max-min+1) + min;
    }
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int suma (int *tab, int len) {
  int i; 
  int ss = 0;
  for (i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.5f,", *poczatek++); 
  printf ("\n");    
  return;}
int main(){
int TAB[ROWS][COLUMNS];
int *p=TAB[0];

int *koniec=&TAB[ROWS-1][COLUMNS-1];
for(;p<=koniec;p++){
    *p=i_rand(-5,5);   
}
for(int i=0;i<ROWS;i++){
    wypisz_i(TAB[i],TAB[i]+COLUMNS);
}
double *sr=tab_avg(TAB,ROWS);
wypisz_d(sr,sr+ROWS);
free(tab_avg(TAB,ROWS));
return 0;
}
double *tab_avg(int tab[][COLUMNS],int n){
int i;
double *avg=malloc(n*sizeof(double));
for(i=0;i<n;i++){
    *(avg+i)=(double)(suma(tab[i],COLUMNS)/(double)COLUMNS);
}
return avg;

}

