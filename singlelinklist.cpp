#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* HEAD = NULL;
struct Node* TAIL = NULL;

Node* createNode(int value){
    struct Node* new_nodes = (struct Node*)malloc(sizeof(struct Node));
    new_nodes->value = value;
    new_nodes->next = NULL;

    return new_nodes;
}

void pushHead(int value){
    struct Node* temp = createNode(value);

    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        temp->next = HEAD;
        HEAD = temp;
    }
}

void pushTail(int value){
    struct Node* temp = createNode(value);

    if(!HEAD){
        HEAD = TAIL = temp;
    }else{
        TAIL->next = temp;
        TAIL = temp;
    }
}

void popHead(){
    if(!HEAD){
        return;
    }else if(HEAD == TAIL){
        HEAD = TAIL = NULL;
    }else{
        Node* temp = HEAD->next;
        free(HEAD);
        HEAD = temp;
    }
}

void popTail(){
    if(!HEAD){
        return;
    }else if(HEAD == TAIL){
        HEAD = TAIL = NULL;
    }else{
        Node* temp = HEAD;
        while(temp->next != TAIL){
            temp = temp->next;
        }
        free(TAIL);
        temp->next = NULL;
        TAIL = temp;
    }
}

void printList(){
    struct Node* iter = HEAD;
    while(iter){
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

int main(){
    pushHead(5);
    pushHead(4);
    pushTail(10);
    pushTail(11);
    printList();
    popHead();
    printList();
    popTail();
    printList();
}