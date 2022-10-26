#include <stdio.h>
#include <string.h>

/* Definição de um artigo*/
typedef struct Artigo
{
   char nome[50];
   float preco;
}ARTIGO;

/* Definição do nosso objeto agregador*/

typedef struct Mercearia
{
   ARTIGO artigos[50];
   int number;
}MERCEARIA;

/* Funções de inicialização*/

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

/* Queries sobre a mercearia */
ARTIGO consulta_artigo(MERCEARIA m,char nome []){
    for (int i = 0; i <m.number ; i++)
    {
        if(strcmp(m.artigos[i].nome,nome)==0){
            return m.artigos[i];
        }
    }
    ARTIGO r;
    return r;
}

ARTIGO edita_artigo(MERCEARIA m,char nome[],float preco){

       for(int i = 0; i < m.number ; i++){

         if(strcmp(m.artigos[i].nome,nome)==0){

           m.artigos[i].preco=preco;  
           return m.artigos[i];
       }
        
    }
        ARTIGO r;
        return r;
}

MERCEARIA remove_artigo(MERCEARIA m,char nome[]){

       for(int i = 0; i < m.number ; i++){

            if(strcmp(m.artigos[i].nome,nome)==0){

                ARTIGO aux;

                for(int j = i; j < m.number; j++){

                aux = m.artigos[i];
                m.artigos[i]=m.artigos[i+1];
                m.artigos[i+1]=aux;

                }

                m.number--;

                return m;
            }

       }

}

/* Visualização das structs*/
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

int main(){
    /* Criação dos artigos */
    ARTIGO a1 = cria_artigo("Maçãs",1.2);
    ARTIGO a2 = cria_artigo("Cereais",2.5);
    ARTIGO artigos[2];
    artigos[0]=a1;
    artigos[1]=a2;

    /* Inicialização da mercearia */
    MERCEARIA merc = init(artigos,2);

    /************ Queries sobre a mercearia *************/

    /* 1 - Consulta de todos os produtos disponíveis*/
    // mercearia2str(merc);

    /* 2 - Consulta de um artigo por nome */
 //   ARTIGO c1 = consulta_artigo(merc,"Maçãs");
//  produto2str(c1);
    /* 3 - Consulta de artigos por intervalo de preço */
 
    /* 4 - Edição do preço de um determinado artigo */
//    ARTIGO c3 = edita_artigo(merc,"Maçãs",3.0);
//    produto2str(c3);
    /* 5 - Eliminar um determinado artigo por preço */

    /* 6 - Receber as informações necessárias para criar os artigos pelo terminal */

    /* 7 - Guardar a mercearia num ficheiro */

  /*  FILE *ficheiro;

    ficheiro = fopen("mercearia","w");

    if(ficheiro == NULL){

        printf("Erro ao abrir o ficheiro");

        return 1;

    }

    int escrito = fwrite(&merc,sizeof(struct Mercearia),1,ficheiro);

    if (escrito!=0)

    {

        printf("Mercearia guardada com sucesso");

    }

    else{

        printf("Erro ao guardar a Mercearia no ficheiro");

    }

     8- Carregar a mercearia de um ficheiro 

    FILE *ficheiro_leitura;

    ficheiro_leitura = fopen("mercearia","rb");

    if(ficheiro_leitura == NULL){

        printf("Erro ao abrir o ficheiro");

        return 1;

    }

    int leitura = fread(&merc,sizeof(struct Mercearia),1,ficheiro_leitura);

    printf("\n%d",leitura);

    if(leitura != 0){
        
        mercearia2str(merc);
        printf("Leitura efetuada com sucesso");

    }

    else{

        printf("Ocorreu um erro na leitura");

    }

	*/

    /* 6 - Guardar a mercearia num ficheiro */

    FILE *ficheiro;

    ficheiro = fopen ("mercearia", "w");

    if (ficheiro == NULL)

    {

        printf(stderr, "Erro ao abrir o ficheiro para escrita\n"); 

        return 1;

    }

    int escrito = fwrite (&merc, sizeof(struct Mercearia), 1, ficheiro);

    if(escrito != 0){

        printf("Mercearia guardada no ficheiro com suceeso!\n"); 

    }

    else{

        printf("Erro ao guardar a Mercearia no ficheiro!\n"); 

    }

    fclose (ficheiro);



    // /* 7 - Carregar a mercearia de um ficheiro */

    FILE *ficheiro_leitura;

    ficheiro_leitura = fopen ("mercearia", "r");

    if (ficheiro_leitura == NULL)

    {

        printf(stderr, "Erro ao abrir o ficheiro para leitura\n"); 

        return 1;

    }

    MERCEARIA m_lida;

    int lido = fread(&m_lida, sizeof(struct Mercearia), 1, ficheiro_leitura);

    if(lido != 0){

        printf("Mercearia lida do ficheiro com suceeso:\n");

        mercearia2str(m_lida);

    }

    else{

        printf("Erro ao ler a mercearia do ficheiro!\n");

    }

    fclose (ficheiro_leitura);


}

