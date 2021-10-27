#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;  
} Node;

typedef struct Node * pointer;

pointer initialize_list(){
    return NULL;
}

pointer put(pinter list, int number){
    pointer new;
    new = malloc(sizeof(Node));
    if (new == NULL) {
           printf("Memoria insuficiente.\n");
           exit(1);  
        }
    new->data = number;
    new->next = list;
    return new;
}