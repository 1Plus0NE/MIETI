/*

    ********************************************
    *                                          *
    *   MP2                                    *
    *   Trabalho realizado por:                *
    *                                          *
    *   Luis Ferreira A98286                   *
    *   José Fernandes A95360                  *
    *                                          *
    ********************************************

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../includes/colaboradores.h"

int age_user(int x){

    int flag=0;

    if(x<4){

        flag=1;

    }

    else if(x>100){

        flag=1;

    }

    while(flag){

        printf("\nFoi introduzido um valor invalido!");
        printf("\nIntroduza a sua idade: ");
        scanf("%d",&x);

        flag=0;

        if(x<4){

            flag=1;

        }

        else if(x>100){

            flag=1;

        }

    }

    return x;

}

char* genre_user(NO* genreList, int x){                     // Função que retorna um genero

    genreList->user.genero_user;

    while(x!=1 && x!=2 && x!=3){
                
                printf("\nFoi introduzido um valor invalido!");
                printf("\nIntroduza o seu genero: ");
                printf("\n1 - Masculino");
                printf("\n2 - Feminino");
                printf("\n3 - Outro\n\n");
                scanf("%d",&x);
                getchar();

    }

    if(x==1){

        return "Masculino";

    }

    if(x==2){

        return "Feminino";

    }

    if(x==3){

        return "Outro";

    }

}

char* tlm_user(NO* tlmList, char tlm[]){                    // Função que retorna um número de telemóvel válido

    int length, flag=0;

    length = strlen(tlm);

        if(length!=9){

            flag=1;

        }

        else if(tlm[0]=='9'){
            
            switch(tlm[1]){

                case '0':

                flag=1;
                break;

                case '4':

                flag=1;
                break;

                case '5':

                flag=1;
                break;

                case '7':

                flag=1;
                break;

                case '8':

                flag=1;
                break;

                case '9':

                flag=1;
                break;

            }

        } 

            while(flag){

                printf("\nFoi introduzido um numero de telemovel invalido!");
                printf("\nIntroduza o seu numero de telemovel: ");
                scanf("%s",tlm);

                length = strlen(tlm);

                flag=0;

                if(length!=9){

                    flag=1;

                }

                else if(tlm[0]=='9'){
                
                switch(tlm[1]){

                    case '0':

                    flag=1;
                    break;

                    case '4':

                    flag=1;
                    break;

                    case '5':

                    flag=1;
                    break;

                    case '7':

                    flag=1;
                    break;

                    case '8':

                    flag=1;
                    break;

                    case '9':

                    flag=1;
                    break;

                }

            }

        }

        return tlm;

}

char* email_user(char email[]){                             // Função que retorna um email valido

    int     i;
    char    *pos1, *pos2;
    char    *ch;

    while(1){

        for (i = 0, ch = email; *ch; *ch++){

                if (*ch == '@'){

                    pos1 = ch;  // <-stores last @ address
                    i++;

                }

            }

            pos2 = ch;          // <-stores end address ("\0") of email

        /* If there is only one "@" */
        if(i == 1){

            /* Pos1 - email <-a character must be before "@". Ch - pos1 <-Counts
             * backwards from the end of the string towards "@". A character
             * must be between "@" and "." */
            while(pos1 - email && ch - pos1 > 1){

                /* From the end of string to "." has to be atleast 2 chars */
                if((pos2 - ch) > 2 && *ch == '.'){
                    //printf("pos2 - ch is %d and *ch is %c",pos2 - ch, *ch);
                    return email;

                }

                ch--;

            }

        }

        printf("\nFoi introduzido um e-mail invalido!\nIntroduza o seu e-mail: ");
        scanf("%39s", email);
        
    } /* End while */

    return email;
}

