#ifndef LISTA_H
#define LISTA_H

typedef struct _simplenode SimpleNode;
typedef struct _linkedlist Linkedlist;

SimpleNode *SimpleNode_create(int val);
Linkedlist *Linkedlist_create();
void Linkedlist_addfirst(Linkedlist *L, int val);
void Linkedlist_addlast(Linkedlist *L, int val);
void Linkedlist_print (const Linkedlist *L);

 

#endif