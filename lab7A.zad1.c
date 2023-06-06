#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
char *va_cat(char **s1,...){
va_list args;
va_start(args,s1);
char *kon=malloc(30*(sizeof(char)));

while(*s1){
    strcat(kon,*s1);
++s1;
}
va_end(args);

return kon;
}
int main(int argc, char *argv[]){
char *d,*k;
//d=argv[1];
int i;
d=va_cat(argv+1,argv+2);
printf("wynik %s",d);
free(d);
return 0;


}