NO* criar_User(int id){                                     // Função para criar um User

    NO* newList = (NO*)malloc(sizeof(NO));
    if(newList == NULL){

        perror("\nErro no malloc");

    }

        int genre, age, flag=0;
        char tele[9], email[30];

        newList->user.identificador_user = id;
        printf("\nID: #%04d",newList->user.identificador_user);

        getchar();
        printf("\nIntroduza o nome do utilizador: ");
        scanf("%[^\n]",newList->user.nome_user);

        printf("\nIntroduza a sua idade: ");
        scanf("%d",&age);

        newList->user.idade_user = age_user(age);

        printf("\nIntroduza o seu genero: ");
        printf("\n1 - Masculino");
        printf("\n2 - Feminino");
        printf("\n3 - Outro\n\n");
        scanf("%d",&genre);
        getchar();

        strcpy(newList->user.genero_user, genre_user(newList,genre));

        printf("\nIntroduza a sua morada: ");
        scanf("%[^\n]",newList->user.morada_user);
        
        printf("\nIntroduza o seu e-mail: ");
        scanf("%s",email);

        strcpy(newList->user.email_user, email_user(email));

        printf("\nIntroduza o seu numero de telemovel: ");
        scanf("%s",tele);
        
        strcpy(newList->user.tlm_user, tlm_user(newList, tele));

        newList->prox = NULL;
        return newList;

}

NO* add_List(NO* list, NO* element){                        // Função para adicionar um node à lista

    if(list!=NULL){

        if(strcmp(element->user.nome_user,list->user.nome_user)>0){

            list->prox = add_List(list->prox,element);

        }

        else{

            element->prox = list;
            list = element;

        }      

    }

    else{

        list = element;

    }

    return list;

}

NO* search(NO* list, char* name){                           // Função para retornar um node dado um nome de um User existente

    NO* aux = NULL;
    for(aux = list; aux!=NULL; aux = aux->prox){

        if(strcmp(aux->user.nome_user, name)==0){
            
            return aux;

        }

    }

}

void print_User(NO* list, char* name){                      // Função para printar as informações para um dado nome de um User

    NO* aux;
    aux = search(list, name);

    if(aux==NULL){

        printf("Nao foi encontrado esse utilizador!");

    }

    else{

        printf("\nID: #%04d",aux->user.identificador_user);
        printf("\nIdade: %d",aux->user.idade_user);
        printf("\nGenero: %s",&aux->user.genero_user);
        printf("\nMorada: %s",&aux->user.morada_user);
        printf("\nE-mail: %s",&aux->user.email_user);
        printf("\nTelemovel: %s",&aux->user.tlm_user);

    }

}

void list_User(NO* list){                                   // Função para listar todos os Users existentes

    NO* aux = list; // COPIA

            if(aux){ // Enquanto apontar para alguma coisa 
                
                printf("\n%s",aux->user.nome_user);
                list_User(aux->prox);

            }
 
}

NO* edit_User(NO* list, char* name){                        // Função para editar um User

    NO* aux;
    aux = search(list, name);

    int escolha, age;
    char tele[9], email[30];

    if(aux==NULL){

        printf("Nao foi encontrado esse utilizador!");

    }

    else{

        printf("\nO que pretende editar?\n\n1.Idade\n2.Morada\n3.Email\n4.Numero de Telemovel\n\n");
        scanf("%d",&escolha);

        switch(escolha){

            case 1:

            printf("\nIntroduza a sua idade: ");
            scanf("%d", &age);
            getchar();

            aux->user.idade_user = age_user(age);   
            break;

            case 2:

            getchar();
            printf("\nIntroduza a sua morada: ");
            scanf("%[^\n]", aux->user.morada_user);
            break;

            case 3:

            printf("\nIntroduza o seu e-mail: ");
            scanf("%s", email);

            strcpy(aux->user.email_user, email_user(email));
            break;

            case 4:

            printf("\nIntroduza o seu numero de telemovel: ");
            scanf("%s", tele);

            strcpy(aux->user.tlm_user, tlm_user(aux, tele));
            break;
            
        }

    }

    return list;

}

