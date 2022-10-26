/*

     __________________________________________
    |                                          |
    |   MP2                                    |
    |   Trabalho realizado por:                |
    |                                          |
    |   Luis Ferreira A98286                   |
    |   José Fernandes A95360                  |
    |                                          |
    |__________________________________________|

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../includes/structs.h"
#include "../includes/colaboradores.h"

int hora_fim(tarefa *t, int i){

    // Função responsável pela comparação da hora do fim da tarefa com a hora do inicio da tarefa

    int flag=0, flag2=0;

    if(t[i].data_inicio_aa == t[i].data_fim_aa){

        if(t[i].data_inicio_mm == t[i].data_fim_mm){

            if(t[i].data_inicio_dd == t[i].data_fim_dd){

                if(t[i].hora_fim_h<t[i].hora_inicio_h){

                    flag=1;

                }

                else if(t[i].hora_fim_min<t[i].hora_inicio_min && t[i].hora_fim_h<=t[i].hora_inicio_h){

                    flag=1;

                }

                while(flag){

                    printf("\nValores invalidos!");
                    printf("\nIntroduza valores validos para a hora de inicio");
                    printf("\n\nHora de Fim: ");
                    scanf("%d %d",&t[i].hora_fim_h,&t[i].hora_fim_min);

                    flag=0;

                    if(t[i].hora_fim_h<t[i].hora_inicio_h){

                        flag=1;

                    }

                    else if(t[i].hora_fim_min<t[i].hora_inicio_min && t[i].hora_fim_h<=t[i].hora_inicio_h){

                        flag=1;

                    }

                }

            }

        }

    }

    else{

        if(t[i].hora_fim_h<0){

            flag2=0;

        }

        else if(t[i].hora_fim_min<0){

            flag2=0;

        }

        while(flag2){

            printf("\nValores invalidos!");
            printf("\nIntroduza valores validos para a hora de inicio");
            printf("\n\nHora de Fim: ");
            scanf("%d %d",&t[i].hora_fim_h,&t[i].hora_fim_min);

            flag2=0;

            if(t[i].hora_fim_h<0){

                flag2=0;

            }

            else if(t[i].hora_fim_min<0){

                flag2=0;

            }

        }

    }    

}

int hora_inicio(tarefa *t, int i){

    // Função responsável pela comparação da hora do inicio da tarefa com a hora do sistema

    int flag=0;
    int hora,min;

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    hora = local->tm_hour;
    min = local->tm_min;

    if(t[i].hora_inicio_h<hora){

        flag=1;

    }

    else if(t[i].hora_inicio_min<min && t[i].hora_inicio_h<=hora){

        flag=1;

    }

    while(flag){

        printf("\nValores invalidos!");
        printf("\nIntroduza valores validos para a hora de inicio");
        printf("\n\nHora de Inicio: ");
        scanf("%d %d",&t[i].hora_inicio_h,&t[i].hora_inicio_min);

        flag=0;

        if(t[i].hora_inicio_h<hora){

            flag=1;

        }

        else if(t[i].hora_inicio_min<min && t[i].hora_inicio_h<=hora){

            flag=1;

        }

    }

}

int data_fim(tarefa *t, int i){

    // Função responsável pela comparação da data de fim da tarefa com a data de inicio da tarefa

    int flag=0;

    if(t[i].data_fim_aa<t[i].data_inicio_aa){         

        flag=1;

    } 

    else if(t[i].data_fim_mm<t[i].data_inicio_mm && t[i].data_fim_aa<=t[i].data_inicio_aa){ 

        flag=1;

    }

    else if(t[i].data_fim_dd<t[i].data_inicio_dd && t[i].data_fim_mm<=t[i].data_inicio_mm && t[i].data_fim_aa<=t[i].data_inicio_aa){

        flag=1;

    }


    while(flag){

        printf("\nValores invalidos!");
        printf("\nData de fim nao pode ser inferior a data de inicio ");
        printf("\n\nData de Fim ( aaaa mm dd ): ");
        scanf("%d %d %d",&t[i].data_fim_aa,&t[i].data_fim_mm,&t[i].data_fim_dd);

        flag=0;

        if(t[i].data_fim_aa<t[i].data_inicio_aa){

            flag=1;

        } 

        else if(t[i].data_fim_mm<t[i].data_inicio_mm && t[i].data_fim_aa<=t[i].data_inicio_aa){

            flag=1;

        }

        else if(t[i].data_fim_dd<t[i].data_inicio_dd && t[i].data_fim_mm<=t[i].data_inicio_mm && t[i].data_fim_aa<=t[i].data_inicio_aa){

            flag=1;

        }

    }

}

int data_inicio(tarefa *t,int i){

    // Função responsável pela comparação da data de inicio da tarefa com a data do sistema

    int flag=0;
    int dia, mes, ano;

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    dia = local->tm_mday;            
    mes = local->tm_mon + 1;                 
    ano = local->tm_year + 1900;

    if(t[i].data_inicio_aa<ano){    

        flag=1;

    }

    else if(t[i].data_inicio_mm<mes && t[i].data_inicio_aa<=ano){
        
        flag=1;

    }

    else if(t[i].data_inicio_dd<dia && t[i].data_inicio_mm<=mes && t[i].data_inicio_aa<=ano){

        flag=1;

    }

    while(flag){

        printf("\nValores invalidos!");
        printf("\nIntroduza valores validos para a data ( aaaa mm dd )");
        printf("\n\nData de Inicio ( aaaa mm dd ): ");
        scanf("%d %d %d",&t[i].data_inicio_aa,&t[i].data_inicio_mm,&t[i].data_inicio_dd);

        flag=0;

        if(t[i].data_inicio_aa<ano){
        
            flag=1;

        }

        else if(t[i].data_inicio_mm<mes && t[i].data_inicio_aa<=ano){
        
            flag=1;

        }

        else if(t[i].data_inicio_dd<dia && t[i].data_inicio_mm<=mes && t[i].data_inicio_aa<=ano){

            flag=1;

        }

    }

}

void swap(void *x, void *y, int size){

    void *tmp;

    // Variavel tmp aloca na memória o tamanho da tarefa

    tmp = malloc(size);

    // Swap

    memcpy(tmp, x, size);
    memcpy(x, y, size);
    memcpy(y, tmp, size);

    // Após o swap fica livre o espaço na memória utilizado

    free(tmp);

}

void prioridade(int x, int i, tarefa t[]){

    t[i].prioridade;

    if(x==1){

        strcpy(t[i].prioridade,"Alta");

    }

    if(x==2){

        strcpy(t[i].prioridade,"Media");
        
    }

    if(x==3){

        strcpy(t[i].prioridade,"Baixa");
        
    }

}

void estado(int y,int i,tarefa t[]){

    t[i].estado_tarefa;

    if(y==1){

        strcpy(t[i].estado_tarefa,"Concluido");

    }

    if(y==2){

        strcpy(t[i].estado_tarefa,"Pendente");

    }

}

tarefa cria_tarefa(tarefa *t, int i, int id_tarefa){

            // Declaração de variáveis

            int prio;
            int est;

            t[i].identificador_tarefa=id_tarefa;

            printf("\n#%04d",t[i].identificador_tarefa);    
            getchar();
            printf("\nNome da Tarefa: ");
            scanf("%[^\n]",t[i].nome_tarefa);
            getchar();                     // Recebe o \n do scanf 

            // Pede uma descrição para a tarefa
            
            printf("\nDescricao: ");
            scanf("%[^\n]",t[i].descricao_tarefa);
            getchar();
            // Pede um tipo para a tarefa

            printf("\nTipo de Tarefa ( Profissional ou Pessoal): ");
            scanf("%s",t[i].tipo_tarefa);

            // Pede um subtipo para a tarefa

            printf("\nSubtipo de Tarefa ( Desporto, Estudos, Casa, etc...): ");
            scanf("%s",t[i].subtipo_tarefa);

            // Define a prioridade da tarefa

            printf("\nPrioridade:\n\n1.Alta\n2.Media.\n3.Baixa\n\n");
            scanf("%d",&prio);

            while(prio!=1 && prio!=2 && prio!=3){

                    printf("\nValor invalido!");
                    printf("\nIntroduza um valor valido\n");
                    printf("\nPrioridade:\n\n1.Alta\n2.Media.\n3.Baixa\n\n");
                    scanf("%d",&prio);

            }

            prioridade(prio,i,t);

            // Define o estado da tarefa

            printf("\nEstado da Tarefa\n\n1.Concluido\n2.Pendente\n\n");
            scanf("%d",&est);

            while(est!=1 && est!=2){

                    printf("\nValor invalido!");
                    printf("\nIntroduza um valor valido\n");
                    printf("\nEstado da Tarefa\n\n1.Concluido\n2.Pendente\n\n");
                    scanf("%d",&est);

            }

            estado(est,i,t);

            // Pede uma data de inicio da tarefa

            printf("\nData de Inicio ( aaaa mm dd ): ");
            scanf("%d %d %d",&t[i].data_inicio_aa,&t[i].data_inicio_mm,&t[i].data_inicio_dd);

            data_inicio(t,i);

            // Pede uma data de fim da tarefa

            printf("\nData de Fim ( aaaa mm dd ): ");
            scanf("%d %d %d",&t[i].data_fim_aa,&t[i].data_fim_mm,&t[i].data_fim_dd);
            
            data_fim(t,i);

            // Pede uma hora de inicio da tarefa

            printf("\nHora de Inicio: ");
            scanf("%d %d",&t[i].hora_inicio_h,&t[i].hora_inicio_min);

            hora_inicio(t,i);

            // Pede uma hora de fim da tarefa

            printf("\nHora de Fim: ");
            scanf("%d %d",&t[i].hora_fim_h,&t[i].hora_fim_min);

            hora_fim(t,i);

}

int ver_tarefa(tarefa *t, int total){

        // Declaração de variáveis

        int j=0;
        int pos=0;
        
        // Condição para verificar se há alguma tarefa

        if(total==0){

          printf("\nNao foi possivel encontrar uma tarefa.");

        }

        else{

            // Ciclo que percorre o array de tarefas e que as dispõe no ecrã

            printf("\nQue tarefa pretende consultar?\n");
            
            for(int i=0;i<total;i++){

                j++;
                printf("\n%d.%s",j,t[i].nome_tarefa);
                
            }

            printf("\n\n");
            scanf("%d",&pos);

            if(pos>total){

                printf("\nEssa tarefa nao existe!");

            }

        else{

            pos--;

            // Printa as informações da tarefa escolhida
            printf("\nID: #%04d",t[pos].identificador_tarefa);
            printf("\nDescricao: %s",t[pos].descricao_tarefa);
            printf("\nTipo de Tarefa: %s",t[pos].tipo_tarefa);
            printf("\nSubtipo de Tarefa: %s",t[pos].subtipo_tarefa);
            printf("\nPrioridade: %s",t[pos].prioridade);
            printf("\nEstado da Tarefa: %s",t[pos].estado_tarefa);
            printf("\nData de Inicio ( dd/mm/aa ): %d/%d/%d",t[pos].data_inicio_dd,t[pos].data_inicio_mm,t[pos].data_inicio_aa);
            printf("\nData de Fim ( dd/mm/aa ): %d/%d/%d",t[pos].data_fim_dd,t[pos].data_fim_mm,t[pos].data_fim_aa);
            printf("\nHora de Inicio: %d:%d",t[pos].hora_inicio_h,t[pos].hora_inicio_min);
            printf("\nHora de Fim: %d:%d",t[pos].hora_fim_h,t[pos].hora_fim_min);
            int ctd=0;         
            printf("\nParticipantes da Tarefa: %s\n",t[pos].participantes[ctd]);

        } 

    }

}

void editar_tarefa(tarefa *t, int total){

        // Declaração de variáveis

        int pos=0;
        int seleciona=0;
        int prio=0;
        int est=0;
        int j=0;

        // Condição para verificar se há alguma tarefa 

        if(total==0){

            printf("\nNao foi possivel encontrar uma tarefa.");

        }

        else{

        // Ciclo que percorre o array de tarefas e que as dispõe no ecrã para o utilizador editar

        printf("\nQue tarefa pretende editar?\n");

        for(int i=0;i<total;i++){

            j++;
            printf("\n%d.%s",j,t[i].nome_tarefa);

        }

        printf("\n\n");
        scanf("%d",&pos);

        if(pos>total){

            printf("\nEssa tarefa nao existe!");

        }

        else{

        pos--;
        int i=pos;

        printf("\nO que deseja alterar?\n\n1.Nome da Tarefa\n2.Descricao\n3.Tipo de Tarefa\n4.Subtipo de Tarefa\n5.Prioridade da Tarefa\n6.Estado da Tarefa\n7.Data de Inicio\n8.Data de Fim\n9.Hora de Inicio\n10.Hora de Fim\n\n");
        scanf("%d",&seleciona);
        getchar();

            switch(seleciona){

                case 1:

                printf("\nEscreva um novo nome da tarefa: ");
                scanf("%s",&t[i].nome_tarefa);

                printf("\nO novo nome da tarefa: %s",t[i].nome_tarefa);
                break;

                case 2:

                printf("\nEscreva uma nova descricao: ");
                scanf("%[^\n]",&t[i].descricao_tarefa);

                printf("\nA sua nova descricao: %s",t[i].descricao_tarefa);
                break;

                case 3:

                printf("\nAltere o tipo de tarefa ( Profissional ou Pessoal): ");
                scanf("%s",&t[i].tipo_tarefa);

                printf("O novo tipo de tarefa: %s",t[i].tipo_tarefa);
                break;

                case 4:

                printf("\nAltere o subtipo de tarefa ( Desporto, Estudos, Casa, etc...): ");
                scanf("%s",&t[i].subtipo_tarefa);

                printf("\nO novo subtipo de tarefa: %s",t[i].subtipo_tarefa);
                break;

                case 5:

                printf("\nAltere a sua prioridade:\n\n1.Alta\n2.Media.\n3.Baixa\n\n");
                scanf("%d",&prio);

                while(prio!=1 && prio!=2 && prio!=3){

                    printf("\nValor invalido!");
                    printf("\nIntroduza um valor valido\n");
                    printf("\nPrioridade:\n\n1.Alta\n2.Media.\n3.Baixa\n\n");
                    scanf("%d",&prio);

                }

                prioridade(prio,i,t);
                printf("\nA nova prioridade da tarefa: %s",t[i].prioridade);
                break;

                case 6:

                printf("\nEstado da Tarefa\n\n1.Concluido\n2.Pendente\n\n");
                scanf("%d",&est);

                while(est!=1 && est!=2){

                    printf("\nValor invalido!");
                    printf("\nIntroduza um valor valido\n");
                    printf("\nEstado da Tarefa\n\n1.Concluido\n2.Pendente\n\n");
                    scanf("%d",&est);

                }

                estado(est,i,t);
                printf("\nO novo estado da tarefa%s",t[i].estado_tarefa);
                break;

                case 7:

                printf("\nIntroduza a nova data de inicio ( aaaa mm dd ): ");
                scanf("%d %d %d",&t[i].data_inicio_dd,&t[i].data_inicio_mm,&t[i].data_inicio_aa);

                data_inicio(t,i);

                printf("\nA sua nova data de inicio: %d/%d/%d",t[i].data_inicio_aa,t[i].data_inicio_mm,t[i].data_inicio_dd);
                break;

                case 8:

                printf("\nIntroduza a nova data de fim ( aaaa mm dd ): ");
                scanf("%d %d %d",&t[i].data_fim_aa,&t[i].data_fim_mm,&t[i].data_fim_dd);

                data_fim(t,i);

                printf("\nA sua nova data de fim: %d/%d/%d",t[i].data_fim_aa,t[i].data_fim_mm,t[i].data_fim_dd);
                break;

                case 9:

                printf("\nIntroduza a nova hora de inicio: ");
                scanf("%d %d",&t[i].hora_inicio_h,&t[i].hora_inicio_min);

                hora_inicio(t,i);

                printf("\nA sua nova hora de inicio: %d:%d",t[i].hora_inicio_h,t[i].hora_inicio_min);
                break;

                case 10:

                printf("\nIntroduza a nova hora de fim: ");
                scanf("%d %d",&t[i].hora_fim_h,&t[i].hora_fim_min);

                hora_fim(t,i);

                printf("\nA sua nova hora de fim: %d:%d",t[i].hora_fim_h,t[i].hora_fim_min);
                break;

            }

        }

    }

}

void eliminar_tarefa(tarefa *t, int *total){

        // Declaração de variáveis

        int pos=0;
        int j=0; 

        // Condição para verificar se há alguma tarefa

        if(*total==0){

            printf("\nNao foi possivel encontrar uma tarefa.");

        }
        
        else{

        // Ciclo que percorre o array de tarefas e as dispõe no ecrã para o utilizador remover

        printf("\nQue tarefa pretende eliminar?\n");

        for(int i=0;i<*total;i++){

            j++;    
            printf("\n%d.%s",j,t[i].nome_tarefa);

        }
        
            printf("\n\n");
            scanf("%d",&pos);

        if(pos>*total){

            printf("\nEssa tarefa nao existe!");

        }

        else{

            pos--;

            for(int i=pos;i<*total-1;i++){

                swap(&t[i],&t[i+1],sizeof(tarefa));
            
            }
            
            *total-=1;

            printf("\nTarefa eliminada com sucesso!");

        }

    }

}

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

                    pos1 = ch;
                    i++;

                }

            }

            pos2 = ch;

        if(i == 1){

            while(pos1 - email && ch - pos1 > 1){

                
                if((pos2 - ch) > 2 && *ch == '.'){
                
                    return email;

                }

                ch--;

            }

        }

        printf("\nFoi introduzido um e-mail invalido!\nIntroduza o seu e-mail: ");
        scanf("%39s", email);
        
    }

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

NO* search(NO* list, char* tele){                           // Função para retornar um node dado um nome de um User existente

    NO* aux = NULL;
    for(aux = list; aux!=NULL; aux = aux->prox){

        if(strcmp(aux->user.tlm_user, tele)==0){
            
            return aux;

        }

    }

}

void print_User(NO* list, char* tele){                      // Função para printar as informações para um dado nome de um User

    NO* aux;
    aux = search(list, tele);

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

    NO* aux = list;

    if(aux){
        
        printf("\n%s",aux->user.nome_user);
        list_User(aux->prox);

    }
 
}

NO* edit_User(NO* list, char* tele){                        // Função para editar um User

    NO* aux;
    aux = search(list, tele);

    int escolha, age;
    char telemovel[9], email[30];

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
            scanf("%s", telemovel);

            strcpy(aux->user.tlm_user, tlm_user(aux, telemovel));
            break;
            
        }

    }

    return list;

}

NO* delete_User(NO* list, char* tele, int flag){            // Função para eliminar um User

    NO* aux = list;
    NO* ant = NULL;
  
    while(aux != NULL && strcmp(aux->user.tlm_user,tele)!=0){

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

void connectUser(NO* list, tarefa *t, int total){
    
    NO* aux;
     
    int j=0, pos=0, decision=0, ctd=0;
    char tele[9];
    
        // Condição para verificar se há alguma tarefa

        if(total==0){

            printf("\nNao foi possivel encontrar uma tarefa.");

        }

        else{

            // Ciclo que percorre o array de tarefas e que as dispõe no ecrã

            printf("\nQue tarefa pretende fazer ligacoes?\n");
        
            for(int i=0;i<total;i++){

                j++;
                printf("\n%d.%s",j,t[i].nome_tarefa);
            
            }

            printf("\n\n");
            scanf("%d",&pos);

        if(pos>total){

            printf("\nEssa tarefa nao existe!");

        }

        else{   
    
            //LINK* Copy = t[pos].colaborador;
            //LINK* New = NULL;

            do{

                printf("\nO que pretende fazer?\n");                 
                printf("\n1. Adicionar Utilizador\n2. Sair\n\n");
                scanf("%d",&decision);

                if(decision==1){
                    
                    printf("\nIntroduza o numero de telemovel do seu utilizador: ");
                    scanf("%s",tele);

                    aux=search(list, tele);

                    if(aux==NULL){
                        
                        printf("\nNao foi encontrado esse utilizador\n");

                    }
                    
                    else{
                        
                        strcpy(t[pos].participantes[ctd],aux->user.nome_user);
                        t[pos].partN++;
                        ctd++;
                        
                        /*

                            New = (LINK*)malloc(sizeof(LINK));

                            strcpy(New->linked.nameUser,aux->user.nome_user);
                            New->prox = NULL;

                            printf("\nIntroduza a função deste utilizador na tarefa: ");
                            scanf(" %[^\n]",New->linked.functionTask);

                            if(t[pos].colaborador==NULL){

                                strcpy(t[pos].colaborador, New->linked.nameUser);

                            }

                            else{

                                strcpy(Copy->linked.nameUser, t[pos].colaborador);

                                while(Copy->prox!=NULL){

                                    Copy = Copy->prox;

                                }

                                Copy->prox = New;

                            }

                        */    
                        
                        printf("\nUtilizador adicionado com sucesso!");
                        
                    }               

                }

            }while(decision!=2);

        }    

    }  

}

