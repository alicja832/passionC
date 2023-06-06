#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmpr(const void *a, const void *b){
return strcmp(*(const char **)a,*(const char **)b);
}
int main(){
char *TAB[]={"Ala","As","Bolek","Lolek","Ola","Reksio","Tola"};
char *pattern="Lolek";
char **result=bsearch(&pattern,TAB,7,sizeof(*TAB),cmpr);
if(result)
printf("%ld",result- TAB);
else printf("brak");
return 0;

}

