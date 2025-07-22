#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (void){
    Linkedlist *L = Linkedlist_create();
    Linkedlist_addfirst (L, 5);
    Linkedlist_addfirst (L, 4);
    Linkedlist_addfirst (L, 2);
    Linkedlist_addfirst (L, 10);
    Linkedlist_print (L);

    return 0;
}