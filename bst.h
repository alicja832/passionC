#ifndef BST_H
#define BST_H
struct tnode;
int i_rand(int min, int max);
struct tnode *add1 (struct tnode *head, int k);
void add2(struct tnode **tree,struct tnode *parent,int x);
void print(struct tnode *tree);
void fre(struct tnode *tree);
int search(struct tnode *tree,int x);
int find(int *tab,int rozm, int wart);
int max(struct tnode *tree);
int min(struct tnode *tree);
int level(struct tnode *tree);
#endif

