#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura y funciones para la pila
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(capacity * sizeof(char));
    return stack;
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->array[stack->top--];
}

// Estructura y funciones para la cola
struct Queue {
    int front, rear, size;
    unsigned capacity;
    char* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (char*)malloc(capacity * sizeof(char));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, char item) {
    if (queue->size == queue->capacity) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

char dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) return '\0';
    char item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Función para verificar palíndromo
int isPalindrome(const char* str) {
    int len = strlen(str);
    struct Stack* stack = createStack(len);
    struct Queue* queue = createQueue(len);

    for (int i = 0; str[i] != '\0'; i++) {
        push(stack, str[i]);
        enqueue(queue, str[i]);
    }

    while (!isStackEmpty(stack) && !isQueueEmpty(queue)) {
        char s = pop(stack);
        char q = dequeue(queue);
        if (s != q) {
            free(stack->array);
            free(stack);
            free(queue->array);
            free(queue);
            return 0;
        }
    }

    free(stack->array);
    free(stack);
    free(queue->array);
    free(queue);
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <archivo.txt>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Eliminar salto de línea
        if (isPalindrome(line)) {
            printf("Es palindromo: %s\n", line);
        } else {
            printf("No es palindromo: %s\n", line);
        }
    }

    fclose(file);
    return 0;
}