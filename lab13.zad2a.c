#include <stdio.h>
int main(){
char tab[]="2,4,6,7,8,9,10";
int tab2[]={2,4,5,6};
FILE *fo=fopen("test1.bin","wb");
FILE *ff=fopen("test2.bin","wb");

    fwrite(tab,sizeof(char),7,fo);
    fwrite(tab2,sizeof(int),3,ff);

//funkcja memmove


fclose(fo);
fclose(ff);

return 0;
}
