//1. ( 2 ) Proszę napisać i przetestować funkcję zgodną z prototypem, float *avg_two (int *, int*);, która //przyjmuje /////jako parametry 2
//wskaźniki na liczby całkowite i wylicza średnią z tak przekazanych wartości. Funkcja ma zwrócić wskaźnik na zmienną rzeczywistą
//przechowującą tak otrzymaną wartość.W main wypisuje wartość średnią
#include <stdio.h>
float *avg_two (int *n, int*m);
int main(){
int n=78;
int m=33;
printf("średnia to %f\n", *avg_two(&n,&m));
return 0;}
float *avg_two (int *n, int*m){
float sr;
sr= (float)(*n+*m)/2;
float *s=&sr;
return s;
}
