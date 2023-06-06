#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
int main(){
int i,j,columns, rows;
srand(time(0));
columns=i_rand(2,5);
rows=i_rand(1,3);
printf("%d col %d\n",rows, columns);
int **array_1=malloc((rows)*sizeof(int));
for(i=0;i<rows;i++)
    *(array_1+i)=malloc(columns*sizeof(int));
for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        *(*(array_1+i)+j)=i_rand(1,15);
        }
}
for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        printf("%3d",array_1[i][j]);
        }
    printf("\n");
}

printf("tablica array 2\n");
int **array_2=malloc(rows*sizeof(int));
*array_2=malloc((rows*columns)*sizeof(int));
for(i=1;i<rows;i++){
*(array_2+i)=*array_2+i*columns;
}
for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        array_2[i][j]=i_rand(1,15);
        }
}
for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        printf("%3d",array_2[i][j]);
        }
    printf("\n");
}
int nowyrow=i_rand(1,4);
printf("%d",nowyrow);
if(nowyrow<rows){
   for(i=nowyrow;i<rows;i++){
    free(array_1[i]);
    array_1[i]=NULL;
    }     
}
array_1=realloc(array_1,nowyrow*sizeof(int));
//
if(nowyrow>rows){
    for(i=rows;i<nowyrow;i++){
    *(array_1+i)=malloc(columns*sizeof(int));
    } 
    for(i=rows;i<nowyrow;i++){
    for(j=0;j<columns;j++){
        *(*(array_1+i)+j)=i_rand(1,15);
        }
    }
}
printf("wypusz \n");
for(i=0;i<nowyrow;i++){
    for(j=0;j<columns;j++){
        printf("%3d",array_1[i][j]);
        }
    printf("\n");
}
//array2
   *array_2=realloc(*array_2,(nowyrow*columns)*sizeof(int));   
    array_2=realloc(array_2,nowyrow*sizeof(int));

if(nowyrow>rows){
    for(i=rows;i<nowyrow;i++){
    *(array_2+i)=*array_2+i*columns;
    }
}
for(i=rows;i<nowyrow;i++){
    for(j=0;j<columns;j++){
        array_2[i][j]=i_rand(1,15);
        }
}
printf("druga tablica po zminie\n"); 
for(i=0;i<nowyrow;i++){
    for(j=0;j<columns;j++){
        printf("%3d",array_2[i][j]);
        }
    printf("\n");
}
free(*array_2);
*array_2=NULL;
free(array_2);
array_2=NULL;  

    

for(i=0;i<nowyrow;i++){
free(*(array_1+i));
array_1[i]=NULL;
}
printf("tablica array 2\n");
free(array_1);
array_1=NULL;
return 0;
}
