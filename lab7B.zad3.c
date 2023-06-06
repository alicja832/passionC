#include <stdio.h>
#include <stdlib.h>
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
int suma (int *tab, int len) { 
    int i,j;
  int ss = 0;
  for (i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
//funkcja porownujaca sumy wierszy
int icmpr2(const void *a,const void *b){
static int l;
static int I=0;
I=I+1;
printf("i=%d\n",I);
if(I==1) {
    l=(int *)b-(int *)a;
    printf("l=%d\n",l);
   }
int s1=suma((int *)a,l);
int s2=suma((int *)b,l);
return s1-s2;
}
void proc_2(int w,int k, int tab[w][k]){
qsort(tab,w,k*sizeof(int),icmpr2);
}
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
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
proc_1(3,6,tab_A);
proc_1(4,3,tab_B);
printf("po procedurze 1\n");
for(i=0;i<3;i++){
    wypisz_i(tab_A[i],tab_A[i]+6);
    printf("\n");
    }
for(i=0;i<4;i++){
    wypisz_i(tab_B[i],tab_B[i]+3);
    printf("\n");
    }
printf("po proc 2\n");
proc_2(3,6,tab_A);
for(i=0;i<3;i++){
    wypisz_i(tab_A[i],tab_A[i]+6);
    printf("\n");
    }
proc_2(4,3,tab_B);
for(i=0;i<4;i++){
    wypisz_i(tab_B[i],tab_B[i]+3);
    printf("\n");
    }
return 0;

}

