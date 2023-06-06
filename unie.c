#include <stdio.h>
#include <stdlib.h>

struct liczba{
char ch;
union{
	int j;
	double d;
	}u;
};
int cmp(const void *a, const void *b){
	struct liczba *aa=(struct liczba*)a;
	struct liczba *bb=(struct liczba*)b;

	if(aa->ch=='i'){


		if(bb->ch=='i')
			return (*aa).u.j-(*bb).u.j;	
	
		else if(bb->ch=='d')
			return 1;
	}
	else if(aa->ch=='d'){
		if(bb->ch=='d')
			return (((*aa).u.d)> ((*bb).u.d))-(((*aa).u.d)<((*bb).u.d));
		else if(bb->ch=='i')
			return -1;
	}
}

//funkcja porównująca dla intów
	int cmp2(const void *a, const void *b){
		return *((const int*)a)-*((const int *)b);
	}
//funckja porównoujaca dla double
	int cmp3(const void *a, const void *b){
		return *((double *)a)-*((double *)b);
	}
		
int main(){
	struct liczba *tab=malloc(4*sizeof(struct liczba));
	int i;
	for(i=0;i<4;i=i+2){
		(tab+i)->ch='i';
	}
	for(i=1;i<4;i=i+2){
		(tab+i)->ch='d';
	}
	for(i=0;i<4;i++){
		if(tab[i].ch=='i')
			tab[i].u.j=5-i;
		else if(tab[i].ch=='d')
			tab[i].u.d=0.33;
	}
		for(i=0;i<4;i++){
		if(tab[i].ch=='i')
			printf(" %d ",tab[i].u.j);
		else if(tab[i].ch=='d')
			printf(" %lf \n",tab[i].u.d);	
	}
printf("posortowana\n");
qsort(tab,4,sizeof(struct liczba),cmp);
		for(i=0;i<4;i++){
		if(tab[i].ch=='i')
			printf(" %d ",tab[i].u.j);
		else if(tab[i].ch=='d')
			printf(" %lf \n",tab[i].u.d);	
	}
double s;
char a;
int s1;
struct liczba *tab1=NULL;
printf("podaj typ \n");
scanf("%c",&a);
printf("podaj liczbę \n");
if(a=='i'){
	scanf("%d",&s1);
	tab1=bsearch(&s1,&(tab->u.j),4,sizeof(struct liczba), cmp2);
}
else{
	scanf("%lf",&s);	
	tab1=bsearch(&s,&(tab->u.d),4,sizeof(struct liczba),cmp3);
    }
if(tab1)
	printf("ind %ld ",tab1-tab);

free(tab);
return 0;
}
		
