prog1.exe: BSTw.o BSTf.o
	gcc -o BST.exe BSTf.o BSTw.o -Wall
file2.o: BSTf.c bst.h
	gcc -c -g BSTf.c -Wall
prog2.o: BSTw.c bst.h
	gcc -c -g BSTw.c -Wall
