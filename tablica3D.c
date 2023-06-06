#include <stdio.h>
#include <stdlib.h>
int **tab3(int x, int y){
	int **tab=malloc(x*sizeof(sizeof(int*)));
	tab[0]=malloc(x*y*sizeof(int));
	for(int i=1; i<x ;i++){
		tab[i]=tab[i-1]+y;
	}
return tab;
}

void proc(int tab[][7],int k){
	printf("Sukces");
}

int main(){
	int **t=tab3(2,7);
	proc(t,3);
free(*t);
free(t);
return 0;
}
