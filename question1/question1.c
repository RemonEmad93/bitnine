#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        ADD,
        SUB,
        MUL,
        DIV
    } type;
    union {
        int value;
        struct {
            struct Node *arg1;
            struct Node *arg2;
        } operation;
    } data;
} Node;

Node* makeFunc(enum TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    return newNode;
}

Node* makeValue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = -1; 
    newNode->data.value = value;
    return newNode;
}

void calc(Node* node) {
    if (node == NULL) return;

    switch (node->type) {
        case ADD:
            node->data.value = node->data.operation.arg1->data.value +
                               node->data.operation.arg2->data.value;
            printf("add : %d\n", node->data.value);
            break;
        case SUB:
            node->data.value = node->data.operation.arg1->data.value -
                               node->data.operation.arg2->data.value;
            printf("sub : %d\n", node->data.value);
            break;
        case MUL:
            node->data.value = node->data.operation.arg1->data.value *
                               node->data.operation.arg2->data.value;
            printf("mul : %d\n", node->data.value);
            break;
        case DIV:
            node->data.value = node->data.operation.arg1->data.value /
                               node->data.operation.arg2->data.value;
            printf("div : %d\n", node->data.value);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int fibonacci(int n) {
    if (n <= 1) {
    return n;
  } else {
    int fib_n_1 = fibonacci(n - 1);
    int fib_n_2 = fibonacci(n - 2);
    return fib_n_1 + fib_n_2;
  }
}

int main() {
    Node* add = makeFunc(ADD);
    add->data.operation.arg1 = makeValue(10);
    add->data.operation.arg2 = makeValue(6);

    Node* mul = makeFunc(MUL);
    mul->data.operation.arg1 = makeValue(5);
    mul->data.operation.arg2 = makeValue(4);

    Node* sub = makeFunc(SUB);
    sub->data.operation.arg1 = add;
    sub->data.operation.arg2 = mul;

    calc(add);
    calc(mul);
    calc(sub);

    int fiboValue = fibonacci(sub->data.value);
    Node* fibo = makeValue(fiboValue);
    printf("fibo : %d\n", fiboValue);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
