#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tnode{
//char *s=malloc(10*sizeof(char));
char s[];
int l;
struct tnode *next;
};
struct tnode *add(struct tnode *head,char *value){
    struct tnode *elem=malloc(sizeof(struct tnode));
    strcpy(elem->s,value);
    elem->l=1;
    elem->next=NULL;
    if(head){
        if(strcmp(value,head->s)<0){
            elem->next=head;
            head=elem; 
            return head; 
        }
        else if(strcmp(value,head->s)==0){
            head->l=head->l+1;
            free(elem); 
            return head;   
        }
        else{
        
            struct tnode *tmp=head;
            for(;tmp->next && (strcmp(value,tmp->next->s) < 0); tmp=tmp->next);

            if( (tmp->next) && (strcmp(value,tmp->next->s) == 0)  ){
            free(elem);
            tmp->next->l=tmp->next->l+1;
            return head;
            }
            else {
            printf("jest ");
            elem->next=tmp->next;
            tmp->next=elem;
            return head;
            }
        
        }
    }
    else
    head=elem;
//printf("%p\n",head);
return head;
}
void wypisz(struct tnode *head){
        while(head){
            printf("[%s]-> %d ",head->s,head->l);
            head=head->next;
        }
return;
}
void fres(struct tnode *head){
    struct tnode *tmp;
    while(head){
    tmp=head->next;
    free(head);
    head=tmp;
}
return;
}

int main(){
    struct tnode *head=NULL;
    FILE *fp=fopen("myfile.txt","r");
    FILE *fpp=fopen("wyjscie.txt","w");
    if(fp){
    char *sk=malloc(4*sizeof(char));
    
   while(fscanf(fp,"%s",sk)!=EOF){
            fprintf(fpp, "%s" ,sk);
            fprintf(fpp, "%c\n",":");
            head=add(head,sk);
           //wypisz(head);

        }
    fclose(fp);
    }  
printf("\n");
wypisz(head);
fres(head); 
free(sk);
return 0;
}

