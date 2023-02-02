#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int value){
    struct Node* new_nodes = (Node*)malloc(sizeof(Node));
    new_nodes->value = value;
    new_nodes->next = NULL;
    new_nodes->prev = NULL;
    return new_nodes;
}

void pushHead(int value){
    struct Node* temp = createNode(value);
    if(!head){
        head = tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushTail(int value){
    struct Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(int value){
    struct Node *temp = createNode(value);

    if(!head){
        head = tail = temp;
    }else{
        if(value < head->value){
            pushHead(value);
        }else if(value >= tail->value){
            pushTail(value);
        }else{
            Node* curr = head;
            while(curr->value <= value){
                curr = curr->next;
            }

            temp->next = curr;
            temp->prev = curr->prev;
            curr->prev->next = temp;
            curr->prev = temp;

        }
    }
}

void popHead(){
    if(!head){
        return;
    }else if(head == tail){
        head = tail = NULL;
    }else{
        Node* iter = head->next;
        iter->prev = NULL;
        free(head);
        head = iter;
    }
}

void popTail(){
    if(!head){
        return;
    }else if(head == tail){
        head = tail = NULL;
    }else{
        Node* iter = tail->prev;
        iter->next = NULL;
        free(tail);
        tail = iter;
    }
}

void popValue(int x){
    if(!head){
        return;
    }else if(head == tail){
        head = tail = NULL;
    }else{
        Node* iter = head;
        while(iter->value != x){
            iter = iter->next;
        }

        if(iter == head){
            popHead();
        }else if(iter == tail){
            popTail();
        }else{
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            free(iter);
        }

    }
}

void printList(){
    Node* iter = head;
    while(iter){
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

int main(){
    pushHead(10);
    pushHead(20);
    pushMid(15);
    pushTail(30);
    pushTail(40);
    pushMid(25);
    pushMid(35);
    
    printList();

    popHead();
    printList();
    popTail();
    printList();
    popValue(25);
    printList();
    popValue(35);
    printList();
}