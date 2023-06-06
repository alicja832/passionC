#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    char s;
    struct lista *next;
    struct lista *prev;
};

struct lista *sortadd (struct lista *head, char value){
    
    struct lista *elem=malloc(sizeof(struct lista));
    elem->s=value;
    elem->next=NULL;
    elem->prev=NULL;
    if(head){
        if(strcmp(&(value),&(head->s))<0){
            head->prev=elem;
            elem->next=head;
            head=elem;
                    
        }
        else{
        
            struct lista *tmp;
            for(;tmp->next && (strcmp(&(value),&(tmp->next->s)) < 0); tmp=tmp->next);
            elem->next=tmp->next;
            tmp->next=elem;
            elem->prev=tmp;
        }

    }
    else
    head=elem;

return head;
}

void wypisz(struct lista *head, int n){
printf("HEAD ");
if(n==1){
        while(head){
            printf("[%c]->",head->s);
            head=head->next;
        }
    }
else{
    struct lista *tmp;
    for(;head;head=head->next) tmp=head;
    while(tmp){
        printf("[%c]->",tmp->s);
        tmp=tmp->prev;
        }
    }
printf(" NULL");
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

struct lista *jednosc(struct lista **h1, struct lista **h2){
    struct lista *head2=NULL;
    struct lista *h=NULL;
    if(!(*h1)) {
        h= *h2; 
        *h2=(*h2)->next;
        return h;
    }
    if(!(*h2)){ 
        h= *h1; 
        *h1=(*h1)->next;
        return h;
    }
    else{
        if(strcmp(&((*h1)->s),&((*h2)->s))<0){
            head2=*h1;
            *h1=(*h1)->next;
            head2->next=jednosc(h1,h2); 
        }
        else{
            head2=*h2;
            *h2=(*h2)->next;
            head2->next=jednosc(h1,h2);
        }
    }
return head2;
}

int main(){
    struct lista *head=NULL;
    head=sortadd(head,'z');
    head=sortadd(head,'c');
    //head=sortadd(head,'f');
    wypisz(head,1);
    printf("\n");
    wypisz(head,0);
    printf("\n");
    printf("head2");
    struct lista *head2=NULL;
    head2=sortadd(head2,'d');
    head2=sortadd(head2,'a');
    wypisz(head2,1);
    printf("\n");
    printf("\n");
    struct lista *head3=NULL;
    head3=jednosc(&head,&head2);
    wypisz(head3,1);
    printf("\n");
     printf("Pierwsza ");
    wypisz(head,1);
    printf("\n");
     printf("Druga ");
    wypisz(head2,1);
    fres(head3);
    //fres(head2);
return 0;
}



