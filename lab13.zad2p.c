#include <stdio.h>
#include <stdlib.h>
void print_bin(FILE *p){
 fseek(p,0,SEEK_END);
    int k;
    k=ftell(p)/4;

    int *ch=malloc(k*sizeof(int));
    fseek(p,0,SEEK_SET);
    fread(ch,sizeof(int),k,p);
    for(int i=0;i<k;i++)
        printf("%d",ch[i]);
printf("\n");
free(ch);
}
void print_txt(char *file_name){
    FILE *p2=fopen(file_name,"r");
    fseek(p2,0,SEEK_END);
    int k;
    k=ftell(p2);

    char *kl=malloc((k+1)*sizeof(char));
    fseek(p2,0,SEEK_SET);
    fread(kl,sizeof(char),k,p2);
printf(" txt :%s",kl);
fseek(p2,0,SEEK_SET);
fclose(p2);
free(kl);
    
}
int main(){
FILE *p=fopen("test1.bin","rb+");
FILE *p1=fopen("test2.bin","rb");
print_txt("tablica1.txt");
print_bin(p);
print_bin(p1);
    
fclose(p);
fclose(p1);
return 0;

}
