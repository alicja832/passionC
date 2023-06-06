//zad1
#include <stdio.h>
int mniejszy(int k){
return 1;
}
int wiekszy(int l){
return 4;
}
int rowny(int a){
return 5;
}

int main(){
char *nazwy[]={"mniejszy","wiekszy","rowny"};
int (*tab[3])(int k)={mniejszy,wiekszy,rowny};
char s[]={'m','n','i','e','j','s','z','y'};
char *str="wiekszy";
//proba
printf("%s dla %d wynosi %d\n",nazwy[1],2,tab[1](2));
return 0;
}
