#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (void){
    Linkedlist *L = Linkedlist_create();

    Linkedlist_addfirst(L, 5);
    Linkedlist_addfirst(L, 6);
    Linkedlist_addfirst(L, 9);
    Linkedlist_addfirst(L, 6);
    Linkedlist_print(L);
    //Linkedlist_addlast (L, 5);
   // Linkedlist_addlast (L, 4);
    //Linkedlist_addlast(L, 2);
   // Linkedlist_addlast (L, 10);
   // Linkedlist_print(L);

    return 0;
}