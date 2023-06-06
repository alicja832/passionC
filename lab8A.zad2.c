#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int charcmp(const void *a,const void *b){
//printf("%d \n",*(char *)b-*(char *)a);
//return *(char *)b-*(char *)a;
//if(*(char *)a-*(char *)b==32 )return 1;
//if(*(char *)a-*(char *)b==0) return -1;
if(((64<*(char *)b && *(char *)b<91) && (64<*(char *)a && *(char *)a<91)) || ((96<*(char *)b && *(char *)b<129) &&  (96<*(char *)a && *(char *)a<129)))
 return strcmp((const char*)a,(const char*)b);
else {
if(*(char *)b>*(char *)a) return strcmp((const char*)a+32,(const char*)b);
if(*(char *)b<*(char *)a) return strcmp((const char*)a,(const char*)b+32);
}
}

int main(){
char T[20][16];
srand((unsigned)time(NULL));
int i,j;
for(i=0;i<20;i++){
    for(j=0;j<15;j++){
    T[i][j]='A'+rand()%('z'-'A'+1);
    while((T[i][j]>90) && (T[i][j]<97))
    T[i][j]='A'+rand()%('z'-'A'+1);
    }   
T[i][15]='\0';
}
printf("Wygenerowane łańcuchy \n");
for(i=0;i<20;i++){
    for(j=0;j<15;j++){
    printf("%c",T[i][j]);
    }   
printf("\n");
}
for(i=0;i<20;i++){
qsort(T[i],15,sizeof(char),charcmp);
}
printf("Wygenerowane łańcuchy po Q1\n");
for(i=0;i<20;i++){
    for(j=0;j<15;j++){
    printf("%c",T[i][j]);
    }   
printf("\n");
}
return 0;}
