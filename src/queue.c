#include <stdlib.h>
#include <stdio.h>

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

int is_full(Queue *queue) {
    if(!queue) {
        printf("Queue is NULL\n");
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
        printf("Queue is NULL\n");
        return 0;
    }

    if(queue->tail == 0) {
        return 1;
    } else {
        return 0;
    }
}

Queue* create_queue(int length) {
    Queue *queue = malloc(sizeof(Queue));
    
    if(queue == NULL) {
        printf("The queue isnt allocated\n");
        return queue;
    }

    queue->size = length;
    
    queue->tail = 0;
    
    queue->queue = malloc(sizeof(int) * length);
}

int enqueue(Queue* queue, int value) {
    if(!queue) {
        printf("Queue is NULL\n");
        return 0;
    }
    if(is_full(queue)) {
        printf("Fail to input %d\n", value);
        printf("Queue is FULL\n");
        return 0;
    }
    
    queue->queue[queue->tail] = value;
    
    queue->tail++;
    return 1;
}

int dequeue(Queue* queue, int *value) {
    if(!queue) {
        printf("Queue is NULL\n");
        return 0;
    }
    if(is_empty(queue)) {
        printf("Queue is EMPTY\n");
        return 0;
    }

    *value = queue->queue[0];

    for(int i = 0; i < queue->size; i++) {
        queue->queue[i] = queue->queue[i + 1];
    }

    queue->tail--;
    return 1;
}

int peek(Queue* queue, int *value) {
    if(!queue) {
        printf("Queue is NULL\n");
        return 0;
    }
    if(is_empty(queue)) {
        printf("Queue is EMPTY\n");
        return 0;
    }

    *value = queue->queue[0]; // pergar o primeiro e não o último
    return 1;
}

void free_queue(Queue* queue) {
    if(!queue) {
        printf("Queue is NULL\n");
        return;
    }

    free(queue);
}