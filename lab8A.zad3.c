#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
struct vector{
double x;
double y;
double z;
};
struct all_vect{
double x;
double y;
double z;
double len;
};
int dlcmp(const void *a,const void *b);
int dlcmp2(const void *a,const void *b);
double vect_len( struct vector );
void fill_tab ( struct all_vect *, int );
int main(int argc, char *argv[]){
int k=atoi(argv[1]);
printf("%d\n",k);
struct all_vect *tab_vect=malloc(k*4*sizeof(double));
int i;
srand((unsigned int)time(NULL));
for(i=0;i<k;i++){
tab_vect[i].x=rand()%15;
tab_vect[i].y=rand()%15;
tab_vect[i].z=rand()%15;
}
fill_tab(tab_vect,k);
for(i=0;i<k;i++){
printf(" %d x=%f,y=%f,z=%f, dl=%f\n",i,tab_vect[i].x,tab_vect[i].y,tab_vect[i].z,tab_vect[i].len);
}
qsort(tab_vect,k,4*sizeof(double),dlcmp);
printf("po wymianie\n");
for(i=0;i<k;i++){
printf(" %d x=%f,y=%f,z=%f, dl=%f\n",i,tab_vect[i].x,tab_vect[i].y,tab_vect[i].z,tab_vect[i].len);
}
//Wczytać wartość typu double i sprawdzić (bsearch), ile jest wektorów o takiej długości w
//tablicy tab_vect
double d;
printf("podac dl  ");
scanf("%lf",&d);
if(bsearch(&d,&(tab_vect->len),k,4*sizeof(double),dlcmp2))
printf(" jest ");

free(tab_vect);
return 0;
}
double vect_len( struct vector t){
double len;
double x,y,z;
x=t.x;
y=t.y;
z=t.z;
len=sqrt(x*x+y*y+z*z);
return len;}
void fill_tab (struct all_vect *tab_vect, int z ){
//struct vector pomoc;
int i;
double l;
for(i=0;i<z;i++){
struct vector pomoc={tab_vect[i].x,tab_vect[i].y,tab_vect[i].z};
l=vect_len(pomoc);
tab_vect[i].len=l;
}
return;
}
int dlcmp(const void *a,const void *b){
return (*(struct all_vect *)a).len-(*(struct all_vect *)b).len;}
int dlcmp2(const void *a,const void *b){
double x=*(double *)a;
double y=*(double *)b;
return a-b;}
