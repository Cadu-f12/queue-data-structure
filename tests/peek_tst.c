#include <stdio.h>

#include "../src/queue.h"

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

int main() {
    Queue *fila = create_queue(3);
    int picked;

    enqueue(fila, 8);
    enqueue(fila, 9);
    enqueue(fila, 10);

    printf("CODE RUNS?\nyes = 1 / no = 0: %d\n", peek(fila, &picked));
    printf("PICKED VALUE\nexpected: 10, picked: %d\n", picked);

    free_queue(fila);
    return 0;
}