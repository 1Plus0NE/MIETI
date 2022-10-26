#include <stdlib.h>

typedef struct Tarefa{

    int identificador_tarefa;
    char nome_tarefa[30];
    char estado_tarefa[20];
    char descricao_tarefa[300];
    char tipo_tarefa[20];
    char subtipo_tarefa[20];
    char prioridade[20];
    int data_inicio_dd;
    int data_inicio_mm;
    int data_inicio_aa;
    int data_fim_dd;
    int data_fim_mm;
    int data_fim_aa;
    int hora_inicio_h;
    int hora_inicio_min;
    int hora_fim_h;
    int hora_fim_min;
    //char colaborador[20];
    char participantes[50][50];
    int partN;

}tarefa;
/*
typedef struct linked{

    char functionTask[20];
    char nameUser[20];

}LINKED;

typedef struct link{

    LINKED linked;
    struct link *prox;

}LINK;
*/