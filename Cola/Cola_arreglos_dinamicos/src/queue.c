#include "queue.h"
#include <stdlib.h>

Queue queue_create(int len) {
    Queue q;
    q.data = malloc(len * sizeof(Data));
    
    if (q.data == NULL) {
        q.head = -1;
        q.tail = -1;
        q.len = 0;
    } else {
        q.head = -1;
        q.tail = -1;
        q.len = len;  // len almacena la capacidad
    }
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL || q->data == NULL || q->len == 0) return;
    
    // Verificar si está llena (condición circular)
    if ((q->tail + 1) % q->len == q->head) return;
    
    if (q->head == -1) {
        q->head = 0;
        q->tail = 0;
    } else {
        q->tail = (q->tail + 1) % q->len;
    }
    
    q->data[q->tail] = d;
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->data == NULL || q->head == -1) return -1;
    
    Data valor = q->data[q->head];
    
    if (q->head == q->tail) {
        q->head = -1;
        q->tail = -1;
    } else {
        q->head = (q->head + 1) % q->len;
    }
    
    return valor;
}

bool queue_is_empty(Queue* q) {
    return (q == NULL || q->data == NULL) ? true : (q->head == -1);
}

Data queue_front(Queue* q) {
    if (q == NULL || q->data == NULL || q->head == -1) return -1;
    return q->data[q->head];
}

void queue_empty(Queue* q) {
    if (q == NULL) return;
    q->head = -1;
    q->tail = -1;
}

void queue_delete(Queue* q) {
    if (q == NULL) return;
    free(q->data);
    q->data = NULL;
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}