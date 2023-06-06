#include <stdio.h>
void swap(int *a, int *b);
int main(){
int i,j,n=5;
int A[]={3,2,4,1,1};
for(i=0;i<n;i++)
	for(j=n-1;j>i;j--)
		if(A[j]<A[j-1])
		    swap(A+j,A+j-1);
for(i=0;i<n;i++)
printf( "%d  ",A[i]);
return 0;
}
void swap(int *a, int *b){
int tmp;
tmp=*a;
*a=*b;
*b=tmp;
return;
}


