#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
int i,n=0;
  char *p;
  for(i=1; i<argc;i++)
    n+=strlen(*(argv+i));
    n+=argc;
char strin[n];
char nowy[n];
    for(i=1;i<argc;i++)
    {   p=argv[i];
        strcat(strin,p);
        strcat(strin," ");
    }
    printf("łańcuch wejsciowy %s \n", strin);
  char separ[] = ")(,;";
  char* token;
  
  token = strtok(strin,separ);
 while (token != NULL){
    printf ("%s \n",token);
//strcpy(nowy,token);
   token = strtok(NULL,separ);
}
//printf ("%s \n",nowy);
 //for(i=1;i<argc;i++)
   // {   p=argv[i];
     //   strcat(strin,p);
       // strcat(strin," ");
    //}

for(i=0;i<sizeof(strin)/sizeof(strin[0]);i++)
    printf("%c",strin[i]);
return 0;
}
