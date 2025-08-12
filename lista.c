#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//struct que cria os elementos do primeiro nó da lista
typedef struct _simplenode{
    int valor;
    struct _simplenode *next;

}SimpleNode;
//structu que cria a celula cabeça da lista.
typedef struct _linkedlist{ 
    SimpleNode *begin;
    SimpleNode *end;
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
    L->begin =NULL;
    L->end = NULL;

    return L;

 }
 bool Linkedlist_isempty( const Linkedlist *L){

    return (L->begin == NULL && L->end ==NULL);

 }
// procedimento que vai ligar as duas funções de cima e fazer a celula cabeça apontar pro nó da lista q eu criei na outra função.
 void Linkedlist_addfirst(Linkedlist *L, int val){
   //cria o nó
    SimpleNode *p = SimpleNode_create(val);
  //o ponteiro desse no criado vai apontar pra onde o comeco da lista aponta
    p->next = L->begin;
    //a lista ta vazia?
    if (Linkedlist_isempty(L)){
        L->end = p;
    }
    //e o começo da lista agora vai apontar pro no que eu criei
    L->begin = p;
 }
 void Linkedlist_addlast_slow(Linkedlist *L, int val){

     SimpleNode *aux = SimpleNode_create(val);

    //se a lista estiver vazia.
    if (Linkedlist_isempty(L)){
        L->begin = aux;
        
    }else {
        //comando de repetição que vai fazer o aux perocorrer até o final da lista pra encontrar o nó que aponta pra null. 
        SimpleNode *p = L->begin;
       while (p->next !=NULL){
      p = p ->next; 
      } 

    p->next = aux; 
  }

 }

 void Linkedlist_addlast(Linkedlist *L, int val){
    SimpleNode *q = SimpleNode_create(val);
  
    //vai fazer os meus dois ponteiros iniciais aponterem pro valor do ultimo nó. nesse if se a lista tiver vazia
    if (Linkedlist_isempty(L)){
        L->begin = q;
        L->end = q;

    }else {
        //vai fazer o meu end apontar pro ultimo ponteiro, ou seja, oq aponta pro null e anexar o nó q nele.
        L->end->next = q;
        //depois de anexar o q no end, vai fazer o end apontar pro null de novo, pq ele conitnua apontando pro ultimo no antes da incersão do q, mas como q passou a ser o ultimo
        //é necessario fazer essa atualização.
        L->end = L->end->next;
    }
 }

 void Linkedlist_print (const Linkedlist *L){
    SimpleNode *p = L->begin;

    //enquanto p nao chegou no fim da lista ele vai imprimir
    while (p != NULL){
        printf ("%d-> ", p->valor);
        p = p->next;
        
    }
      printf ("NULL");
      printf ("\n");
 }
 //procedimento pra remover no começo da lista.
 void Linkedlist_remove(Linkedlist *L, int val){
  if (!Linkedlist_isempty(L)){
  //caso 1 o elemento estar na cabeça da lista!
   if (L->begin->valor == val){
    //crio uma variavel aleatoria pra ter acesso no segundo nó da lista.
        SimpleNode *pos = L->begin;
        if (L->begin == L->end){
          L->end == NULL;
        }
        //faço a minha cabeça da lista apontar pro próximo no da lista.
        L->begin =  L->begin->next;
        
       
        //apago o segundo nó dando um free nele
        free(pos);
     }
      else{
       
       SimpleNode *pos = L->begin->next;
       SimpleNode *prev = L->begin;
       //lista estiver diferente do valor apontado por pos e o pos não estiver nulo
       //avance os ponteiros auxiliares para os proximos elementos da lista
       while (pos->valor != val && pos !=NULL){
         //ponteiro prev vai apontar pra onde pos ta apontando
         prev = pos;
         //ou eu simplesmente posso fazer
         //prev = prev->next; (Ja que o prex next é o mesmo valor que ele o atual pos está apontando. entao da basicamente na mesma)
         //ponteiro pos vai apontar pra onde o laço next está apontando
         pos = pos->next;
        } 
        //se o valor desejado foi encontrado:
         if (pos !=NULL){
          //ponteiro next de prev vai receber o ponteiro pos next 
          prev->next = pos->next;

          if (pos->next == NULL){
            L->end = prev;
          }
          //e o ponteiro pos pode ser removido
          free(pos); 
        }
      }
    }
 }


 


