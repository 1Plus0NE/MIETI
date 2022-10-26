#include <stdlib.h>

typedef struct user{

    int identificador_user;
    char nome_user[50];
    int idade_user;
    char genero_user[10];
    char morada_user[50];
    char email_user[50];
    char tlm_user[20];
    char tipo_user[50];
    
}USER;

typedef struct no{

    USER user;
    struct no *prox;

}NO;