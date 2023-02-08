#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 97

struct Node{
    int key;
    char string[100];
    Node* next;
};

struct HashTable{
    int dataCount = 0;
    Node* head;
    Node* tail;
};

Node* createNode(int key, char string[]){
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->string, string);
    temp->key = key;
    temp->next = NULL;

    return temp;
}

HashTable hashTable[MAX];

int hashFunction(char string[]){
    int total = 0;
    for(int i = 0; i < strlen(string); i++){
        total += string[i];
    }

    int hasilHash = total % MAX;

    return hasilHash;
}

void insert(char string[]){
    int key = hashFunction(string);
    Node* temp = createNode(key, string);

    if(hashTable[temp->key].head == NULL){
        hashTable[temp->key].head = hashTable[temp->key].tail = temp;
    }else{
        hashTable[temp->key].tail->next = temp;
        hashTable[temp->key].tail = temp;
    }

    hashTable[temp->key].dataCount++;
}

void searching(char string[]){
    int key = hashFunction(string);

    if(hashTable[key].dataCount == 0){
        return;
    }else{
        Node* iter = hashTable[key].head;
        while(iter){
            if(strcmp(iter->string, string) == 0){
                printf("%s is founded in key %d.\n", string, key);
                return;
            }

            iter = iter->next;
        }
    }
}

void deleteNode(char string[]){
    int key = hashFunction(string);

    if(hashTable[key].dataCount == 0){
        printf("Data is not found.\n");
        return;
    }else{
        if(!hashTable[key].head->next){
            free(hashTable[key].head);
            hashTable[key].head = NULL;
            printf("Data has been deleted in 1.");
        }else if(strcmp(hashTable[key].head->string, string) == 0){
            Node* temp = hashTable[key].head;
            hashTable[key].head = hashTable[key].head->next;
            temp->next = NULL;
            free(temp);
            printf("Data has been deleted in 2.");
        }else{
            Node* temp = hashTable[key].head;
            while(temp->next && strcmp(temp->next->string, string) != 0){
                temp = temp->next;
            }

            Node* iter = temp->next;
            temp->next = temp->next->next;
            iter->next = NULL;
            free(iter);
            printf("Data has been deleted in 3.");
        }
    }
}

Node* printHashTable(){
    for(int i = 0; i < MAX; i++){
        printf("%d: ", i);
        Node* iter = hashTable[i].head;

        if(!iter){
            printf("(null)");
        }

        while(iter){
            printf("%s ", iter->string);
            iter = iter->next;
        }
        printf("\n");
    }
}

int main(){
    insert("Aline");
    insert("Dokyeom");
    insert("Yugyeom");
    insert("Bambam");
    insert("Mark");
    insert("Joshua");

    printHashTable();
    printf("\n");

    searching("Aline");
    printf("\n");
    searching("Bambam");
    printf("\n");

    deleteNode("Aline");
    printf("\n");
    printHashTable();
    deleteNode("Dokyeom");
    printf("\n");
    printHashTable();

    printf("\n");

    return 0;
}