int main(void){

    // Variaveis usadas nas tarefas

    tarefa t[50];
    int i=0;
    int idTask=1;
    int menu, colaboradores, tarefas, connect;
    FILE *file_tarefa;
    int remover=0;

    // Variveis usadas nos colaboradores

    NO* head = NULL;
    NO* aux = NULL;
    int id=1, flag=0;
    char tele[30];

    head = read_file(head,&id);

    file_tarefa=fopen("Tarefa.bin","rb");
    while(fread(&t[i],sizeof(tarefa),1,file_tarefa)){
        
        i++;   

    }fclose(file_tarefa);

    do{

        printf("\n\nSeja bem-vindo ao Sistema de Gestao de Tarefas\nO que deseja consultar?\n\n1. Menu Colaboradores\n2. Menu Tarefas\n0. Sair\n\n");
        scanf("%d",&menu);

        switch(menu){

            case 1:

                menuUser:

                do{

                    printf("\nO que deseja consultar?\n\n1. Consultar Utilizador\n2. Editar Utilizadores\n3. Remover Utilizadores\n4. Criar Utilizadores\n5. Listar Utilizadores\n0. Sair\n\n");
                    scanf("%d",&colaboradores);

                    switch(colaboradores){
                            
                            case 1:

                                if(head==NULL){

                                    printf("\nNao existem utilizadores!");

                                }

                                else{

                                    printf("\nIntroduza o numero de telemovel do seu utilizador: ");
                                    scanf("%s",tele);

                                    print_User(head,tele);

                                }

                                goto menuUser;
                                break;
                                
                            case 2:

                                if(head==NULL){

                                    printf("\nNao existem utilizadores!");

                                }

                                else{

                                    printf("\nIntroduza o numero de telemovel do seu utilizador: ");
                                    scanf("%s",tele);

                                    edit_User(head,tele);

                                }
                                
                                goto menuUser;
                                break;

                            case 3:

                                if(head==NULL){

                                    printf("\nNao existem utilizadores!");

                                }

                                else{

                                    printf("\nIntroduza o numero de telemovel do seu utilizador: ");
                                    scanf("%s",tele);

                                    if(head->prox==NULL){

                                        flag=1;
                                        
                                    }

                                    head = delete_User(head,tele,flag);
                                    flag=0;

                                }

                                goto menuUser;
                                break;

                            case 4:

                                aux = criar_User(id);
                                head = add_List(head,aux);
                                id++;
                                goto menuUser;
                                break;

                            case 5:

                                list_User(head);
                                goto menuUser;
                                break;   

                    }

                }while(colaboradores!=0);

                write_file(head,id);
                break;

            case 2:

                menuTask:

                do{

                    printf("\nO que deseja consultar?\n\n1. Ver Tarefas\n2. Editar Tarefas\n3. Eliminar Tarefas\n4. Criar Tarefas\n5. Criar Ligacoes\n0. Sair\n\n");
                    scanf("%d",&tarefas);

                    switch(tarefas){

                    case 1:

                        ver_tarefa(t, i);
                        goto menuTask;
                        break;

                    case 2:

                        editar_tarefa(t, i);
                        goto menuTask;
                        break;
                        
                    case 3:

                        eliminar_tarefa(t, &i);
                        goto menuTask;
                        break;
                        
                    case 4:
                    
                        cria_tarefa(t, i, idTask);
                        i++;
                        idTask++;
                        goto menuTask;  
                        break;

                    case 5:

                        connectUser(head, t, i);
                        goto menuTask;
                        break;    

                }

            }while(tarefas!=0);
            break;

        }
    
    }while(menu!=0);

    remover=remove("Tarefa.bin");

    file_tarefa=fopen("Tarefa.bin","ab");

    for(int j=0;j<i;j++){
        
        fwrite(&t[j],sizeof(tarefa),1,file_tarefa);

    }fclose(file_tarefa);

}