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
char words[n];
//printf("%s\n",words);
//char *schowek;
//strtok(words,korektor);
//printf("%s",words);
//strtok(words+5,korektor);
//printf("%s",words);

for(i=1;i<argc;i++){
    p=argv[i];
    if(!strstr(words,p))
    {
    strcat(words,p);
    strcat(words," ");
    }
}   
printf("%s\n",words); 

return 0;
}
