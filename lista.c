#include "lista.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct _simplenode{
    int valor;
    struct _simplenode *next;

}SimpleNode;

typedef struct _linkedlist{ 
    SimpleNode *begin;
}Linkedlist;

//vai criar o primeiro no da lista
 SimpleNode *SimpleNode_create(int val){
   SimpleNode *snode = (SimpleNode*) calloc(1 , sizeof(SimpleNode));
   snode->valor = val;
   snode->next = NULL;

   return snode;
 }
// vai criar a celula cabeça e apontar pro null.
 Linkedlist *Linkedlist_create(){

    Linkedlist *L = (Linkedlist*)calloc (1, sizeof(Linkedlist*));
    L->begin = NULL;

    return L;

 }
// procedimento que vai ligar as duas funções de cima e fazer a celula cabeça apontar pro nó da lista q eu criei na outra função.
 void Linkedlist_addfirst(Linkedlist *L, int val){
     SimpleNode *p = SimpleNode_create(val);
     p->next = L->begin;
     L->begin = p;

 }

 void Linkedlist_print (const Linkedlist *L){
    SimpleNode *p = L->begin;

    //enquanto p nao chegou no fim da lista ele vai imprimir
    while (p != NULL){
        printf ("%d-> ", p->valor);
        p = p->next;
        
    }
      printf ("NULL");
 }

