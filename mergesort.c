#include <stdio.h>
#include <math.h>
void merge(int *tab, int p, int q, int r){
int a=q-p+1;
int b=r-q;
int L[a],R[b+1];
int i,j,k;
for(i=0;i<a+1;i++)
    L[i]=tab[p+i-1];
for(j=0;j<b+1;j++)
    R[i]=tab[q+j];
//L+a+1=null;
//R+b+1=null;
i=0;
j=0;
for(k=p;k<=r;k++){
    if(L[i]<=R[j]){
        tab[k]=L[i];
        i=i+1;
        }
    else{
        tab[k]=R[j];
         j++;
        }
}
return;
}
void mergesort(int *tab,int p,int r){
if(p<r){
    int q;
    q=floor((p+r)/2);
    mergesort(tab,p,q);
    mergesort(tab,q+1,r);
    merge(tab,p,q,r);
}
return;}
int main(){
int tab[]={4,3,2,1};
int *p=tab;
mergesort(tab,1,3);
for(int i=0;i<4;i++){
    printf(" %d ", *p);
    p++;
}
return 0;
}
