#include <stdio.h>
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
int min (int *tab, int len) { 
  int ind = 0;
  int i;
  for (i = 1; i < len; i++)  
    if(tab[i] < tab[ind])
            ind = i; 
 return ind;}
 void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}
void swap_tab(int *A,int *B,int n){
int i=0;
while(i<n){
swap(A,B);
A++;
B++;
i++;
}
return;
}
void swap_rows(int n, int (*TAB)[n], int x, int y){
swap_tab(TAB[x],TAB[y],n);
}

void sort1(int w, int k, int tab[w][k]){
 int minn,i,j;
 for(j=0;j<w;j++){
 minn=j;
 for(i=0;i<w;i++){
    if(tab[i][min(tab[i],k)]<tab[minn][min(tab[minn],k)]){
    minn=i;}
    }
    
 swap_rows(k,tab,j,minn);
 }
 return;
 }
 int  main(){
 int i;
 int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
 int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
 sort1(3,6,tab_A);
 for(i=0;i<3;i++){
 wypisz_i(tab_A[i],tab_A[i]+6);
 }
 sort1(4,3,tab_B);
 for(i=0;i<4;i++){
 wypisz_i(tab_B[i],tab_B[i]+3);
 }
 return 0;
 }
 
 
