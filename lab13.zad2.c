#include <stdio.h>
int main(){
int tab[]={2,4,6,7,8,9,10};
int tab2[]={2,4,5,6};
FILE *fo=fopen("test1.dat","w");
FILE *ff=fopen("test2.dat","w");

    fwrite(tab,sizeof(int),4,fo);
    fwrite(tab2,sizeof(int),3,ff);



fclose(fo);
fclose(ff);

return 0;
}
