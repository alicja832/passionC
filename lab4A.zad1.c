#include <stdio.h>


void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
 void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}
int main(){
int TAB[]={3,5,6,7,2,4,78};
int *TAB_P[7];
int **WSK,**MIN;
WSK=MIN=TAB_P;
int i;
for(i=0;i<7;i++){
    *(WSK)=TAB+i;
    WSK++;    
}
WSK--;
wypisz_i(*MIN,*WSK+1);
printf("\n");
WSK=MIN;
for(i=0;i<7;i++){
    printf("TAB_P[%d]=%p \n",i,*WSK);  
    WSK++;  
}
WSK=MIN;

for(i=0;i<7;i++){
    if(**(MIN+i)<**WSK) WSK=MIN+i;    
}
printf("Najmniejsza wartość to %d  , indeks to %ld\n",**WSK,WSK-MIN);
swap(*MIN,*WSK);
WSK=MIN;
for(i=0;i<7;i++){
    printf("TAB_P[%d]=%p \n",i,*WSK);  
    WSK++;  
}
WSK--;
wypisz_i(*MIN,*WSK+1);
printf("\n");
//zamiana
printf("wymiana");
int *temp = *MIN;
         *MIN = *WSK;
         *WSK = temp;
printf("\n");
WSK=MIN;
for(i=0;i<7;i++){
    printf("TAB_P[%d]=%p \n",i,*WSK);
    WSK++;    
}
WSK=MIN;
printf("przez wsk\n");
for(i=0;i<7;i++){
    printf(" %d ",**WSK);
    WSK++;
    }
printf("\n przez indentyfikator; ");
wypisz_i(TAB,TAB+7);

return 0;


}
