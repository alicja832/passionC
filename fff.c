#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trig{
    double (*f1)(double);
    char nazwa[4];
    struct trig *next;
};
void dodaj(struct trig **head, char *m, double(*f)(double)){
    struct trig *elem=malloc(sizeof(struct trig));
    elem->f1=f;
    strcpy(elem->nazwa,m);
    elem->next=NULL;
    if(!(*head)){
        *head=elem;
        return;
    }
    if(strcmp(m,(*head)->nazwa)<0){
        elem->next=*head;
        *head=elem;
        return;
    }
    struct trig *tmp=*head;
    while(tmp->next && strcmp(m,tmp->next->nazwa)>0)
        tmp=tmp->next;
    elem->next=tmp->next;
    tmp->next=elem;
    return;


}
void wypisz(struct trig *head, double kat){
    while(head){
        printf("%s(%lf)=%lf\n",head->nazwa,kat,(head->f1)(kat));
        head=head->next;
    }
}
void zwolnij(struct trig **head){
    struct trig *tmp=*head;
    while(*head){
        tmp=(*head)->next;
        free(*head);
        *head=tmp;
    }
}
int main(){
    struct trig *head=NULL;
    char funname[][4]={"sin","cos","tan"};
    double (*funwsk[3])(double)={sin,cos,tan};
    int i;
    for(i=0;i<3;i++){
        dodaj(&head,funname[i],funwsk[i]);
    }
    double deg_val=0;
    while(deg_val<90)
        wypisz(head,(deg_val)+=30);
    zwolnij(&head);
    return 0;
}
