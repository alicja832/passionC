#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void proc_1(int w1, int k1, int tab1[w1][k1]);
int tcmpr(const void *t1, const void *t2);
void proc_2(int w1, int k1, int tab1[w1][k1]);
void swap(int*a, int*b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
};
int suma (int *tab, int len) { 
    int i,j;
  int ss = 0;
  for (i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
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
}
void swap_row(int n, int (*a)[n], int x, int y){
swap_tab(a[x],a[y],n);
//procedura wymieniająca wiersz x z wierszem y w tablicy a
// przy użyciu procedury swap_tab
return;
}
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}
int main(){
int tab_A[2][6], tab_B[4][3];
int i,j;
srand((unsigned int)time(NULL));
for(i=0;i<2;i++)
    for(j=0;j<6;j++)
    tab_A[i][j]=rand()%20;
printf("A\n");
print_tab_all(6,tab_A,2);
for(i=0;i<4;i++)
    for(j=0;j<3;j++)
    tab_B[i][j]=rand()%20;
printf("B\n");
print_tab_all(3,tab_B,4);
printf("po proc_1\n");
//proc_1(4,3,tab_B);
//print_tab_all(3,tab_B,4);
printf("potem..\n");
proc_2(2,6,tab_A);
print_tab_all(6,tab_A,2);
printf("po raz drugi\n");
proc_2(4,3,tab_B);
print_tab_all(3,tab_B,4);
return 0;
}
void proc_1(int w1, int k1, int tab1[w1][k1]){
int su=0;
int i,j,min=0;
for(j=0;j<w1;j++){
    su=suma(tab1[j],k1);
    min=j;
for(i=j;i<w1;i++){
    if(suma(tab1[i],k1)<su){
    su=suma(tab1[i],k1);
    min=i;
    }
}
swap_row(k1,tab1,j,min);
}
return;
}
void proc_2(int w1, int k1, int tab1[w1][k1]){
qsort(tab1,w1,k1*sizeof(int),tcmpr);
return ;

}
int tcmpr(const void *t1, const void *t2){
    int k1=(t2-t1)/sizeof(int);
    static int k= k1;
    printf("%d\n",k1);
    int s1=suma((int*)t1,k1);
    int s2=suma((int*)t2,k1);
return s1-s2;
}


       
