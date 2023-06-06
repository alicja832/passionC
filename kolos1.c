#include <stdio.h>
double *(*f(int s, int k,int i, int lk[s][k][i]))[];
double *(*f(int s, int k,int i, int lk[s][k][i]))[]{
double *tab[2];
double x=3,t=4.8;
double *p1=&x,*p2=&t;
//printf("%d   ",sizeof(p1));
tab[0]=p1;
tab[1]=p2;
double *(*kot)[2];
kot=&tab;
return kot;
}
int main(){
char *c[]={"HOOD","LATE","RING","BABY"};
char **cp[]={c+3,c+2,c+1,c};
char ***cpp=cp+2;
printf("%s",**++cpp+1);//OOD
printf("%s",*++*--cpp-2);//E
printf("%s",*cpp[-1]+2);//NG
printf("%s ",cpp[-2][-1]+2);//NG
for(int i=sizeof(c)/sizeof(*c);i>0;i--)
    printf("%s ",*cp[i-1]);
printf("moje   %s   ",*++*--cpp);
//printf("%s",*cpp[]+2);
double q=6;
double *o=&q;
printf("%lu  ",sizeof(o));


return 0;




}
