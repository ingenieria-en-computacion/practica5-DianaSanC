#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isBalanced(const char* expr) {
    int len = strlen(expr);
    struct Stack* stack = createStack(len);
    int balanced = 1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(stack, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(stack)) {
                balanced = 0;
                break;
            }
            char top = pop(stack);
            if (!isMatchingPair(top, c)) {
                balanced = 0;
                break;
            }
        }
    }

    if (!isEmpty(stack)) {
        balanced = 0;
    }

    free(stack->array);
    free(stack);
    return balanced;
}

int main() {
    char expr[1024];
    printf("Ingrese la expresion: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Eliminar salto de línea

    if (isBalanced(expr)) {
        printf("La expresion esta equilibrada.\n");
    } else {
        printf("La expresion NO esta equilibrada.\n");
    }

    return 0;
}