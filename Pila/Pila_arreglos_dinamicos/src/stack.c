#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack stack_create(int len) {
    Stack s;
    s.data = (Data*)malloc(len * sizeof(Data));
    if (s.data == NULL) {
        s.top = -1; // Indica creación fallida
    } else {
        s.top = -1; // Pila vacía
    }
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s == NULL || s->data == NULL) return;
    // Nota: No se puede verificar si está llena por falta de campo de capacidad
    s->top++;
    s->data[s->top] = d;
}

Data stack_pop(Stack* s) {
    if (s == NULL || s->data == NULL || s->top == -1) return -1;
    Data valor = s->data[s->top];
    s->top--;
    return valor;
}

bool stack_is_empty(Stack* s) {
    return (s == NULL || s->data == NULL) ? true : (s->top == -1);
}

void stack_delete(Stack *s) {
    if (s != NULL) {
        free(s->data);
        s->data = NULL;
        s->top = -1;
    }
}

void stack_empty(Stack* s) {
    if (s != NULL) {
        s->top = -1;
    }
}

void stack_print(Stack *s) {
    if (s == NULL || s->data == NULL) {
        printf("Pila inválida\n");
        return;
    }
    
    if (s->top == -1) {
        printf("Pila vacía\n");
        return;
    }
    
    printf("Elementos (tope primero): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}