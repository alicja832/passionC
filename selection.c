#include <stdio.h>
int main(){
int A[]={5,3,4,4,2,1,5,7};
int i,min,k,tmp;
int n=8;
for( i=0;i<n;i++){
	min=i;
	for(k=i+1; k<n; k++)
		if(A[k]<A[min])
			min=k;
	tmp=A[min];
	A[min]=A[i];
	A[i]=tmp;
}
for(i=0;i<n;i++){
printf(" %d   ",A[i]);
}
return 0;
}
