#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return NULL;
    s->top = NULL;
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s == NULL) return;
    
    Node *nuevo = new_node(d);
    if (nuevo == NULL) return;
    
    nuevo->next = s->top;
    s->top = nuevo;
}

Data stack_pop(Stack* s) {
    if (s == NULL || s->top == NULL) return -1;
    
    Node *temp = s->top;
    Data valor = temp->data;
    s->top = s->top->next;
    
    temp->next = NULL;  // Necesario para delete_node()
    delete_node(temp);
    return valor;
}

bool stack_is_empty(Stack* s) {
    return (s == NULL) ? true : (s->top == NULL);
}

void stack_empty(Stack* s) {
    if (s == NULL) return;
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
}

void stack_delete(Stack *s) {
    if (s == NULL) return;
    
    stack_empty(s);
    free(s);
}

void stack_print(Stack *s) {
    if (s == NULL) {
        printf("Pila inválida (NULL)\n");
        return;
    }
    
    if (stack_is_empty(s)) {
        printf("Pila vacía\n");
        return;
    }
    
    printf("Elementos (tope primero): ");
    Node *actual = s->top;
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->next;
    }
    printf("\n");
}