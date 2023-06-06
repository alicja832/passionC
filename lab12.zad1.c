#include <stdio.h>
#include <stdlib.h>
struct tnode {
  int value;
  struct tnode * next;  
}; 
void add_front (struct tnode **head,int val){
	struct tnode *tmp=malloc(sizeof(struct tnode));
	tmp->value=val;
	tmp->next=*head;
	
	*head=tmp;
	return;
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
int spr1(struct tnode **L_1, struct tnode *L_2){
int a=0;
struct tnode *tmp1=*L_1;
//struct tnode *tmp2=*L_2;
		for(;L_2;L_2=L_2->next){
			tmp1=*L_1;
			for(;tmp1;tmp1=tmp1->next)
				if(tmp1==L_2) a=1;
		}
return a;
}	
		
int main(){
int k;
struct tnode *L_1=NULL;
struct tnode *L_2=NULL;
while(k<20){
	scanf("%d",&k);
	if(k!=0){
	if(k%2 == 0){
	add_front(&L_1,k);
	}
	else{
	add_front(&L_2,k);
	}
	}
	else{
	add_front(&L_1,k);//niewazne do ktorej dodamy i tak beda razem
	L_2=L_1;
	}
	
	
	
}
wypisz(L_1);
wypisz(L_2);
//sprawdzanie
int spr=spr1(&L_1,L_2);
if(spr==1) printf("jest");
else printf("nie ma");

frees(L_2);

return 0;
}
	
