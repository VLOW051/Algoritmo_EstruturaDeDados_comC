#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 100
#define MAX_TOKEN 20

typedef struct {
    double items[MAX_STACK];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_STACK - 1;
}

void push(Stack *s, double value) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

double pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

double eval_rpn(char *tokens[], int n) {
    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        char *token = tokens[i];
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atof(token));
        } else if (strlen(token) == 1) {
            double b = pop(&s);
            double a = pop(&s);
            switch (token[0]) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                default:
                    printf("Operador inválido: %s\n", token);
                    exit(1);
            }
        } else {
            printf("Token inválido: %s\n", token);
            exit(1);
        }
    }
    return pop(&s);
}

int main() {
    char entrada[256];
    char *tokens[MAX_STACK];
    int n = 0;

    printf("Digite a expressão em notação polonesa reversa (RPN), separando por espaço (ex: 5 3 + 2 *):\n");
    printf("Operadores válidos: + - * /\n");
    printf("Exemplo: Para (5 + 3) * 2, digite: 5 3 + 2 *\n");
    printf("Expressão: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        printf("Erro na leitura da entrada.\n");
        return 1;
    }

    // Quebra a entrada em tokens
    char *token = strtok(entrada, " \n");
    while (token != NULL && n < MAX_STACK) {
        tokens[n++] = token;
        token = strtok(NULL, " \n");
    }

    if (n == 0) {
        printf("Nenhum valor informado.\n");
        return 1;
    }

    double resultado = eval_rpn(tokens, n);
    printf("Resultado: %.2f\n", resultado);
    return 0;
}