#include <stdio.h>
#include <stdlib.h>
struct tnode {
  int value;
  struct tnode * next;  
}; 

struct tnode *elem(struct tnode *head1,struct tnode *elem ){
 int key=elem->value;
 if(!head1) { elem->next=NULL; return elem;}
 else{
 if(head1 ->value  > key)
 {elem ->next=head1;
 head1=elem;
 return head1;}
 else{
 struct tnode *tp=head1;
 for(;tp ->next && tp ->next ->value < key;tp=tp->next);
 elem ->next=tp ->next;
 tp->next=elem;}
 }
 
return head1;
}	
void wypisz(struct tnode *head){
	printf("head ");
	for(;head;head=head->next){
		printf("['%d']->",head->value);
		}
	printf(" NULL ");
	return;
}
struct tnode *frees(struct tnode *head){
	struct tnode *pomoc=NULL;
	while(head){
	pomoc=head->next;
	free(head);
	head=pomoc;
	}
return NULL;
}		
 	
	
	
	
int main(){
struct tnode *nowy=malloc(sizeof(struct tnode));
nowy->value=7;
struct tnode *head=NULL;
head=elem(head,nowy);
struct tnode *nowy1=malloc(sizeof(struct tnode));
nowy1->value=8;
head=elem(head,nowy1);
//nowy->value=3;

wypisz(head);
frees(head);
return 0;
}

