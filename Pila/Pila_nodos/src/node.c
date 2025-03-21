#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;

// Nodo
typedef struct Node {
    Data data;
    struct Node* next;
} Node;

Node* new_node(Data d) {
    Node* nuevo = (Node*)malloc(sizeof(Node));
    if (nuevo == NULL) return NULL;
    
    nuevo->data = d;
    nuevo->next = NULL;
    return nuevo;
}

void delete_node(Node* n) {
    if (n != NULL && n->next == NULL) {
        free(n);
    }
}

void print_node(Node* n) {
    if (n == NULL) {
        printf("Nodo inválido (NULL)\n");
        return;
    }
    printf("Nodo [Dato: %d | Siguiente: %p]\n", 
           n->data, 
           (void*)n->next);
}


typedef struct {
    Node* head;
    Node* tail;
} Queue;

Queue* queue_create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) return NULL;
    
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) return;
    
    Node* nuevo = new_node(d);
    if (nuevo == NULL) return;
    
    if (q->head == NULL) {
        q->head = q->tail = nuevo;
    } else {
        q->tail->next = nuevo;
        q->tail = nuevo;
    }
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->head == NULL) return -1;
    
    Node* temp = q->head;
    Data valor = temp->data;
    
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    
    temp->next = NULL;  // Requisito para delete_node()
    delete_node(temp);
    return valor;
}

bool queue_is_empty(Queue* q) {
    return (q == NULL) ? true : (q->head == NULL);
}

Data queue_front(Queue* q) {
    if (queue_is_empty(q)) return -1;
    return q->head->data;
}

void queue_empty(Queue* q) {
    if (q == NULL) return;
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q) {
    if (q == NULL) return;
    
    queue_empty(q);
    free(q);
}