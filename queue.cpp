#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node* next;
};

struct Queue{
    Node* front;
    Node* rear;
};

Node* createNode(int value){
    struct Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

Queue* createQueue(){
    struct Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

void enqueue(Queue* q, int value){
    struct Node* temp = createNode(value);

    if(q->rear == NULL){
        q->front = q->rear = temp;
    }else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

void dequeue(Queue* q){
    if(q->front == NULL){
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);
}

void printQueue(Queue* q){
    Node* iter = q->front;
    while(iter){
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

int main(){
    Queue* q = createQueue();
    enqueue(q, 1);
    printQueue(q);
    enqueue(q, 2);
    printQueue(q);
    enqueue(q, 3);
    printQueue(q);
    enqueue(q, 4);
    printQueue(q);
    enqueue(q, 5);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    return 0;
}