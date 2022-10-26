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

#include "../includes/structs.h"

int hora_fim(tarefa *t, int i){

    // Função responsável pela comparação da hora do fim da tarefa com a hora do inicio da tarefa

    int flag=0;

    if(t[i].hora_fim_h<t[i].hora_inicio_h){

        flag=1;

    }

    else if(t[i].hora_fim_min<t[i].hora_inicio_min && t[i].hora_fim_h<=t[i].hora_inicio_h){

        flag=1;

    }

    while(flag){

        printf("\nValores invalidos!");
        printf("\nIntroduza valores validos para a hora de inicio");
        printf("\n\nHora de Inicio: ");
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
        printf("\nIntroduza valores validos para a data ( aaaa mm dd )\n");
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

tarefa cria_tarefa(tarefa *t, int i){

            // Declaração de variáveis

            int prio;
            int est;

            // Determinar a hora atual ( dia, mes, ano, hora e minuto )

            /*
            int hora, min, dia, mes, ano;

            time_t now;
            time(&now);
            struct tm *local = localtime(&now);

            hora = local->tm_hour;
            min = local->tm_min;   
 
            dia = local->tm_mday;            
            mes = local->tm_mon + 1;                 
            ano = local->tm_year + 1900;
            */
            // Pede um nome para a tarefa

            printf("\nNome da Tarefa: ");
            scanf("%s",t[i].nome_tarefa);
            getchar();                      // Recebe o \n do scanf 

            // Pede uma descrição para a tarefa

            printf("\nDescricao: ");
            scanf("%[^\n]",t[i].descricao_tarefa);

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

        printf("\nDescricao: %s",t[pos].descricao_tarefa);
        printf("\nTipo de Tarefa: %s",t[pos].tipo_tarefa);
        printf("\nSubtipo de Tarefa: %s",t[pos].subtipo_tarefa);
        printf("\nPrioridade: %s",t[pos].prioridade);
        printf("\nEstado da Tarefa: %s",t[pos].estado_tarefa);
        printf("\nData de Inicio ( dd/mm/aa ): %d/%d/%d",t[pos].data_inicio_dd,t[pos].data_inicio_mm,t[pos].data_inicio_aa);
        printf("\nData de Fim ( dd/mm/aa ): %d/%d/%d",t[pos].data_fim_dd,t[pos].data_fim_mm,t[pos].data_fim_aa);
        printf("\nHora de Inicio: %d:%d",t[pos].hora_inicio_h,t[pos].hora_inicio_min);
        printf("\nHora de Fim: %d:%d",t[pos].hora_fim_h,t[pos].hora_fim_min);
        printf("\n");

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

int main(void){

    // Declaração de variáveis

    tarefa t[50];
    int i=0;
    int menu;
    FILE *file_tarefa;
    int remover=0;

    file_tarefa=fopen("Tarefa.bin","rb");
    while(fread(&t[i],sizeof(tarefa),1,file_tarefa)){
        
        i++;
        printf("Foi adicionada %d tarefa\n",i);    

    }fclose(file_tarefa);

    do{

    printf("\n\nSeja bem-vindo ao Sistema de Gestao de Tarefas\nO que deseja consultar?\n\n1. Ver Tarefas\n2. Editar Tarefas\n3. Eliminar Tarefas\n4. Criar Tarefas\n5. Sair\n\n");
    scanf("%d",&menu);

    switch(menu){

        case 1:

            ver_tarefa(t, i);
            break;

        case 2:

            editar_tarefa(t, i);
            break;
            
        case 3:

            eliminar_tarefa(t, &i);
            break;
            
        case 4:

            cria_tarefa(t, i);
            i++;
            break;

        default:

            break;    

    }
    
}while(menu!=5);

    remover=remove("Tarefa.bin");

    file_tarefa=fopen("Tarefa.bin","ab");

    for(int j=0;j<i;j++){
        
        fwrite(&t[j],sizeof(tarefa),1,file_tarefa);

    }fclose(file_tarefa);

    printf("\nAs suas tarefas foram guardadas com sucesso!");

}


