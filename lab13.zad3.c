#include <stdio.h>
#include <stdlib.h>
void print_bin (FILE *p){

rewind(p);
int ch;
while((ch=fgetc(p))!=EOF){
    printf("%d",ch);

}
printf("\n");
rewind(p);


}
int main(){
    FILE *p1=fopen("test1.bin","rb+");
    if(!p1){
    printf("cannot open");
    exit(-1);

} 
   print_bin(p1);
    int k,w=123;

    fseek(p1,0,SEEK_END);
    int rozm=ftell(p1);
    k=20;
    if(k<=rozm){

        fseek(p1,k,SEEK_SET);
        fputc(w,p1);
}
else{
    fputc(w,p1);
}
    printf("\n");
    print_bin(p1);

fclose(p1);
return 0;
}
