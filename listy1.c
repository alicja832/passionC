#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tnode {
char value;
struct tnode * next;
struct tnode * prev;
};
   
//dodawanie na początek listy, nieposortowanie
struct tnode *add (struct tnode *head,char val){
    struct tnode *temp=malloc(sizeof(struct tnode));
    temp->next=head;
    temp->value=val;
    if(head){
    head->prev=temp;}
return temp;
}
//val to wartosc, ktora przypiszemy

struct tnode *sortadd(struct tnode *head,char key){
    struct tnode *newelem=malloc(sizeof(struct tnode));
    if(!newelem)
        return head;
    if(head){
    newelem->value=key;
    newelem->next=NULL;
    newelem->prev=NULL;
    if(strcmp(&(head->value),&key)>0){
        head->prev=newelem;
        newelem->next=head;
        newelem->prev=NULL;
        head=newelem;
    }
    else{
        struct tnode *tmp=head;
        for(;tmp->next && (strcmp(&(tmp->next->value),&key)<0);tmp=tmp->next);
        newelem->next=tmp->next;
        newelem->prev=tmp;
        tmp->next=newelem;
        newelem->next->prev=newelem;
        }
   }
    else{
    newelem->next=head;
    newelem->value=key;
    head=newelem;}
return head;
}
//wypisywanie
void prints(struct tnode *elem, char kier){
struct tnode *print=NULL;
if(kier=='n'){
printf("zgodnie z next\n");
for(;elem;elem=elem->next){
    printf("prev[ %p ]",elem->prev);
    printf("[ %p ]",elem);
    printf(" (%c)-> ",elem->value);
    printf("next[ %p ]\n",elem->next);
    print=elem;
}
printf("NULL\n");
}
else{
printf("zgodnie z prev\n");
printf("\n");
for(;elem;elem=elem->next)
print=elem;
for(;print;print=print->prev){
    printf("prev[ %p ]",print->prev);
    printf("[ %p ]",print);
    printf(" (%c)-> ",print->value);
    printf("next[ %p ]\n",print->next);
}
}


return;
}

//zwalnianie
void frees(struct tnode *elem){
struct tnode *pomoc;
while(elem){
    pomoc=elem->next;
    free(elem);
    elem=pomoc;
}
return;
}

//usuwanie elementu znalezionego
struct tnode *usun(struct tnode *elem,char key){
    struct tnode *jeden=elem;
    struct tnode *dwa=NULL;//pomocniczy
for (;jeden;  jeden=jeden->next){
if(jeden->value == key){
if(!dwa){
    elem=elem->next;
    free(jeden);
    elem->prev=NULL;
    jeden=elem;
    printf(" jeden value %c",jeden->value);
    //dwa sie w ogole nie zmienil, czyli początkowy musiał być keyem
    }
else{
    dwa->next=jeden->next;
    dwa->next->prev=dwa;
    free(jeden);
    jeden=dwa;
    }
}
}
return elem;
}
// szukanie

struct tnode *search(struct tnode *elem,char key){
    while(elem && elem->value != key)
        elem=elem->next;
return elem;}
//to ma sens dla jednokierunkowej

struct tnode *odwrot(struct tnode *head){
    struct tnode *cur=head;
    struct tnode *prev=NULL;
    struct tnode *next=NULL;
   
    while(cur){
         next=cur->next;//idziemy do konca listy
         cur->next = prev;//ustawiamy nexta w strukturze na wsk wskazujący na poprzednią
         prev=cur;//ustatwiamy na aktualną aby pozniej zmienic
         cur=next;//idziemy do konca listy
        }
return prev;
}

int main(){
struct tnode *head;
head= NULL;
head=sortadd(head,'z');
head=sortadd(head,'c');
head=sortadd(head,'a');
head=sortadd(head,'a');
head=sortadd(head,'f');
head=sortadd(head,'t');
head=sortadd(head,'a');
head=sortadd(head,'f');
char kier;
printf("podaj kierunek n lub p\n");
scanf("%c",&kier);
prints(head,kier);
char ch;
printf("podaj key ");
scanf(" %c",&ch);
head=usun(head,ch);
printf("\n");
prints(head,ch);
printf("\n");

frees(head);
return 0;

}
