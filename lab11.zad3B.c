#include <stdio.h>
#include <stdlib.h>
struct tnode {
  char value;
  struct tnode * next;
}; 
void wypisz(struct tnode *head){
	printf("head ");
	for(;head;head=head->next){
		printf("['%c']->",head->value);
		}
	printf(" NULL ");
	return;
}
struct tnode *add_end(struct tnode *head , int  val){
	struct tnode *temp = malloc(sizeof(struct tnode));
		temp ->value = val;
		temp ->next = NULL;
		if (head){
			struct tnode *ele = head;
			while(ele ->next)
				ele=ele ->next;
				ele ->next=temp;
		} 				
		else
			head = temp;
	
return  head;
}
struct tnode *usun2(struct tnode *head, char key){
	struct tnode *nowy=NULL;
	struct tnode *jeden=head;
	struct tnode *dwa=NULL;
    struct tnode *tmp=NULL;
	char b=key-32;
	for(;jeden;dwa=jeden,jeden=jeden->next){
		if((jeden->value==key) || (jeden->value==b)){
            printf("segmentation");
			if(!nowy){
			nowy=jeden;
			nowy->next=NULL;
            tmp=nowy;
			printf("tu");
			}
			else{
			printf("tu");
            nowy=jeden;
			nowy->next=tmp;
            tmp=nowy;
			}
			
			if(!dwa){
				head = head ->next; 
				jeden=head;
					 
			}
			else{
			dwa ->next = jeden ->next;
			jeden=dwa;
			}
		}
	}
return nowy;
}
struct tnode *usun(struct tnode *head, char key){
	struct tnode *jeden=head;
	struct tnode *dwa=NULL;
	char b=key-32;
	printf("%c",b);
	for(;jeden;dwa=jeden,jeden=jeden->next){
		if((jeden->value==key) || (jeden->value==b)){ 
			if(!dwa){
			head = head ->next; 
			//free(jeden);
			jeden=head; 
			}
			else{
			dwa ->next = jeden ->next;
			free(jeden);
			jeden=dwa;
			}
		}
	}
return head;
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
	struct tnode *head=NULL;//'a', 'c', 'v', 'f', 't' 
	head=add_end(head,'a');
	head=add_end(head,'t');
	head=add_end(head,'o');
	head=add_end(head,'k');
	head=add_end(head,' ');
	head=add_end(head,'a');
	head=add_end(head,'m');
	head=add_end(head,' ');
	head=add_end(head,'a');
	head=add_end(head,'l');
	head=add_end(head,'A');
	

wypisz(head);
//head=usun(head,'a');
//wypisz(head);
struct tnode *new=NULL;
new=usun2(head,'a');
wypisz(head);
printf("\n");
wypisz(new);
frees(head);

return 0;
}
