#include <stdio.h>
#include <stdlib.h>
//#define KOLUMNY 10
//#define WIERSZE 10
void alltabs(int,int, int tab[*][*]);
int **multi_tab(int t1[][3],int t2[][4],int n);
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int main(){
int tab1[2][3]={{1,2,3},{4,5,6}}, tab2[3][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1}};
int i;
for(i=0;i<2;i++)
    wypisz_i(tab1[i],tab1[i]+3);
printf("\n");
for(i=0;i<3;i++)
    wypisz_i(tab2[i],tab2[i]+4);
printf("z użyciem funkcji\n");
alltabs(3,4,tab2);
printf("wynik\n");

int **wsk;
wsk=multi_tab(tab1,tab2,2);
for(i=0;i<2;i++)
    wypisz_i(*(wsk+i),*(wsk+i)+4);

free(*wsk);
*wsk=NULL;
    
free(wsk);
wsk=NULL;

    
return 0;
}
int **multi_tab(int t1[][3],int t2[][4],int n){
int **multi_tab=malloc((n)*sizeof(int));
int *wiers_tab=malloc(8*sizeof(int));
int i,j,z,suma;
for(i=0,j=0;i<8,j<3;i+=4,j++){
    *(multi_tab+j)=wiers_tab+i;
    }
for(i=0;i<n;i++){
    for(j=0;j<4;j++){
        suma=0;
        for(z=0;z<3;z++){
        suma+=t1[i][z]*t2[z][j];
        }
        multi_tab[i][j]=suma;
    }
}

return multi_tab;
}
void alltabs(int wiersze,int kolumny, int tab[wiersze][kolumny]){
int i,j;
for(i=0;i<wiersze;i++){
    for(j=0;j<kolumny;j++)
    {   
        printf("%3d",tab[i][j]);
}
printf("\n");
}
return;}


