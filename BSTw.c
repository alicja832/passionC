#include "bst.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main(){
srand(time(NULL));
    struct tnode *tree=NULL;
    int i,k,j;
//stwarzam tablice pomocnicza aby nie mogły sie powtarzać
int tab[5];
for(i=0;i<5;i++){
        k=i_rand(0,40);
        if(find(tab,i,k))
            tab[i]=k;
        }

    for(i=0;i<5;i++){
        add2(&tree,NULL,tab[i]);
        printf(" %d ",tab[i]);
    }
printf("\n");
print(tree);
int s;
printf("\npodaj szukaną \n");
scanf("%d",&s);
int a=search(tree,s);
printf(" ile %d\n",a);
int dr=level(tree);
printf("Najdłuższa trasa to %d ",dr);

fre(tree);

return 0;
}
