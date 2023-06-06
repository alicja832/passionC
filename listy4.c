#include <stdio.h>
#include <stdlib.h>
struct lista{
	char a;
	struct lista *next;
	struct lista *prev;
};
struct lista *add(struct lista *head,char value){
	struct lista *tmp=malloc(sizeof(struct lista));
	tmp->a = value;
	tmp->next = head;
	if(head)
	head->prev = tmp;
return tmp;
}
void wypisz(struct lista *head){
	for(;head;head=head->next){
		printf(" prev %p [%c] next %p-> \n",head->prev,head->a,head->next);
	}
return;
}

//lista jednokierunkowa


struct lista1{
	char a;
	struct lista1 *next;
};
void wypisz2(struct lista1 *head1){
	for(;head1;head1=head1->next){
		printf("%p [%c]->",head1,head1->a);
	}
return;
}
void fres(struct lista *head){
	struct lista *pomoc;
	while(head){
	pomoc=head->next;
	free(head);
	head=pomoc;


}
return;
}

void fres1(struct lista1 *head){
    struct lista1 *tmp;
    while(head){
    tmp=head->next;
    free(head);
    head=tmp;
}
return;
}
struct lista1 *newer(struct lista *head){
struct lista *tmp=head;
int a=2;
struct lista *tmp1=NULL;
struct lista1 *head1=NULL;
struct lista1 *tmpp=NULL;
for(;tmp;tmp=tmp->next){
printf("%d\n",a);
    while(tmp->a == 'x'){
        if(tmp==head){
        tmp1=head->next;
        tmp1->prev=NULL;
        head1=(struct lista1*)head;
        head1->next=tmpp;
        tmpp=head1;
        tmp=tmp1;
        }
        else{
        printf("%d\n",a);
        tmp1=tmp->next;
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        head1=(struct lista1*)tmp;
        head1->next=tmpp;
        tmpp=head1;
        tmp=tmp1;
        }
        }
}
return head1;
}
int main(){
int a=4;
struct lista *head=NULL;
struct lista *tmp=head;
struct lista *tmp1=NULL;
head=add(head,'c');
head=add(head,'x');
head=add(head,'x');
head=add(head,'a');
head=add(head,'a');
wypisz(head);
printf("\n");
struct lista1 *head1=NULL;
struct lista1 *tmpp=NULL;
//próbujemy przechwycic coś dalej
tmp=head;
//for(;tmp;tmp=tmp->next){
//printf("%d\n",a);
  //  while(tmp->a == 'x'){
    //    if(tmp==head){
      //  tmp1=head->next;
       // tmp1->prev=NULL;
       // head1=(struct lista1*)head;
       // head1->next=tmpp;
       // tmpp=head1;
       // tmp=tmp1;
       // }
       // else{
       // printf("%d\n",a);
       // tmp1=tmp->next;
       // tmp->prev->next=tmp->next;
       // tmp->next->prev=tmp->prev;
       // head1=(struct lista1*)tmp;
       // head1->next=tmpp;
       // tmpp=head1;
       // tmp=tmp1;
       // }
       // }
//}
//wypisz2(head1);
printf("\n");
head1=newer(head);
wypisz2(head1);
printf("\n");
wypisz(head);

fres(head);
fres1(head1);

return 0;
}
