#include <stdio.h>
int main(){
char *c[]={"spark","chair","assignment","workingparty"};
char **cp[]={c+3,c+2,c+1,c};
char ***cpp=cp;
cpp++;
printf("%s ",**cpp);
printf("%s",*cp[0]+7);
printf(" %s",*cpp[2]);

printf(" %s",*(*cp-2));
printf(" %s",*--*--cpp+4);
return 0;
}   
