#include <stdio.h>
#include <stdlib.h>
struct lista{
    char a;
    struct lista *next;
    struct lista *prev;
};
void wypisz(struct lista *head){
    while(head){
        printf(" [%c]-> ",head->a);
        head=head->next;
}
return;
}
struct lista1{
    char a;
    struct lista1 *next;
};
void wypisz1(struct lista1 *head){
    while(head){
        printf(" [%c]-> ",head->a);
        head=head->next;
}
return;
}
void add(struct lista **head,char b){
    struct lista *tmp=malloc(sizeof(struct lista));
    tmp->a=b;
    tmp->next=*head;
    tmp->prev=NULL;
    if(*head){
    (*head)->prev=tmp;}
*head=tmp;
return;
}
void fres(struct lista *head){
    struct lista *tmp;
    while(head){
    tmp=head->next;
    free(head);
    head=tmp;
}
return;
}
struct lista1 *usuw(struct lista *head, char s){
    struct lista *tmp1=head;
    struct lista *tmp2=NULL;
    struct lista *tmp3=NULL;
    struct lista1 *nowa=NULL;
    struct lista1 *ntmp=NULL;
    for(;tmp1;tmp2=tmp1,tmp1=tmp1->next){
    if(tmp1->a==s){
    
        if(!tmp2){
        nowa=(struct lista1*)head;
        nowa->next=NULL;
        ntmp=nowa;
        head=tmp1->next;
        tmp1=head;
    }
    else{
        tmp2->next=tmp1->next;
        tmp3=tmp1->next;
        tmp1->next->prev=tmp2;
        if(!nowa){
        nowa=(struct lista1*)tmp1;
        nowa->next=NULL;
        ntmp=nowa;
        }
        else{
        nowa=(struct lista1*)tmp1;
        nowa->next=ntmp;
        ntmp=nowa;
        }
        tmp1=tmp3;
       }
    }
}
return nowa;
}

        
        
        
    
    
int main(){
struct lista *head=NULL;
add(&head,'z');
add(&head,'a');
add(&head,'s');
add(&head,'a');
//struct lista1 *head1=NULL;
//head1=usuw(head,'a');
wypisz(head);
//wypisz1(head1);
//fres(head);
return 0;}

