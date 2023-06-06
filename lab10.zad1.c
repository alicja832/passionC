#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
char *va_cat(int x,char *s,...);
int main(int argc, char *argv[]){
char *c;
c=argv[1];
int i;
for(i=2;i<argc;i++){
c=va_cat(2,c,argv[i]);
//free(c);
}
printf("wynik %s",c);
free(c);
return 0;
}
char *va_cat(int x,char *s,...){
    int z=strlen(s);
    const char *d;
    char *wyp=malloc(z*sizeof(char));
    va_list argptr;
    va_start(argptr,s);
    int i;
strcat(wyp,s);

    for(i=1;i<x;i++){
    
        d=va_arg(argptr,const char*);
    z+=strlen(d);
        wyp=realloc(wyp,z);
        strcat(wyp,d);

    }
//printf("%s",wyp);
 va_end(argptr);       
    
return wyp;
}
