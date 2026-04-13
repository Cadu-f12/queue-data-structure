#include <stdio.h>

#include "../src/queue.h"

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

int main() {
    Queue *fila = create_queue(3);

    enqueue(fila, 5);

    enqueue(fila, 6);

    enqueue(fila, 7);
    
    int deleted = -1;

    dequeue(fila, &deleted);

    printf("DELETED\nexpected: 5, test: %d\n", deleted);
    printf("VALUE AT 0\nexpected: 6, test: %d\n", fila->queue[0]);
    printf("VALUE AT 1\nexpected: 7, test: %d\n", fila->queue[1]);
    printf("TAIL\nexpected: 2, test: %d\n", fila->tail);

    return 0;
}