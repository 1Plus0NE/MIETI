#include "../includes/structs.h"
void produto2str(ARTIGO a){
    printf("\n\n------------- Descrição de artigo: -------------\n");
    printf(" Nome : ");
	for (int i = 0; a.nome[i]!='\0'; i++)
    {
        printf("%c",a.nome[i]);
    }
    printf("\n Preço : %.2f$",a.preco);
}

void mercearia2str(MERCEARIA m){
    printf("\n\n------------- Artigos disponíveis na mercearia: -------------\n\n ");
	for (int i = 0; i<m.number; i++)
    {
        produto2str(m.artigos[i]);
    }
    printf("\n\n--------------------------------------------------------------\n\n");
}