#include <stdio.h>
int main(){
int TAB[4][6];
char *NAP[]={"nap1","nap2","nap3"};
double T[][2]={{1.0,1.0},{0.},{2.0,3.0}};
double (*a)[3][2]=&T;
double (*a1)[2]=T;
//double ***a1=&T;
//int (*FF(int k))[3];

//int (*(*b)(int))[3]=FF+1;
//int (*c)[3]=FF(9);
int (*d)[6]=&TAB[2];
//int *e=FF(9)[1];
char *f=*NAP +1;
char g=*NAP[1]++;
printf("%c",g);
double (*h)[2]=(double [][2]){1.0,3.0,4.0};
char **k=NAP;
return 0;
}
