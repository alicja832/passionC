#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void wypelnij(double tab[][6],double ilwier);
void wypisz_d(double *tab1,double *tab2);
int main(){
double A_1[8][6];
double A_2[10][6];
wypelnij(A_1,8);
wypelnij(A_2,10);
wypisz_d(A_1[0],A_1[7]+6);
printf("\n");
for(int i=0;i<8;i++){
wypisz_d(A_1[i],A_1[i]+6);
printf("\n");
}

return 0;
}
void wypelnij(double tab[][6],double ilwier){
int i,j;
double r;
for(i=0;i<ilwier;i++){
    for(j=0;j<6;j++)
    {
    r=(double)rand()/RAND_MAX;
    *(tab[i]+j)=r*(100-0+0.4)+0;
    }
}
return;
}
void wypisz_d(double *tab1,double *tab2){
while(tab1<tab2){
printf("%4.4f  ",*tab1);
tab1++;
}
return;
}
