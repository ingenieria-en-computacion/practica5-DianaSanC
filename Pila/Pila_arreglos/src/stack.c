#include <stdio.h>
#include <stdlib.h>

#define TAM 100
typedef int Data;

typedef struct {
    Data data[TAM];
    int top;     // -1 = pila vacía
} Stack;

// Crea una pila vacía
Stack stack_create() {
    Stack s;
    s.top = -1;
    return s;
}

// Inserta un elemento en el tope
void stack_push(Stack* s, Data d) {
    if (s == NULL || s->top == TAM - 1) return;  // Pila llena o inválida
    s->top++;
    s->data[s->top] = d;
}

// Elimina y devuelve el elemento del tope
Data stack_pop(Stack* s) {
    if (s == NULL || s->top == -1) return -1;    // Valor de error
    
    Data valor = s->data[s->top];
    s->top--;
    return valor;
}

// Verifica si la pila está vacía
int stack_is_empty(Stack* s) {
    if (s == NULL) return -1;    // Error
    return (s->top == -1) ? 1 : 0;
}

// Vacía la pila
void stack_empty(Stack* s) {
    if (s != NULL) {
        s->top = -1;
    }
}

// Imprime los elementos de la pila
void stack_print(Stack* s) {
    if (s == NULL) {
        printf("Pila inválida (NULL)\n");
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
