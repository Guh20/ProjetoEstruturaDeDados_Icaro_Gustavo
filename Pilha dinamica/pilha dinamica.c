#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Erro: Falha na alocação de memória para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória para o nó da pilha.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int searchRecursive(Node* current, int target) {
    if (current == NULL) {
        return 0; 
    }
    if (current->data == target) {
        return 1; 
    }
    return searchRecursive(current->next, target);
}

int search(Stack* stack, int target) {
    return searchRecursive(stack->top, target);
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return;
    }
    Node* current = stack->top;
    printf("Elementos da pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    display(stack);

    int target = 20;
    if (search(stack, target)) {
        printf("O elemento %d está na pilha.\n", target);
    } else {
        printf("O elemento %d não está na pilha.\n", target);
    }

    printf("Desempilhando um elemento: %d\n", pop(stack));

    display(stack);

    free(stack);

    return 0;
}