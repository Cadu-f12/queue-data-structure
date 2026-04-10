typedef struct Queue_ Queue;

Queue* create_queue();

int enqueue(Queue* queue, int value);

int dequeue(Queue* queue, int* value);

int peek(Queue* queue, int* value);

void free_queue(Queue* queue);