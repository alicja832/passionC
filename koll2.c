#include <stdio.h>
int main(){
    int (*FF(int T[], int k))[2];
    int TAB[4][6];
    int (*(*a1)(int T[], int ))[2]=FF+1;
    int (*a2)[2]=FF(*TAB,6);
    int *a3=FF(TAB[0],0)[1];


    char NAP[][5]={"nap1","nap2","nap3"};

    char *a5=*NAP +1;
    char a_2=*NAP[1];
    char (*a6)[3][5]=&NAP;
    char (*a15)[5]=NAP;

    int TAB1[4][6];
    int *a8;
    int (*a9)[6];
    int a10;

    a8 = TAB1[1];
    a9 = TAB +1;
    a10 = *(TAB+1)[1];

    double *(*F1(int T[], int k))[2];

    double T[][2]={{1.0,1.0},{0.},{2.0,3.0}};
    
    int (*b)[4][6]=&TAB;
    double *(*(*c)(int T[],int))[2]=F1+1;
    double *(*f)[2];
    f=F1(*TAB,6);
    double (*d)[2]=T+1;
    double **e=F1(TAB[1],3)[1];
    char (*k)[5]=NAP;
//pojawi sie tylko ze nie ma funkcji
    

    return 0;

}
