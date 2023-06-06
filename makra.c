#include <stdio.h>
#include <stdlib.h>
#define ADD(a,b) (a++)+b
int main(){
	float a=4.2,b=3;
	printf("Wynik defina to %f:", ADD(a,b));
	printf("PIerwsza zmienna to %f",a);
return 0;
}
