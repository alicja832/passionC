#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max){
return rand() % (max-min+1) + min;
}

void wypisz_i (int *poczatek, int *koniec) {
  while (poczatek < koniec)
    printf ("%4d ", *poczatek++);
  printf ("\n");
}

int main(void){
    srand(time(NULL));
    printf("podaj rozmiar tablicy:");

    int rozmiar;
    scanf("%d",&rozmiar);

    int *table = malloc(rozmiar*sizeof(int));
    if (!table){
        puts("Blad alokacji\n");
        exit(-1);
    }

    for(int i=0;i<rozmiar;i++){
        *(table +i)= i_rand(-5, 5);
        printf("t[%d]=%d, ",i, *(table+i));
    }
    printf("\n");
    

    int *arg_p=NULL;
    int *arg_n=NULL;

    int p=0,n=0;

    for(int i=0;i<rozmiar;i++){
        if(abs(*(table+i))%2){
            arg_n = realloc(arg_n,(n+1)*sizeof(int));
            if(!arg_n){
                puts("Blad alokacji\n");
                free(arg_p);            
                free(table);
                exit(-1);
            }
            *(arg_n + n) = *(table+i);
            n++;
        }
        else
        {
            arg_p = realloc(arg_p,(p+1)*sizeof(int));
            if(!arg_p){
                puts("Blad alokacji\n");
                free(arg_n);            
                free(table);
                exit(-1);
            }        
            *(arg_p + p) = *(table+i);
            p++;
        }
    }

    for(int i=0;i<p;i++){
        printf("p[%d]=%d, ",i, *(arg_p+i));
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("n[%d]=%d, ",i, *(arg_n+i));
    }
    printf("\n");

/*wypisz_i(arg_n,arg_n +n);
wypisz_i(arg_p,arg_p +p);*/

    free(table);
    free(arg_p);
    free(arg_n);
    return 0;
}
Kacper

