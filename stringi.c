#include <string.h>
#include <stdio.h>
#define con(s) #s
unsigned int str1(char *s){
    char *p=s;
    while(*s++);
    return s-p;
}
unsigned int str2(char *s){
    char *p=s;
    while(*s) s++;
    return s-p;
}
int main(){
    char str[]="ja mam 10 kotow\0 i 0 zab";//16
    printf(con(str1 to)"%u\n",str1(str));
    printf(con(str2 to) "%u\n",str2(str));//15
    char strr[]="Ala ma 0 kotow \0 i 2 psy";
     printf(con(str1 to)"%u\n",str1(strr));//17
    printf(con(str2 to) "%u\n",str2(strr));//16
    printf(con(strlen to)"%d\n",strlen(strr));//16
    printf(con(rozm to)"%d\n",sizeof(strr));//26
    return 0;
}
