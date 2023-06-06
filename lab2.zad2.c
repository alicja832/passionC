//Proszę napisać wykorzystując operatory binarne i maski bitowe program, w którym
//zostaną zaimplementowane
//o procedura zamieniająca liczbę całkowitą bez znaku na string reprezentujący jej zapis
//binarny, zgodna z prototypem :
//void write_binar(unsigned n, char * wsk);
//unsigned bits(unsigned x, unsigned n);//zwracająca n najmłodszych bitów z liczby x - bity numerujemy od najmłodszego

//Liczba oraz ilość bitów do wypisania ma być wczytywana z klawiatury - należy sprawdzić czy
//podana ilość bitów jest poprawna
//Wynik dla liczby 435 oraz 7 bitów
//liczba wczytana 435 : 00000000000000000000000110110011
//7 najmlodszych bitow : 00000000000000000000000000110011

#include <stdio.h>
#include <string.h>
unsigned bits(unsigned x, unsigned n); //nalezy wykorzystac maske bitowa
void write_binar (unsigned n, char *wsk); //nalezy wykorzystac maske bitowa
int pot(int a,int b);
int main () {
unsigned result, number, bit_num;
scanf("%d",&number);
do{
    printf("podaj liczbę bitów do wypisania\n");
    printf("\n");
    scanf("%d",&bit_num);
}
while(bit_num>32);
char number_string[32];//tablica na zapis binarny
write_binar(number,number_string);//zamiana liczby na string procedura write_binar
printf("liczba wczytana %d : %s\n", number,number_string); //liczba wczytana
result = bits (number, bit_num); 
write_binar (result,number_string);
printf("%u najmlodszych bitow %s\n", bit_num,number_string); //7 najmlodszych
//printf("result  %u    ",result);
//printf("%ld ",strlen(number_string));
return 0; }
int pot(int a, int b){
int wynik=1;
    for(int i=1;i<=b;i++){
    wynik=wynik*a;}
return wynik;
}
void write_binar (unsigned n, char *wsk){
int i;
unsigned maska=1;
 
    for(i=32;i>=0;i--)
    {
       if((n>>(i-1)) & maska)
        *(wsk+32-i)='1';
        else
        *(wsk+32-i)='0';    
    }
    *(wsk+32)='\0';
return;
}
unsigned bits(unsigned x, unsigned n){
//x-liczba
//n-liczba the younger bits
unsigned maska1=0;
    for(int i=0;i<n;i++){
    maska1=maska1+pot(2,i);
}
//printf("maska %u\n",maska1);
int b=(x & maska1);
return b;
}

