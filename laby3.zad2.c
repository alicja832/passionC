#include <stdio.h>
#include <stdlib.h>
int main(){
float arg1[]={0.4,2.3,2.4,6.1,12.3};
float arg2[]={2.4,3.3,4.67,9.7};
float *result;
result=malloc(20*sizeof(float));
float *t=result;
float *p=arg1,*s=arg2;
float *p2=arg1+sizeof(arg1)/sizeof(float),*p3=arg2+sizeof(arg2)/sizeof(float);
while(p<p2 || s<p3){
    if(s>=p3){
    *result=*p;
    p++;
    }
else if(p>=p2){
    *result=*s;
    s++;
    }
else{
    if(*p<*s)
    {
    *result=*p;
    p++;
    }
    else if(*s<*p)
    {
    *result=*s;
    s++;
    }
    else{
    *result=*p;
    p++;
    }
    }
result++;
}
//result=t;
for(result=t;(*result)!=0;result++){
if(*result==*(result-1))
*result=*(result+1);
}
result=t;
while(*result!=0){
printf("%4f \n",*result);
result++;
}
return 0;
}
