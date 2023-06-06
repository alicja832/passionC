#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *usun(char *tab1, char *tab2, char *tab3);
int main(int argc, char *argv[]){
int i,n=0;

for(i=1;i<argc;i++){
    n+=strlen(*(argv+i));
}
char TEKST_1[n];
for(i=1;i<argc;i++){
    strcat(TEKST_1,argv[i]);
    strcat(TEKST_1," ");
}//posortowac tablice wymiarow
char *TEKST_2=malloc(n*sizeof(char));
printf("podaj szukana\n");
scanf("%s",TEKST_2);
int len=strlen(TEKST_2)+1;
printf(" dl %d",len);
TEKST_2=realloc(TEKST_2,len*sizeof(char));
char *TEKST_3=malloc(n*sizeof(char));
printf("podaj do zastapienia\n");
scanf("%s",TEKST_3);
int len2=strlen(TEKST_3)+1;
TEKST_3=realloc(TEKST_3,len*sizeof(char));
printf("%s   %s  %s ",TEKST_1 ,TEKST_2,TEKST_3);
usun(TEKST_1,TEKST_2,TEKST_3);
//free(usun(TEKST_1,TEKST_2,TEKST_3));
//free(TEKST_2);
//TEKST_2=NULL;
//free(TEKST_3);
TEKST_3=NULL;
//usun(TEKST_1,TEKST_2,TEKST_3)=NULL;

return 0;
}
char *usun(char *tab1, char *tab2, char *tab3){
printf("%ld",strlen(tab1));
char *wynik=malloc(30*sizeof(char));
char *p=tab1,*wsk=tab1;
int i;
while(strstr(wsk,tab2)!=NULL){
while(p<strstr(wsk,tab2)){
    *wynik=*p;
    p++;
    wynik++;
    }
    for(i=0;i<=strlen(tab3);i++){
    *wynik=tab3[i];
    wynik++;
    }
    
    wsk=p+strlen(tab3);
    }
if(!strstr(wsk,tab2)){
    wsk=tab1;    
    while(p<wsk+(strlen(tab1))){
    *wynik=*p;
    wynik++;
    p++;
    }
    }
    *wynik='\0';
int k=strlen(wynik);
wynik=realloc(wynik, k*sizeof(char));
 return wynik;
 }
    




