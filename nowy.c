#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void swap(char *p, char *r);
void sort(char stary[10]);
int main(){
time_t czas;
srand((unsigned int)time(&czas));
char a,z;
a='a';
z='z';
char tab1[10];
int i;
for(i=0;i<10;i++)
	{
	tab1[i]=a+ rand()%(z-a+1);
	}
printf("%s\n",tab1);
sort(tab1);
return 0;
}
void sort(char stary[10]){
int i,j;
for(j=0;j<10;j++){
for(i=j;i<10;i++)
	{
	if(strcmp(stary+i,stary+j)<=0){
		swap(stary+j,stary+i);
	}
	}
	}
printf("%s",stary);
}
void swap(char *p, char *r){
char temp;
temp=*p;
*p=*r;
*r=temp;
}
