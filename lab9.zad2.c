#include <stdio.h>
#include <stdlib.h>
int l;
struct dane{
char *imie[2];
char *nazwisko;
};
struct nauczy{
char *nazwisko;
};
struct struct_1{
int numer;
struct nauczy nauczyciel;
struct dane *uczen;
};
int main(int argc, char *argv[]){
int i;
struct struct_1 klasa;
l=atoi(argv[1]);
klasa.uczen=malloc(l*sizeof(struct dane));
klasa.numer=atoi(argv[2]);
klasa.nauczyciel.nazwisko=argv[3];
for(i=0;i<l;i++){
klasa.uczen[i].imie[0]=argv[3+i*3+1];
klasa.uczen[i].imie[1]=argv[3+i*3+2];
klasa.uczen[i].nazwisko=argv[3+i*3+3];
}
for(i=0;i<l;i++){
printf (" %d, %s, %s, %s\n",klasa.numer,klasa.nauczyciel.nazwisko, klasa.uczen->nazwisko,
klasa.uczen[i].imie[1]);
}
printf("podejsie 2 podaj numer klasy\n");
scanf("%d",&klasa.numer);
printf("podaj nauczyciela\n");
scanf("%s",klasa.nauczyciel.nazwisko);
for(i=0;i<l;i++){
printf("imie 0\n");
scanf("%s",klasa.uczen[i].imie[0]);
printf("imie 1\n");
scanf("%s",klasa.uczen[i].imie[1]);
printf("nazwisko\n");
scanf("%s",klasa.uczen[i].nazwisko);
}
return 0;
}
