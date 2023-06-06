#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
int n,i;
char *p;
char korektor[]=",.-";
for(i=1;i<argc;i++){
    n+=strlen(*(argv+i));
    strtok(argv[i],korektor);
    }
int a;
p=argv[1];
for(i=2;i<argc;i++){
    a=strcmp(p,argv[i]);
    if(a<0)p=argv[i];
}   
printf("%s\n",p); 
a=0;
for(i=1;i<argc;i++){
if(strcmp(argv[i],p)==0)
a++;
}
printf("\n wystąpiło %d razy",a);
return 0;
}
