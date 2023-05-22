#include <stdio.h>
#include <stdlib.h>

//Fazer método de ordem, pré-ordem, fazer método que destrói a árvore a partir da raiz, fazer CRUD (Create, Read, Update[não rola], Delete), opcional: balanceamento, cálculo de altura

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL; 
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void ler_em_ordem(Node* root) {
    if (root != NULL) {
        ler_em_ordem(root->left);
        printf("%d ", root->data);
        ler_em_ordem(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15); 
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);
    root = insert(root, 20);
    root = insert(root, 6);
    
    printf("Árvore binária em ordem: ");
    ler_em_ordem(root);
    printf("\n");

    int numberToFind = 7;
    if (search(root, numberToFind)) {
        printf("%d encontrado na árvore.\n", numberToFind);
    } else {
        printf("%d não encontrado na árvore.\n", numberToFind);
    }

    return 0;
}