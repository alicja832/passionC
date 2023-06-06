#include <stdio.h>
struct s1{
    unsigned int a;
    unsigned int b;
}s;
struct s2{
    unsigned int b1:2;
    unsigned int   :4;
    unsigned int b2:3;
}ss;
int main(){
    printf("jeden %ld\n",sizeof(struct s1));
    printf("dwa %ld",sizeof(ss));
    ss.b1=5;
    ss.b2=5;
    printf("wart a1 %u, wart a2 %u\n",ss.b1,ss.b2);
    return 0;
}
