#include <stdio.h>
#include <stdlib.h>
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int icmpr(const void *a,const void *b){
    return *(const int *)a-*(const int *)b;
}
void proc_1(int w, int k, int tab[w][k]){
int i;
for(i=0;i<w;i++){
    qsort(tab[i],k,sizeof(int),icmpr);
}
return;
}
int main(){
int tab_A[3][6]={{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
int tab_B[4][3]={{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
int i;
for(i=0;i<3;i++){
    wypisz_i(tab_A[i],tab_A[i]+6);
    printf("\n");
    }
for(i=0;i<4;i++){
    wypisz_i(tab_B[i],tab_B[i]+3);
    printf("\n");
    }
int p;
int *w=NULL;
printf("wpisz szukano wartosc\n");
scanf("%d",&p);
for(i=0;i<3;i++){
    qsort(tab_A[i],6,sizeof(int),icmpr);
    }
for(i=0;i<3;i++){
    w=bsearch(&p,tab_A[i],6,sizeof(int),icmpr);
    if(w) break;   
}

if(w) printf("znaleziono w %d\n",i);
else printf("Nie znaleziono\n");
//2 tablica==
w=NULL;
printf("wpisz szukano wartosc dla2\n");
scanf("%d",&p);
for(i=0;i<4;i++){
    qsort(tab_B[i],3,sizeof(int),icmpr);
    }
for(i=0;i<4;i++){
    w=bsearch(&p,tab_B[i],3,sizeof(int),icmpr);
    if(w) break;   
}

if(w) printf("znaleziono w %d\n",i);
else printf("Nie znaleziono\n");


return 0;
}

