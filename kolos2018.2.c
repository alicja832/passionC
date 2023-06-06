#include<stdio.h>
#include<stdlib.h>
struct osoba{
char *imie;
int start;
int koniec;
};
int cmp(const void* a, const void *b){
    int a1=((struct osoba *)a)->start;
    int a2=((struct osoba *)a)->koniec;
     int b1=((struct osoba *)b)->start;
    int b2=((struct osoba *)b)->koniec;
return (a2-a1)-(b2-b1);

}
int main(int argc, char *argv[]){
struct osoba *tab=malloc(((argc-1)/3)*sizeof(struct osoba));
int i;
for(i=1;i<argc;i+=3){
    tab[(i-1)/3].imie=argv[i];
    tab[(i-1)/3].start=atoi(argv[i+1]);
    tab[(i-1)/3].koniec=atoi(argv[i+2]);
}
int c=(argc-1)/3;
for(i=0;i<c;i++){
    printf("%s",tab[i].imie);
    printf(" %d",tab[i].start);
    printf(" %d\n",tab[i].koniec);
}
qsort(tab,c,sizeof(struct osoba),cmp);
for(i=0;i<c;i++){
    printf("%s",tab[i].imie);
    printf(" %d",tab[i].start);
    printf(" %d\n",tab[i].koniec);
}
int n;
printf("podaj liczbę lat\n");
scanf("%d",&n);
struct osoba s;
struct osoba *d;
s.start=tab->start;
s.koniec=tab->start+n;
d=bsearch(&s,tab,c,sizeof(struct osoba),cmp);
printf("to osoba  %s",tab[d-tab].imie);
free(tab);
return 0;
}
