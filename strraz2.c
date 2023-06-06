//3. ( 4 ) Proszę napisać program, który usunie z łańcucha wszystkie wystąpienia pod-łańcucha.
//Należy skorzystać z funkcji char* strstr (const char* str1, const char* str2);.
//Przykład działania
//Łańcuch wejściowy: Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.
//Łańcuch do usunięcia: sie
//Lańcuch wyjściowy: Jak nie ma, co lubi, to lubi, co ma.
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
int i,n=0,n1;
for(i=1;i<argc;i++){
    n+=strlen(*(argv+i));
}
printf(" sl %ld  ",strlen(*(argv+1)));
char dlugi[n+argc];
char krotki[3];
//printf("Łańcuch do usunięcia \n");
//scanf(" %s",&krotki[3]);
//int n2=strlen(krotki);
//krotki[n2]='\0';
char *p;
int j;
for(i=1;i<argc;i++){
        p=argv[i];
        for(j=0;j<strlen(*(argv+i));j++){
            strcat(dlugi,p);
            p++;
        }
        strcat(dlugi," ");
}
 //if(!strstr(argv[i],krotki)

printf("łancuch wyjsciowy to %s", dlugi);


return 0;



}
