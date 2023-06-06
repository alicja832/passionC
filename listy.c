#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
		printf(" %p [%c]-> ",head,head->a);
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


struct lista1 *add2(struct lista1 *head1, char key){
	struct lista1 *tmp=malloc(sizeof(struct lista));
	tmp->a=key;
	tmp->next=head1;
return tmp;
}

struct lista1 *usuw2(struct lista *head,char key){
	struct lista1 *nowy=NULL;
    struct lista1 *nowy1=NULL;
	struct lista *curr=head;
	struct lista *pre=NULL;
    struct lista *tmp=curr;
	for(;curr;pre=curr,curr=tmp->next){
		if(curr->a == key){
            tmp=curr;
            if(!nowy){
               nowy=(struct lista1*)curr;
               nowy->next=NULL;
                nowy1=nowy;   
                }
            else{
                 nowy=(struct lista1*)curr;
                 nowy->next=nowy1;
                 nowy1=nowy;
                }

			if(!pre){
				head=head->next;
				curr=head;
			}
			else{
				pre->next=curr->next;
				pre->next->prev=pre;
				wypisz(head);
				printf("\n");
				curr=pre;
			}
		}
	}
return nowy;
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
int main(){
int a=4;
struct lista *head;
head=add(NULL,'c');
head=add(head,'A');
head=add(head,'a');
head=add(head,'x');
head=add(head,'a');
wypisz(head);
printf("\n");
struct lista1 *head1=usuw2(head,'a');
printf("nowa \n");
wypisz2(head1);
printf("dwuk ");
wypisz(head);
fres(head);

return 0;
}
