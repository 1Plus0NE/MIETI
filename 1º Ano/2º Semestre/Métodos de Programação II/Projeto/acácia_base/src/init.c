#include <stdio.h>
#include <string.h>
#include "../includes/structs.h"


/* Função que inicializa a nossa estrutura de dados */
MERCEARIA init(ARTIGO artigos [],int number){
    MERCEARIA merc;
    merc.number  = number;
    for (int i = 0; i < strlen(artigos); i++)
    {
        merc.artigos[i] = artigos[i];
    }

    return merc;
}

ARTIGO cria_artigo(char nome [],float preco){
    ARTIGO art;
    strcpy( art.nome, nome);
    art.preco = preco;
    return art;
}

