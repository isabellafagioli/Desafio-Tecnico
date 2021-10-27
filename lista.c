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

int count_elements(pointer list){
    pointer aux = list;
    int counter = 0;
    while(aux != NULL){
        counter++;
        aux = aux->next;
    }
    return counter;
}

int get(pointer list, int pos){
    pointer aux = list;
    int pos = count_elements(list) - pos; 
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

int fisrt(pointer list){
    if(list != NULL){
        //use recursion to find the first element added
        if(list->next == NULL){
            return list->data;
            printf("%d ", list->data);
        }
        return list(list->next);
    }
    return NULL;
}

pointer remove(pointer list, int pos){
    int element = get(list, pos);
    printf("%d", element);
    pointer aux_list = list; //just to clear (avoid memory leak)
    ponter new_list = initialize_list();
    while(list != NULL){
        if(list->data != element){
            new_list = put(new_list, list->data);
        }
        if(list->data == element){
            list = list->next;
        }
        list->next;
    }
    clear(aux_list);
    return new_list;
}
int last(pointer list){
    return list->data;
}

void read_entry(char *entry, pointer list) {

    if(entry[0] == 'p'){
        int number = entry[4] - '0'; //supposing the example that has only numers of one digit
        put(list, number);
    }
    if(entry[0] == 'g'){
        int pos = entry[4] - '0'; //supposing the example that has only numers of one digit
        int number = get(list, pos);
        printf("%d", number);
    }
    if(entry[0] == 'l' && entry[1] == 'i'){
        list(list);
    }
    if(entry[0] == 'r'){
        int pos = entry[7] - '0'; //supposing the example that has only numers of one digit
        int number = remove(list, pos);
        list(list);
    }
    if(entry[0] == 'c'){
       clear(list);
    }
    if(entry[0] == 'f'){
        int number = first(list);
        printf("%d", number);
    }
    if(entry[0] == 'l' && entry[1] == 'a'){
        int number = last(list);
        printf("%d", number);
    }	
}

int main(int argc, char *argv[]) {
	char input[201];
    pointer list = initialize_list();

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		read_entry(input, list);
	}

	return EXIT_SUCCESS;
}