#include <stdio.h>
#include <stdlib.h>
void swap(double **a,double **b);
int main(){
double T_1[3]={2.11,2.9,1.1};
double T_2[3]={1.11,3.22,2.1};
double T_3[3]={3.77,8.9,1.22};
double *TAB[3]={T_1,T_2,T_3};
int i,j;
for(i=0;i<sizeof(TAB)/sizeof(*TAB);i++){
    for(j=0;j<3;j++)
    printf(" %f ",TAB[i][j]);
printf("\n");
}
swap(TAB,TAB+2);
for(i=0;i<sizeof(TAB)/sizeof(*TAB);i++){
    for(j=0;j<3;j++)
    printf(" %f ",TAB[i][j]);
printf("\n");
}

return 0;
}
void swap(double **a,double **b){
double *temp;
temp=*a;
*a=*b;
*b=temp;
return;
}
