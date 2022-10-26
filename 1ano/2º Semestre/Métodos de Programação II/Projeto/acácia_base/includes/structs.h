/* Definição das estruturas */
#ifndef HEADER_FILE // Isto permite que não ocorram erros quando o ficheiro é
#define HEADER_FILE // incluído em vários ficheiros .c

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
#endif