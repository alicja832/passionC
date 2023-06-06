//bardziej ładniej
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_txt ( char *nazwa );

void print_bin ( FILE *p );

void swap_file (FILE *p, FILE *r);

void przepis_bin (FILE *p, FILE *r);

void swap_file1 (FILE *p, FILE *r);

void przepis_txt(FILE *fp,FILE *ff);


int main(){

FILE *p1, *p2;

p1=fopen("test1.bin","rb+");
p2=fopen("test2.bin","rb+");
char *nazwa="tablica1.txt";
char *nazwa2="tablica2.txt";


if(!p1){

    printf("cannot open file");
    exit(1);

}
if(!p2){

    printf("cannot open file");
    exit(1);

}

print_bin ( p1 );
print_bin (p2);

printf("\n");
rewind(p1);
rewind(p2);
swap_file(p1,p2);

print_bin ( p1 );
print_bin (p2);

fclose(p1);
fclose(p2);
printf("\n");
//pliki tekstowe
print_txt(nazwa);
print_txt(nazwa2);
FILE *p3=fopen(nazwa,"r+");
FILE *p4=fopen(nazwa2,"r+");
fseek(p3,0,SEEK_SET);
fseek(p4,0,SEEK_SET);
//printf("\n");
swap_file1(p3,p4);
print_txt(nazwa);
print_txt(nazwa2);
fclose(p3);
fclose(p4);
return 0;
}

void print_bin (FILE *p){

rewind(p);
int ch;
while((ch=fgetc(p))!=EOF){
    printf("%d",ch);

}
printf("\n");
rewind(p);


}
void print_txt ( char *nazwa){
char c;
FILE *fp=fopen(nazwa,"r");

char b[5];
sscanf(b,fp);

if(!fp){
printf("cannot open");
exit(1);
}

while((c=fgetc(fp))!= EOF){
printf("%c",c);
}
printf("\n");

fclose(fp);

}
void przepis_bin(FILE *fp,FILE *ff){
int c;
rewind(fp);
rewind(ff);
while((c=fgetc(fp))!=EOF){

fputc(c,ff);
}
rewind(fp);
rewind(ff);


}

void przepis_txt(FILE *fp,FILE *ff){
char c;
fseek(fp,0,SEEK_SET);
fseek(fp,0,SEEK_SET);
while((c=fgetc(fp))!=EOF){

fputc(c,ff);
}


}
void swap_file(FILE *p,FILE *r){
FILE *f=fopen("test3.bin","wb+");
    if(!f){
        printf("nie udało sie");
        exit(1);
    }
przepis_bin(r,f);
//print_bin(f);
przepis_bin(p,r);
rewind(f);
przepis_bin(f,p);
fclose(f);
}
void swap_file1(FILE *p,FILE *r){
FILE *f=fopen("tablica3.txt","w+");
    if(!f){
        printf("nie udało sie");
        exit(1);
    }
przepis_txt(r,f);
//print_bin(f);
przepis_txt(p,r);
przepis_txt(f,p);
fclose(f);
}


