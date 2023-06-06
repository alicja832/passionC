#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a,const void *b){
	printf("wchodze");
	char *a1=(char *)a;
	char *b1=(char *)b;
	return strcmp(a1,b1);
}
int main(){
	//int (*FF(int T[],int k))[2];
	int TAB[4][6];
	//int (*(*a1)(int T[],int k))[2];
	//int (*a2)[2];
	//int *a3;
	//a1=FF+1;
	//a2=FF(*TAB,6);
	//a3=FF(TAB[0],0)[1];
	char NAP[][5]={"nap1","nap2","nap3"};
	char *b1;
	char b2;
	char (*b3)[3][5];
	printf("tu gra");
	b1=*NAP+1;
	b2=*NAP[1]+1;
	b3=&NAP;
	char *b4="nap2";
	qsort(NAP,3,sizeof(*NAP),comp);
	char (*c)[5]=bsearch(b4,NAP,sizeof(NAP)/sizeof(*NAP),sizeof(*NAP),comp);
	printf("to jest %ld",c-NAP);

//tabliv=
int *c1;
int (*c2)[6];
int c3;
c1=TAB[1];
c2=TAB+1;
c3=*(TAB+1)[1];
	

return 0;
}
