//2. W funkcji main proszę utworzyć dwuwymiarową tablicę liczb całkowitych abc o pięciu wierszach i
//pięciu kolumnach,
//( 0.5 ) zainicjować ją wartościami, w następujący sposób: i-ty wypełniony wartością i , a
//następnie wypisać procedurą wypisz_i
//TAB[0][0] = 0, TAB[0][1] = 0, TAB[0][2] = 0, TAB[0][3] = 0, TAB[0][4] = 0
//TAB[1][0] = 1, TAB[1][1] = 1, TAB[1][2] = 1, TAB[1][3] = 1, TAB[1][4] = 1
//TAB[2][0] = 2, TAB[2][1] = 2, TAB[2][2] = 2, TAB[2][3] = 2, TAB[2][4] = 2
//TAB[3][0] = 3, TAB[3][1] = 3, TAB[3][2] = 3, TAB[3][3] = 3, TAB[3][4] = 3
//TAB[4][0] = 4, TAB[4][1] = 4, TAB[4][2] = 4, TAB[4][3] = 4, TAB[4][4] = 4

//( 1 ) Wykonać transponowanie tablicy abc - czyli zamienić wiersze z kolumnami i
//wypisać procedurą wypisz_i

//TAB[0][0] = 0, TAB[0][1] = 1, TAB[0][2] = 2, TAB[0][3] = 3, TAB[0][4] = 4
//TAB[1][0] = 0, TAB[1][1] = 1, TAB[1][2] = 2, TAB[1][3] = 3, TAB[1][4] = 4
//TAB[2][0] = 0, TAB[2][1] = 1, TAB[2][2] = 2, TAB[2][3] = 3, TAB[2][4] = 4
//TAB[3][0] = 0, TAB[3][1] = 1, TAB[3][2] = 2, TAB[3][3] = 3, TAB[3][4] = 4
//TAB[4][0] = 0, TAB[4][1] = 1, TAB[4][2] = 2, TAB[4][3] = 3, TAB[4][4] = 4
#include <stdio.h>
void zamiana(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
int abc[5][5];
int i,j;
for(i=0;i<5;i++){
    for(j=0;j<5;j++)
    {
        abc[i][j]=i;
    }
}
for(i=0;i<5;i++){
    for(j=0;j<5;j++)
    {
        printf(" TAB[%d][%d]=%d ",i,j,abc[i][j]);
    }
printf("\n");
}
for(j=0;j<5;j++){
    for(i=j;i<5;i++)
    {
        zamiana(&abc[i][j],&abc[j][i]);
    }
}
printf("\n");
for(i=0;i<5;i++){
    for(j=0;j<5;j++)
    {
        printf(" TAB[%d][%d]=%d ",i,j,abc[i][j]);
    }
printf("\n");
}

return 0;
}
