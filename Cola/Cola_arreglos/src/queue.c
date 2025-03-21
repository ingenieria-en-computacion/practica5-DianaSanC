#include "queue.h"
#include <stdlib.h>

Queue queue_create() {
    Queue q;
    q.head = -1;
    q.tail = -1;
    q.len = 0;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL || q->len == TAM) return;
    
    if (q->len == 0) {
        q->head = 0;
        q->tail = 0;
    } else {
        q->tail = (q->tail + 1) % TAM;
    }
    
    q->datos[q->tail] = d;
    q->len++;
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->len == 0) return -1;
    
    Data valor = q->datos[q->head];
    q->len--;
    
    if (q->len == 0) {
        q->head = -1;
        q->tail = -1;
    } else {
        q->head = (q->head + 1) % TAM;
    }
    
    return valor;
}

bool queue_is_empty(Queue* q) {
    return (q == NULL) ? true : (q->len == 0);
}

Data queue_front(Queue* q) {
    if (q == NULL || q->len == 0) return -1;
    return q->datos[q->head];
}

void queue_empty(Queue* q) {
    if (q == NULL) return;
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}

void queue_delete(Queue* q) {
    // No se necesita liberar memoria
}