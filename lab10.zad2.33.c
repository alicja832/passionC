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

int cmp2(const void *a, const void *b){
int *s1=(int *)a;
int *s2=(int *)b;
//printf("suma %d  ",suma(s1,10));
return suma(s1,10)-suma(s2,10);
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

int **tab_33 = malloc( 15 * sizeof(int*));

tab_33[0] = malloc(10 * 15 * sizeof(int));
for(i = 1; i < 15; i++)  
  tab_33[i] = tab_33[i-1] + (10 * sizeof(int));

for(i = 0; i < 15; i++)
  for(j = 0; j < 10; j++)
   tab_33[i][j]  =  rand() % 21;
   
   //dla tab_33
printf("tab_33\n");
for(i=0;i<15;i++){
    qsort(tab_33[i],10,sizeof(int),cmp);
    wypisz_i(tab_33[i],tab_33[i]+10);
    }
printf("po sortowaniu wg sumy\n");
  qsort(tab_33,15,sizeof(int*),cmp3);   
for(i=0;i<15;i++){
    qsort(tab_33[i],10,sizeof(int),cmp);
    wypisz_i(tab_33[i],tab_33[i]+10);
    }


free(tab_33[0]);
free(tab_33);
return 0;
}
