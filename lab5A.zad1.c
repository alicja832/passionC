#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *usun(char *wejscie, char *dousun);
int main(int argc, char *argv[]){
if(argc>1){
int i,n=0;
for(i=1;i<argc; i++)
    n+=strlen(argv[i]);
n+=argc;
char *input=malloc((n+1)*sizeof(char));
for(i=1;i<argc; i++){
    strcat(input, argv[i]);
    strcat(input, " ");    
}
char szuk[n];
printf(" wpisz szukana \n");
scanf("%s",szuk);
printf(" Łańcuch wejsciowy to %s \n",input );
printf("szukany to "); 
printf("%s",szuk);
printf("\nPo usunieciu %s\n",usun(input, szuk));
free(usun(input, szuk));
free(input);
}
return 0;
}
char *usun(char *wejscie, char *dousun){
char *nowy=malloc((strlen(wejscie)+1)*sizeof(char));
//printf("%ld",(strlen(wejscie)+1));
int z=0;
char *p=wejscie,*wsk;
while(strstr(p, dousun)){
    wsk=strstr(p, dousun);
    while(p<strstr(wsk, dousun)){
    nowy[z]=*p;
    z++;
    p++;
    }
p=p+strlen(dousun);
}
if(!strstr(p, dousun))
while(p<wejscie+strlen(wejscie)){
nowy[z]=*p;
p++;
z++;
}
nowy[z]='\0';
int l=strlen(nowy);
nowy=realloc(nowy,l*sizeof(char));  
//printf("%s", nowy);


return nowy;
free(nowy);
}

