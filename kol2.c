#include <stdio.h>
#include <string.h>
int main(){
char *p="Ala ma Kota";
char pt[]="Ala ma Kota";
printf("p+4= %s ,pt %s ,sizeof(p) %ld ,sizeof(pt) %ld ,strlen(p) %ld ,strlen(pt) %ld",p+4,pt  ,sizeof(p) ,sizeof(pt),strlen(p),strlen(pt));
//ma kota
//ala ma kota
//8
//12
//11
//11
return 0;
}
