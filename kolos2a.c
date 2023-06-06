#include <stdio.h>
#include <string.h>
int *g(int t){
int s=t*t;
return &s;
}
struct like{
float tab1[2];
float tab2[3];
char name[3][3];
};

struct graph{
char name[10];
struct like edges[3];
};

int main(){
char s='i';
char *t="wu";
struct graph Tab[5][3];
struct graph *wsk = Tab[2];
wsk--;
wsk--;
wsk->name[0]=s;
wsk->edges[0].tab1[0]=2.0;
strcpy(wsk->edges[0].name[0],"ma");
//tab2={1.2,3.3,1.4},name={"j","w"}};
printf("%s %f %s",Tab[1][1].name,Tab[1][1].edges[0].tab1[0],Tab[1][1].edges[0].name[0]);
typedef int *((*f)[6])(int);
f tab;
tab[0]=g;
return 0;
}
