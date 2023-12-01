#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;            
    struct Node* next;  
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

Node* search(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current; 
        }
        current = current->next;
    }
    return NULL; 
}

int main() {
  
    Node* head = NULL;

    
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 1);

  
    printf("Lista: ");
    printList(head);


    int target = 7;
    Node* result = search(head, target);

    if (result != NULL) {
        printf("Elemento %d encontrado na lista.\n", target);
    } else {
        printf("Elemento %d não encontrado na lista.\n", target);
    }

 
    freeList(head);

    return 0;
}
