#include <stdio.h>
#include <stdlib.h>
int (*trans_all_tabs(int x, int y,int tab[y][x]))[];
int main(){
int i,j;
int tab1[2][3]={{1,2,3},{3,8,9}};
int tab2[3][4]={{2,5,6,7},{6,4,2,1},{2,9,8,1}};
int (*tab3)[2]=trans_all_tabs(3,2,tab1);
for(i=0;i<3;i++){
    for(j=0;j<2;j++){
    printf("%3d",tab3[i][j]);
    }
printf("\n");
}
free(tab3);
return 0;
}
int (*trans_all_tabs(int x, int y,int tab[y][x]))[]{
int (*wsk)[y]=malloc(x*y*sizeof(int));
int i,j;
for(i=0;i<y;i++){
    for(j=0;j<x;j++){
    wsk[j][i]=tab[i][j];
    }
}
return wsk;
}
