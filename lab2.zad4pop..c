#include  <stdio.h>                   //konieczne biblioteki
#include  <string.h>          

int main(int argc, char *argv[])
{ int i,n1=strlen(*(argv+1));
int n2=  strlen(*(argv+2)),n;
char nap_1[n1],nap_2[n2];
    //deklaracja koniecznych zmiennych, miedzy innymi tablic nap_1 oraz nap_2 
 char *p=argv[1];
 for(i=0;i<n1;i++){
 nap_1[i]=*p;
 p++;
 }
 p=argv[2];
 for(i=0;i<n2;i++){
 nap_2[i]=*p;
 p++;
 }
 nap_1[n1]='\0';
nap_2[n2]='\0';
 
 
      //zapisanie argumentów wywołania programu do tablic nap_1 oraz nap_2

printf ("A -->  napis_1 = %s napis_2 = %s\n", nap_1, nap_2);   //zostanie wypisane: A --> napis_1 = Jedenascie napis_2 = Dwiescie 
if(n1>n2) n=n1;
else n=n2;
char wymiana[n];
strcpy(wymiana, nap_1);
n1=n;
strcpy(nap_1, nap_2);
n2=n;
strcpy(nap_2,wymiana);

printf ("B -->  napis_1 = %s napis_2 =  %s\n", nap_1, nap_2);    //zostanie wypisane: B --> napis_1 = Dwiescie napis_2 = Jedenascie 
return 0;
}
