#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(Data d) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) return NULL;
    
    n->data = d;
    n->next = NULL;
    return n;
}

void delete_node(Node* n) {
    if (n != NULL && n->next == NULL) {
        free(n);
    }
}

void print_node(Node* n) {
    if (n == NULL) {
        printf("Nodo inválido (NULL)\n");
    } else {
        printf("Nodo [Dato: %d | Siguiente: %p]\n", n->data, (void*)n->next);
    }
}