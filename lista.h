#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>



typedef struct _simplenode SimpleNode;
typedef struct _linkedlist Linkedlist;

SimpleNode *SimpleNode_create(int val);
Linkedlist *Linkedlist_create();
void Linkedlist_addfirst(Linkedlist *L, int val);
void Linkedlist_addlast(Linkedlist *L, int val);
void Linkedlist_print (const Linkedlist *L);
bool Linkedlist_isempty( const Linkedlist *L);
void Linkedlist_remove (Linkedlist *L, int val);


#endif