NO* delete_User(NO* list, char* name, int flag){            // Função para eliminar um User

    NO* aux = list;
    NO* ant = NULL;
  
    while(aux != NULL && strcmp(aux->user.nome_user,name)!=0){

        ant = aux;
        aux = aux->prox;

    }

    if(aux == NULL){
        
        printf("\nNao foi encontrado esse utilizador");
        return list;

    }
    
    else{

        if(ant != NULL){

            ant->prox = aux->prox;
            printf("\nUtilizador removido com sucesso!");
            return list;

        }

        else{

            if(flag){
                
                free(list);
                printf("\nUtilizador removido com sucesso!");
                return NULL;

            }

            else{

                list = aux->prox;
                free(aux);
                printf("\nUtilizador removido com sucesso!");

            }

        }

    }

}

void write_file(NO* list, int user_total){

   FILE *fich;
   fich = fopen ("Colaboradores.txt", "w");

   if(fich != NULL){

        if(list){
           
        fprintf(fich,"%d\n",user_total);

           while(list!=NULL){
            
            fprintf(fich,"%d\n",list->user.identificador_user);
            fprintf(fich,"%s\n",list->user.nome_user);
            fprintf(fich,"%d\n",list->user.idade_user);
            fprintf(fich,"%s\n",list->user.genero_user);
            fprintf(fich,"%s\n",list->user.morada_user);
            fprintf(fich,"%s\n",list->user.email_user);

            if(list->prox==NULL){

                fprintf(fich,"%s",list->user.tlm_user);

            }

            else{

                fprintf(fich,"%s\n",list->user.tlm_user);

            }

            list=list->prox;

            }

        }     

    }

    fclose(fich);

}

NO* read_file(NO* list, int* id){

    FILE* read;
    NO* aux;
    int user_total=*id;

    read = fopen("Colaboradores.txt", "r");

    if(read){

        fscanf(read,"%d",&user_total);

        while(!feof(read)){

            aux=malloc(sizeof(NO));

            fscanf(read,"%d",&aux->user.identificador_user);
            fscanf(read,"%s",aux->user.nome_user);
            fscanf(read,"%d",&aux->user.idade_user);
            fscanf(read,"%s",aux->user.genero_user);
            fscanf(read,"%s",aux->user.morada_user);
            fscanf(read,"%s",aux->user.email_user);
            fscanf(read,"%s",aux->user.tlm_user);

            aux->prox = NULL;
            list = add_List(list, aux);

        }
       
    }

    fclose(read);
    *id=user_total;
    return list;

}

int main(){
    
    NO* head = NULL;
    NO* aux = NULL;
    int menu, id=1, flag=0;
    char name[30];

    head = read_file(head,&id);

    do{

        printf("\n\nSeja bem-vindo ao Sistema de Gestao de Tarefas\nO que deseja consultar?\n\n1. Consultar Utilizador\n2. Editar Utilizadores\n3. Remover Utilizadores\n4. Criar Utilizadores\n5. Listar Utilizadores\n0. Sair\n\n");
        scanf("%d",&menu);

        switch(menu){

            case 1:

                if(head==NULL){

                    printf("\nNao existem utilizadores!");

                }

                else{

                    printf("\nIntroduza o nome do seu utilizador: ");
                    scanf("%s",name);

                    print_User(head,name);

                }
                
                break;

            case 2:

                if(head==NULL){

                    printf("\nNao existem utilizadores!");

                }

                else{

                    printf("\nIntroduza o nome do seu utilizador: ");
                    scanf("%s",name);

                    edit_User(head,name);

                }
                
                break;

            case 3:

                if(head==NULL){

                    printf("\nNao existem utilizadores!");

                }

                else{

                    printf("\nIntroduza o nome do seu utilizador: ");
                    scanf("%s",name);

                    if(head->prox==NULL){

                        flag=1;
                        
                    }

                    head = delete_User(head,name,flag);
                    flag=0;

                }

                break;

            case 4:

                aux = criar_User(id);
                head = add_List(head,aux);
                id++;
                break;

            case 5:

                list_User(head);
                break;   

        }

    }while(menu!=0);

    write_file(head,id);

}