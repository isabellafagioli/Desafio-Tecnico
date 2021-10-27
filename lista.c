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

pointer put(pointer list, int number){
    pointer new;
    new = malloc(sizeof(Node));
    // In case it didn't work
    if (new == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);  
    }
    //set data to the number asked and next to the rest of the list
    new->data = number;
    new->next = list;
    return new;
}

int get(pointer list, int pos){
    pointer aux = list;
    //move in the list until the position asked is found
    for(int i = 0; i < pos; i++){
        aux = aux->next;
    }
    return aux->data;
}

void list(pointer list){
    //the first added is right next to null
    if(list != NULL){
        //use recursion to find the first element added
        list(list->next);
        printf("%d ", list->data);
    }
}

void clear(pointer list){
    //free to clear the list
    if(list!=NULL){
        //start from the last so we don't lose the pointer to the next
        clear(list->next);
        free(list);
    }
}

}