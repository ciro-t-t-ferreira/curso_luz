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

Node* procura_ponteiro(Node* root, int data) {
    if (root == NULL) {
        printf("Valor não pertenca à Árvore");
        return NULL; //Não faz tanto sentido retorna NULL, o ideal seria a função não retornar nada ou retornar um erro
    } else if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        return procura_ponteiro(root->left, data);
    } else {
        return procura_ponteiro(root->right, data);
    }
}

int n_filhos(Node* root, int data){
    int filhos = 0;
    Node* node = procura_ponteiro(root, data);
    if (node->left != NULL){
        filhos++;
    }
    if (node->right != NULL){
        filhos++;
    }
    return filhos;
}

int contem(Node* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data <= root->data) {
        return contem(root->left, data);
    } else {
        return contem(root->right, data);
    }
}

void ler_em_ordem(Node* root) {
    if (root != NULL) {
        ler_em_ordem(root->left);
        printf("%d ", root->data);
        ler_em_ordem(root->right);
    }
}

void pre_ordem(Node* root){
    if (root != NULL){
        printf("%d ", root->data);
        pre_ordem(root->left);
        pre_ordem(root->right);
    }
}

void pos_ordem(Node* root){
    if (root != NULL){
        pos_ordem(root->left);
        pos_ordem(root->right);
        printf("%d ", root->data);
    }
}

Node* deleta_arvore(Node* root){//ideia: fazer a função imprimir automaticamente "Árvore apagada" no fim da execução
    
    if (root == NULL){
        return NULL; //Acho que não teria que fazer essa operação já que o ponteiro já é NULL
    }
    
    deleta_arvore(root->left);
    deleta_arvore(root->right);
   
    free(root);
    return NULL; 
}

void deleta_node(Node* root, int data){ //EM CONSTRUÇÃO
    Node* ponteiro_a_deletar = procura_ponteiro(root, data);
    
    if (n_filhos(root, ponteiro_a_deletar->data) == 0){
        free(ponteiro_a_deletar);
        ponteiro_a_deletar = NULL;
    }

    else if (n_filhos(root, ponteiro_a_deletar->data) == 1){
        if(ponteiro_a_deletar->left == NULL){
            Node* temp = ponteiro_a_deletar;
            ponteiro_a_deletar->right = temp;
            free(ponteiro_a_deletar);
            ponteiro_a_deletar = NULL;
        }
        else if(ponteiro_a_deletar->right == NULL){
            Node* temp = ponteiro_a_deletar;
            ponteiro_a_deletar->left = temp;
            free(ponteiro_a_deletar);
            ponteiro_a_deletar = NULL;
        }
    }
    else{
        printf("Tem dois filhos, não fiz ainda, volte mais tarde");
    }
}

void verifica_existencia(Node* root){ //DÚVIDA: esse método checa apenas a existência do root, mas não me garante que não sobraram nós na memória
    if (root == NULL){
        printf("Árvore não existe\n");
    }
    else{
        printf("Árvore existe\n");
    }
}


int main() {
    
    // Cria Árvore
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15); 
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);
    root = insert(root, 3);
    root = insert(root, 13);
   
    // Imprime ordens
    printf("Árvore binária em ordem: ");
    ler_em_ordem(root);
    printf("\n");
    printf("Árvore binária em pré-ordem: ");
    pre_ordem(root);
    printf("\n");
    printf("Árvore binária em pós-ordem: ");
    pos_ordem(root);
    printf("\n\n");

    // Procura valor na árvore
    int numberToFind = 7;
    if (contem(root, numberToFind)) {
        printf("%d encontrado na árvore.\n", numberToFind);
    } else {
        printf("%d não encontrado na árvore.\n\n", numberToFind);
    }

    //Exclui alguns nós
    deleta_node(root, 3);
    printf("Árvore binária em ordem pós exclusão do 3: ");
    ler_em_ordem(root);
    deleta_node(root, 12);
    printf("Árvore binária em ordem pós exclusão do 12: ");
    ler_em_ordem(root);

    //Exclui árvore
    root = deleta_arvore(root);
    verifica_existencia(root);

    return 0;
}