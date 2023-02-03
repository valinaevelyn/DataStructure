#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node* next;
};

Node* top = NULL;

Node* createNode(int value){
    struct Node* new_nodes = (Node*)malloc(sizeof(Node));
    new_nodes->value = value;
    new_nodes->next = NULL;

    return new_nodes;
}

// masuk top, keluar top

void insert(int value){
    Node* temp = createNode(value);

    if(!top){
        top = temp;
    }else{
        temp->next = top;
        top = temp;
    }
}

void deletes(){
    if(!top){
        return;
    }else{
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

void printStack(){
    Node* iter = top;
    while(iter){
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

int main(){
    insert(1);
    insert(6);
    insert(3);
    insert(2);
    insert(5);
    insert(4);
    printStack();
    deletes();
    printStack();
}
