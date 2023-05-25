#include <iostream>

// Definição da classe Node para a lista ligada
class Node {
public: //public indica que o método é visível e acessável por qualquer parte do código 
    int data;
    Node* next;

    Node(int value) {//Construtor da classe (tem o mesmo nome da classe e não tem retorno)
        data = value;
        next = nullptr; //Em C++ é preferível usar nullptr do que NULL
    }
};

// Definição da classe LinkedList
class LinkedList {
private: //private indica que o método só é acessável pela classe
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Função para inserir um elemento no início da lista
    void insert(int value) {
        Node* newNode = new Node(value);
        printf("value:%d\n", value);

        if (head == nullptr) {
            head = newNode;
        } else {
            printf("head:%d\n", head->data);
            newNode->next = head;
            head = newNode;
        }
    }

    // Função para exibir os elementos da lista
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


// Definição da classe Queue (fila)
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Função para enfileirar um elemento
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Função para desenfileirar um elemento
    void dequeue() {
        if (front == nullptr) {
            std::cout << "A fila está vazia." << std::endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Função para exibir os elementos da fila
    void display() {
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Definição da classe Stack (pilha)
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Função para empilhar um elemento
    void push(int value) {
        Node* newNode = new Node(value);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    // Função para desempilhar um elemento
    void pop() {
        if (top == nullptr) {
            std::cout << "A pilha está vazia." << std::endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Função para exibir os elementos da pilha
    void display() {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    // Exemplo de uso da lista ligada
    LinkedList linkedList;
    linkedList.insert(3);
    linkedList.insert(7);
    linkedList.insert(5);
    //linkedList.display();
}
