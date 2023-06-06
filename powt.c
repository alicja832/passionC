#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KOLUMNS 3
#define ROWS 2
int main(){
srand((unsigned int)time(NULL));
int **tab1=malloc(ROWS*sizeof(int*));
int i,j;
int *tab11=malloc(KOLUMNS*ROWS*sizeof(int));
tab1[0]=tab11;

    for(i=1;i<ROWS;i++){
        tab1[i]=tab11+i*KOLUMNS;
        }

    for(i=0;i<ROWS;i++){
        for(j=0;j<KOLUMNS;j++){
            tab1[i][j]=rand()%21;
    }
    }
for(i=0;i<ROWS;i++){
        for(j=0;j<KOLUMNS;j++){
           printf(" %d ", tab1[i][j]);
    }
printf("\n");
    }
free(tab11);
tab11=NULL;
free(tab1);
tab1=NULL;
int **tab2=malloc(ROWS*sizeof(int*));
    for(i=0;i<ROWS;i++){
        tab2[i]=malloc(KOLUMNS*sizeof(int));
        }
for(i=0;i<ROWS;i++){
        for(j=0;j<KOLUMNS;j++){
            tab2[i][j]=rand()%21;
    }
    }
for(i=0;i<ROWS;i++){
        for(j=0;j<KOLUMNS;j++){
           printf(" %d ", tab2[i][j]);
    }
printf("\n");
    }
for(i=0;i<ROWS;i++){
        free(tab2[i]);
        }
free(tab2);
return 0;
}

