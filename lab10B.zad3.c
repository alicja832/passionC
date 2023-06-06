#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//( 4 ) Proszę zaimplementować funkcję wykorzystującą funkcje qsort, oraz bsearch. Funkcja  ma zwracać posortowaną według wartości litery tablicę struktur opisujących statystykę wystąpień litery w przekazanym do funkcji napisie (tylko litery, które są w napisie  bez spacji). Struktura ma zawierać wartość litery (rozróżniamy wielkość liter), oraz tablicę indeksów kolejnych wystąpień litery w napisie.
struct litery{
char a;
int k;
int *tab8=(k*sizeof(int));
};
int litcmp(const void *a,const void *b){
    char *a1=&(((struct litery*)a)->a);
    char *b1=&(((struct litery*)b)->a);
return strcmp(a1,b1);    

}
struct litery *spr(char *wyraz){
struct litery *tab1=malloc(1*sizeof(struct litery));
//65-90 duze
//97-122 male
struct litery c;
struct litery *d;
char x;
char *s;
int i,j=0,k=0,z=0,m;
    for(i=65;i<122;i++){
        if(i>90 && i<97);
        else{
            k=0;
            x=i;
            printf("tu");
           // qsort(tab1,j,sizeof(struct litery),litcmp);
            tab1=realloc(tab1,j*sizeof(struct litery));
            printf("tutaj");
            c.a=x;
            s=strchr(wyraz+z,x);
            if(s){
        
                        if(bsearch(&c,tab1,j-1,sizeof(struct litery),litcmp)){
                                d=bsearch(&c,tab1,j-1,sizeof(struct litery),litcmp);
                                m=d-tab1;
                                k=sizeof(tab1[m].tab8)/sizeof(int);
                                tab1[m].tab8=realloc(tab1[m].tab8,(k+1)*sizeof(int));
                                tab1[m].tab8[k]= s-wyraz;
                                z++;
                        }
                    else{
                    tab1[j].tab8=malloc(1*sizeof(int));
                    tab1[j].a=x;
                    tab1[j].tab8[k]= s-wyraz;
                    j++;
                    z++;}
    }          
}}
return tab1;
};
int main(){
char *napis="Sometimes you will never know the value of a moment until it becomes a memory";
struct litery *tab3;
int i;
tab3=spr(napis);
for(i=0;i<4;i++){
printf("%c = ",tab3[i].a);
printf("%d %d",tab3[i].tab8[0],tab3[i].tab8[1]);
}
free(tab3);
return 0;
}
