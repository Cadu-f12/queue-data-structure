#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "../queue.h"

typedef struct Queue_ {
    int tail;
    int size;
    int *queue;
} Queue;

void pre_menu() { // erro que não processo a função
    system("clear");
    printf("Criando fila de tamanho 10 na memória...\n");
    system("sleep 1.5 && clear");
}

void main_menu(int *input) {
    char cli[] = "[1] Enqueue\n[2] Dequeue\n[3] Front\n[4] Display\n[0] Sair e liberar memória\n";

    while(*input != 1 && *input != 2 && *input != 3 && *input != 4 && *input != 0) {
        printf("%s", cli);
        printf("Escolha uma opção (int): ");
        scanf("%1d", input);
        system("clear");
    }
}

void menu_1(Queue *fila) {
    int value;
    printf("Valor a ser enfileirado (int): ");
    scanf("%d", &value);
    system("sleep 1 && clear");

    int flag = enqueue(fila, value);

    if(!flag) {
        printf("Erro na inserção do valor!\n");
        system("sleep 2 && clear");
        return;
    }

    printf("Valor inserido com sucesso!\n");
    system("sleep 1 && clear");
}

void menu_2(Queue *fila) {
    int dequeue_value;
    int flag = dequeue(fila, &dequeue_value);
    
    if(!flag) {
        printf("Erro ao retirar da fila!\n");
        system("sleep 2 && clear");
        return;
    }

    printf("Valor retirado com sucesso!\n");
    system("sleep 1");
    printf("Valor retirado: %d\n", dequeue_value);
    system("sleep 1.5 && clear");
}

void menu_3(Queue *fila) {
    int value;    
    int flag = peek(fila, &value);

    if(!flag) {
        printf("Erro ao pegar o valor!\n");
        value = 0;
        system("sleep 2 && clear");
        return;
    }

    printf("Valor pego: %d\n", value);
    system("sleep 1.5 && clear");
}

void menu_4(Queue *fila) {
    if(fila->tail == 0) {
        printf("[ Fila vazia ]\n");
        return;
    }
    printf("[ ");
    for(int i = 0; i < fila->tail; i++) {
        if(i == fila->tail - 1) {
            printf("%d ]\n", fila->queue[i]);
            break;
        }
        printf("%d, ", fila->queue[i]);
    }
}

void menu_0(Queue *fila) { // algum erro que duplica a saida inves de apenas sair
    printf("Liberando fila de tamanho 10 na memória...\n");
    system("sleep 1.5 && clear");
    free_queue(fila);
    
}