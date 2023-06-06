#include <stdio.h>
 char *c[] = {
     "ENTER",
     "NEW",
     "POINT",
     "FIRST"
 };
  char **cp[] = {  c+3, c+2, c+1, c };
  char ***cpp = cp;
 int main(void)
 {
     printf("%s", **++cpp );
     printf("%s ", *--*++cpp+3 );
    printf("%s", *cpp[-2]+3 );
    printf("%s\n", cpp[-1][-1]+1 );
    return(0);
 }
int A[3];
char NAP[4][5] = {"nap1", "nap2","nap3"};
double T[][2] = {{1.0,1.0},{0.},{2.0,3.0}};


