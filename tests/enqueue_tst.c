#include <stdio.h>

#include "../src/queue.h"

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

int main() {
    Queue *fila = create_queue(2);

    enqueue(fila, 2);

    printf("TAIL\nexpected: 1, test: %d\n", fila->tail);
    printf("ADDRES POINTER\nexpected: 0, test: %p\n", fila->queue);
    printf("VALUE\nexpected: 2, test: %d\n", fila->queue[fila->tail - 1]);

    enqueue(fila, 6);

    printf("TAIL\nexpected: 2, test: %d\n", fila->tail);
    printf("ADDRES POINTER\nexpected: 0, test: %p\n", fila->queue);
    printf("VALUE\nexpected: 6, test: %d\n", fila->queue[fila->tail - 1]);

    enqueue(fila, 99);

    printf("TAIL\nexpected: 2, test: %d\n", fila->tail);
    printf("ADDRES POINTER\nexpected: 0, test: %p\n", fila->queue);
    printf("VALUE\nexpected: 6, test: %d\n", fila->queue[fila->tail - 1]);

    return 0;
}