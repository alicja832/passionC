#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 //generowanie liczb losowych rzeczywistych z przedziału (min, max)
    double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
    }
union number{
int i;
double d;
};
struct liczba{
char s;
union number jeden;
};
//Napisz procedurę, która wypisze element tablicy (wartość --> typ). Wypisz tablicę na ekran.
void wypisz(int l,struct liczba *tab){
int i;

for(i=0;i<l;i++){
printf(" %d --> %s",tab[i].jeden.i,"integer");
printf(" %f --> %s",tab[i].jeden.d,"double");
printf("\n");
}

}
int main(){
srand((unsigned int)time(NULL));
struct liczba tab[10];
int i;
for(i=0;i<10;i++){
tab[i].jeden=(-5)+rand()%(5-(-5)+1);
}
wypisz(10,tab);
//for(i=0;i<10;i++){
//tab[i].jeden.d=d_rand(-5,5);
//}
//wypisz(10,tab);

return 0;
}
