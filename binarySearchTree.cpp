#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* createNode(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->left = temp->right = NULL;

    return temp;
}

Node* insertNode(Node* curr, Node* node){
    if(curr == NULL){
        return node;
    }else if(node->value < curr->value){
        curr->left = insertNode(curr->left, node);
    }else if(node->value > curr->value){
        curr->right = insertNode(curr->right, node);
    }

    return curr;
}

void inOrder(Node* curr){
    if(curr == NULL){
        return;
    }

    inOrder(curr->left);
    printf("%d ", curr->value);
    inOrder(curr->right);
}

void preOrder(Node* curr){
    if(curr == NULL){
        return;
    }

    printf("%d ", curr->value);
    preOrder(curr->left);
    preOrder(curr->right);
}

void postOrder(Node* curr){
    if(curr == NULL){
        return;
    }

    postOrder(curr->left);
    postOrder(curr->right);
    printf("%d ", curr->value);
}

Node* deleteNode(Node* curr, int value){
    if(curr == NULL){
        return curr;
    }else if(value < curr->value){
        curr->left = deleteNode(curr->left, value);
    }else if(value > curr->value){
        curr->right = deleteNode(curr->right, value);
    }else{
        if(!curr->left && !curr->right){
            free(curr);
            curr = NULL;
        }else if(!curr->left){
            Node* temp = curr;
            curr = curr->right;
            free(temp);
            curr = NULL;
        }else if(!curr->right){
            Node* temp = curr;
            curr = curr->left;
            free(temp);
            curr = NULL;
        }else{
            // Predecessor
            Node* temp = curr->left;
            while(temp->right){
                temp = temp->right;
            }

            temp->value = curr->value;
            curr->left = deleteNode(curr->left, value);

            // Successor
            // Node* temp = curr->right;
            // while(temp->left){
            //     temp = temp->left;
            // }

            // temp->value = curr->value;
            // curr->right = deleteNode(curr->right, value);
        }
    }

    return curr;
}

Node* popAll(Node* curr){
    if(curr == NULL){
        return curr;
    }

    popAll(curr->left);
    popAll(curr->right);
    free(curr);
    curr = NULL;

}

int main(){
    root = insertNode(root, createNode(10));
    insertNode(root, createNode(5));
    insertNode(root, createNode(15));
    insertNode(root, createNode(3));
    insertNode(root, createNode(7));
    insertNode(root, createNode(12));
    insertNode(root, createNode(17));

    printf("Pre Order: ");
    preOrder(root);
    printf("\n");

    printf("In Order: ");
    inOrder(root);
    printf("\n");

    printf("Post Order: ");
    postOrder(root);
    printf("\n");

    root = deleteNode(root, 10);
    printf("In Order: ");
    inOrder(root);
    printf("\n");

    deleteNode(root, 5);
    printf("In Order: ");
    inOrder(root);

    popAll(root);

}