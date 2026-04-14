#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "./view/cli.h"

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

int main() {
    pre_menu();

    Queue *fila = create_queue(10);

    int stop = 1;
    while(stop) {
        int user = -1;

        main_menu(&user);
        
        switch (user) {
            case 1:
                menu_1(fila);
                break;
            case 2:
                menu_2(fila);
                break;
            case 3:
                menu_3(fila);
                break;
            case 4:
                menu_4(fila);
                break;
            case 0:
                menu_0(fila);
                stop = 0;
                break;
        }
    }

    return 0;
}