#include <stdio.h>
#include <stdlib.h>
void sort (double **tab1,int n, int*tab2) ;
void swap(int* a, int* b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}
void swap_pointer (double **a, double **b); 
double **find_tab(double **tab1, int len, int *tab2);
double suma (double *tab, int len) { 
int i;
  double ss = 0.0;
  for (i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
int main(){
double  T_0[ ] = {1.0,3.0, 2.0,1.5, 1.5};
double  T_1[ ] = {1.8, 2.0, 1.2};
double  T_2[ ] = {5.6, 1.0, 3.3, 3.3};
double  T_3[ ] = {1.1, 2.1, -6.5, 1.7, 0.4, 1.7};
double  T_4[ ] = {6.7, 7.8, -9.1, 0.1};
double *TAB[5] = {T_0, T_1, T_2, T_3, T_4};
//sizeof(T_1)/sizeof(double)
int T_size[5]={sizeof(T_0)/sizeof(double),sizeof(T_1)/sizeof(double),sizeof(T_2)/sizeof(double),sizeof(T_3)/sizeof(double),sizeof(T_4)/sizeof(double)};
int i,j;
for (i = 0; i < sizeof(TAB)/sizeof(*TAB); i++){
       for (j = 0; j < T_size[i]; j++)
	    printf("TAB[%d][%d]= %.1f", i, j, TAB[i][j]);
        printf ("\n");
    }
printf("\n");
wypisz_d (*find_tab(TAB, 5, T_size), *find_tab(TAB, 5, T_size)+T_size[(find_tab(TAB, 5, T_size)-TAB)]);
printf("\n");
sort(TAB,5,T_size);
for (i = 0; i < sizeof(TAB)/sizeof(*TAB); i++){
       for (j = 0; j < T_size[i]; j++)
	    printf("TAB[%d][%d]= %.1f", i, j, TAB[i][j]);
        printf ("\n");
    }
return 0;
}
double **find_tab(double **tab1, int len, int *tab2){
double mins=suma (tab1[0], *tab2);
int i;
int minw=i;
for(i=0;i<len;i++){
    if(suma (tab1[i], *(tab2+i))<mins){
    mins=suma(tab1[i], *(tab2+i));
    minw=i;
    }
    }
return tab1+minw;
    }
void swap_pointer (double **a, double **b){
double *temp;
temp=*a;
*a=*b;
*b=temp;
return;}
void sort (double **tab1,int n, int*tab2) {
double **mins;
int i;
for(i=0;i<n;i++){
mins=find_tab(tab1+i, 5-i, tab2+i);
swap(tab2+i,tab2+(mins-tab1));
swap_pointer(mins,tab1+i);
}
return;
}

