#include <stdio.h>
#include <stdlib.h>
struct tnode {
char value;
struct tnode * next;
struct tnode * prev;
};
struct tnode *add (struct tnode *head,struct tnode *tail,char val){
    struct tnode *temp=malloc(sizeof(struct tnode));
    temp->next=head;
    temp->value=val;
    head->prev=temp;
return temp;

}//val to wartosc, ktora przypiszemy
void prints(struct tnode *elem){
for(;elem;elem=elem->next){
    printf(" %p ",elem->next);
    printf(" %c ",elem->value);
}
return;
}
void frees(struct tnode *elem){
while(elem){
    free(elem);
    elem=elem->next;
}
return;
}
struct tnode *search(struct tnode *elem,char key){
    while(elem && elem->value != key)
        elem=elem->next;
return elem;}
int main(){
struct tnode *head;
head= NULL;
struct tnode *tail=NULL;
head=add(head,'a');
//prints(head);
char ch;
printf("podaj key ");
scanf(" %c",&ch);
head=search(head,ch);
printf("%c",head->value);
//frees(head);
free(head);
return 0;

}
