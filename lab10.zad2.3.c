#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_i (int *poczatek, int *koniec) { 
int i;
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
 int cmp(const void *a, const void *b){
return *(const int*)a-*(const int*)b;
}


 int cmp3(const void *a, const void *b){
 //printf("jestem");
 int *a1=*((int **)a);
 int *b1=*((int **)b);
 //printf("%d",suma(a1,10));
return suma(a1,10)-suma(b1,10);
}  

int main(){
int i,j;
srand((unsigned int)time(NULL));
int **tab_3 = malloc( 15*sizeof(int*));

for(i = 0; i < 15; i++)  
tab_3[i] = malloc(10 * sizeof(int));

for(i = 0; i < 15; i++)
  for(j = 0; j < 10; j++)
   tab_3[i][j]  =  rand() % 21;
   
   
printf("Po sortowaniu wierszami tab_3\n");
for(i=0;i<15;i++){
    qsort(tab_3[i],10,sizeof(int),cmp);
    wypisz_i(tab_3[i],tab_3[i]+10);
    }
    
 printf("Po sortowaniu ze wzgl na sume\n");
 qsort(tab_3,15,sizeof(int*),cmp3);
 for(i=0;i<15;i++){
    wypisz_i(tab_3[i],tab_3[i]+10);
    }
  printf("wpisz wartosc sumy\n");
int s;
scanf("%d",&s);
int **tabs=malloc(sizeof(int*));
tabs[0]=malloc(sizeof(10*sizeof(int)));
tabs[0][0]=s;
for(i=1;i<10;i++)
tabs[0][i]=0;
int **szuk;
szuk=bsearch(tabs,tab_3,15,sizeof(int*),cmp3);
int w=szuk-tab_3;
if(szuk) wypisz_i(tab_3[w],tab_3[w]+10);

 
 //zwolninie
 for(i=0;i<15;i++){
 free(tab_3[i]);
 tab_3[i]=NULL;
 }
 free(tab_3);
return 0;
}
