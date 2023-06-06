#include <stdio.h>
int *find_min_wsk (int *t1, int *t2);
void sort (int *tab, int n);
void swap(int*a, int*b){
int temp = *a;
*a = *b;
*b = temp;
return;}
int main(){
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
    printf("Wskaźnik do min warosci to %p indeks %ld\n",find_min_wsk(tab_A,tab_A+22),find_min_wsk(tab_A,tab_A+22)-tab_A);
    //sort(tab_A,23);
    for(int i=0;i<23;i++){
    printf("%d  ",tab_A[i]);
    }
printf("\n");
sort (tab_A,9);
sort(tab_A+9,14);
for(int i=0;i<23;i++){
    printf("%d  ",tab_A[i]);
    }

printf("\n");

}
int *find_min_wsk (int *t1, int *t2){
    int *min=t1;
    for(int i=0;i<t2-t1;i++){
        if(*(t1+i)<*min){
            min=t1+i;
        }
    }
    return min;
}
void sort(int *tab,int n){
int i,j;
        for(i=0;i<n;i++){
            if(*(tab+i)>*find_min_wsk(tab+i,tab+n))
                swap(tab+i,find_min_wsk(tab+i,tab+n));       
        }   
return;
}
