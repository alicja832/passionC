#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CZY(a,b) (a) > (b) ? (1) : (0)
#include "bst.h"
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
struct tnode{
    int key;
    struct tnode *left, *right, *parent;

};
//dodawanie lisci do listy
struct tnode *add1 (struct tnode *head, int k){
    struct tnode *tmp=malloc(sizeof(struct tnode));
    tmp->key=k;
    tmp->left=NULL;
    tmp->right=NULL;
    if(!head){
        tmp->parent=NULL;
    }
    else{
        tmp->parent=head;
        
    }
        
return tmp;
}
//dodawanie elementów, rekurencja
void add2(struct tnode **tree,struct tnode *parent,int x){
    if(*tree){
        if(CZY((*tree)->key,x)){
            add2( &( (*tree)->left ),*tree ,x);
        }
        else{
            add2(&( (*tree)->right ),*tree ,x);
        }
    }
    else{
            *tree=add1(parent,x);
    }
}
void print(struct tnode *tree){
    if(tree->left)
        print(tree->left);
    printf(" %d ",tree->key);
    if(tree->right)
        print(tree->right);

}
//zwalnianie
void fre(struct tnode *tree){
    if(tree){
        struct tnode *tmpl,*tmpr;
        tmpl=tree->left;
        tmpr=tree->right;
        free(tree);
        fre(tmpl);
        fre(tmpr);
    }

}
//search
int search(struct tnode *tree,int x){
    static int i=0;
if(tree){
   i= i+1;
    if(tree->key==x){
        return i;
    }
    else if(CZY(tree->key,x)){
        search(tree->left,x);
    }
    else if(CZY(x,tree->key)){
        search(tree->right,x);
    }
}
else{
return 0;
} 
}
//funkcja patrzaca czy nie ma takiego samego elementu w tablicy
int find(int *tab,int rozm,int wart){
int i,r=1;
for(i=0;i<rozm;i++){
    if(tab[i]==wart)
        r=0;
    }
return r;
}
int max(struct tnode *tree){
static int i=0;
i++;
    if(tree)
    max(tree->right);
return i;
}
int min(struct tnode *tree){
static int i=0;
i++;
    if(tree)
    min(tree->left);
return i;}
//funkcja wyszukująca najdłuższą drogę
int level(struct tnode *tree){
int l,r;
l=min(tree);
r=max(tree);
if (l>r)
    return l;
else
    return r;


}

