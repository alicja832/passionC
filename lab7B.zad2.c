#include <stdio.h>
int suma (int *tab, int len) { 
    int i,j;
  int ss = 0;
  for (i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
void swap(int*a, int*b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
};
void swap_tab(int*a, int*b, int n){
int i=0;
while(i<n){
swap(a,b);
a++;
b++;
i++;
}//procedura wymieniająca zawartość tablic a i b (o tym samym rozmiarze) przy użyciu
//procedury swap
return;
};
void swap_row(int n, int (*a)[n], int x, int y){
swap_tab(a[x],a[y],n);
//procedura wymieniająca wiersz x z wierszem y w tablicy a
// przy użyciu procedury swap_tab
return;
};
void sort1(int w, int k, int tab[w][k]){
int mins;
int i,j;
for(j=0;j<w;j++){
mins=j;
for(i=j;i<w;i++){
    if(suma(tab[i],k)<suma(tab[mins],k)){
        mins=i;
    }    
    swap_row(k,tab,j,mins);
  }
}
return;
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
sort1(3,6,tab_A);
sort1(4,3,tab_B);
for(i=0;i<3;i++){
    wypisz_i(tab_A[i],tab_A[i]+6);
    printf("\n");
    }
for(i=0;i<4;i++){
    wypisz_i(tab_B[i],tab_B[i]+3);
    printf("\n");
    }
return 0;

}


