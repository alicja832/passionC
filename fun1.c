#include <stdio.h>
#include <stdlib.h>
void proc(int var, int T[][var],int var2){
    printf("Udało się !\n");
}
int (*fun_foo(int x, int y))[]{
    //int **tab=malloc(x*sizeof(int*));
    //tab[0]=malloc(x*y*sizeof(int));
    //int i;
    //for(i=1;i<x;i++)
      //  tab[i]=tab[i-1]+y;
    //int **k=tab;
    int (*tab)[y]=malloc(x*y*sizeof(int));
    return tab;
}
int main(){
    int (*pointer)[3]=fun_foo(2,3);
    proc(3,pointer,2);
//przy kompilacji mowi ze cos nie pasi ale wychodzi
return 0;
}
