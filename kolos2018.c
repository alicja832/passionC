#include <stdio.h>
int main(){
struct jeden{
    char *ulica;
    int numerdomu;
};
struct nowy{
   char * nazwisko;
    int wiek;
   struct jeden adresy[3];
}pracownik = {"KOlska",12};
    pracownik.adresy[1].ulica="jerol";
    pracownik.adresy[1].numerdomu=3;
    printf("%s %d %s",pracownik.nazwisko,pracownik.wiek,pracownik.adresy[1].ulica);
return 0;
}
