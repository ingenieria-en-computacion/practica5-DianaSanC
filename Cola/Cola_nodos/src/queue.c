#include "queue.h"
#include <stdlib.h>

Queue* queue_create() {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) return NULL;
    
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) return;
    
    Node *nuevo = new_node(d);
    if (nuevo == NULL) return;
    
    if (q->head == NULL) {
        q->head = q->tail = nuevo;
    } else {
        q->tail->next = nuevo;
        q->tail = nuevo;
    }
}

Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) return -1;
    
    Node *temp = q->head;
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