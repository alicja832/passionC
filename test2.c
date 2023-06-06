#include <stdio.h>
#include <string.h>
int main(){
int A[3];
char NAP[4][5] = {"nap1", "nap2","nap3"};
double T[][2] = {{1.0,1.0},{0.},{2.0,3.0}};

//Proszę zadeklarować zmienne a, b, c, d, e tak, aby //podstawienia odbyły się poprawnie (bez ostrzeżeń)
int (*a)[3] = &A;
char *b = NAP[2];
char *c = *NAP[1]++;
double (*d)[2] = (double [][2]){1.0, 3.0, 4.0};
char (*e)[5] = NAP;
return 0;
}


