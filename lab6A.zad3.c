#include <stdio.h>
#include <stdlib.h>
int **multi_tab(int musthave,int,int t1[*][musthave],int t2[musthave][*],int);
void alltabs(int ,int , int tab[*][*]);
int main(){
int tab1[3][3]={{2,1,1},{3,3,3},{2,8,8}};
int tab2[3][3]={{5,5,5},{2,2,2},{1,2,3}};
alltabs(3,3,tab1);
printf("razy\n");
alltabs(3,3,tab2);
int tab3[3][3];
int **p;
p=multi_tab(3,3,tab1,tab2,3);
int i,j;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        tab3[i][j]=*(*(p+i)+j);
alltabs(3,3,tab3);
free(p);
p=NULL;
int tab4[3][2]={{2,7},{3,8}};
printf("Drugie podjescie\n");
alltabs(3,2,tab4);
printf("rAZY\n");

int **k;
k=multi_tab(3,2,tab1,tab4,3);
int tab5[3][2];
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        tab5[i][j]=*(*(k+i)+j);
alltabs(3,2,tab5);
free(k);
return 0;
}
int **multi_tab(int musthave,int k2,int t1[][musthave],int t2[musthave][k2],int w1){
int **multi_tab=malloc((w1)*sizeof(int));
int *wiers_tab=malloc(k2*sizeof(int));
int i,j,z,suma;
for(i=0,j=0;i<(w1*k2),j<w1;i+=k2,j++){
    *(multi_tab+j)=wiers_tab+i;
    }
for(i=0;i<w1;i++){
    for(j=0;j<k2;j++){
        suma=0;
        for(z=0;z<musthave;z++){
        suma+=t1[i][z]*t2[z][j];
        }
        multi_tab[i][j]=suma;
    }
}

return multi_tab;
}
void alltabs(int wiersze,int kolumny, int tab[wiersze][kolumny]){
int i,j;
for(i=0;i<wiersze;i++){
    for(j=0;j<kolumny;j++)
    {   
        printf("%3d",tab[i][j]);
}
printf("\n");
}
return;}


