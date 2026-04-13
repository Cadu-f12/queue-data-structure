#include <stdlib.h>
#include <stdio.h>

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

int is_full(Queue *queue) {
    if(!queue) {
        printf("Queue is NULL");
        return 0;
    }

    if(queue->size == queue->tail) {
        return 1;
    } else {
        return 0;
    }
}

int is_empty(Queue *queue) {
    if(!queue) {
        printf("Queue is NULL");
        return 0;
    }

    if(queue->tail == 0) {
        return 1;
    }
}

Queue* create_queue() {
    Queue *queue = malloc(sizeof(Queue));
    
    if(queue == NULL) {
        printf("The queue isnt allocated");
        return queue;
    }
    
    int length = 3;

    queue->size = length;
    
    queue->tail = 0;
    
    queue->queue = malloc(sizeof(int) * length);
    queue->queue--;
}

int enqueue(Queue* queue, int value) {
    printf("1");
}

int dequeue(Queue* queue, int* value) {
    printf("1");
}

int peek(Queue* queue, int* value) {
    printf("1");
}

void free_queue(Queue* queue) {
    if(!queue) {
        printf("Queue is NULL");
        return;
    }

    free(queue);
}