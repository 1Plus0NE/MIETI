#include <stdio.h>
#include <string.h>

#include "../includes/structs.h"
#include "../includes/str.h"
#include "../includes/init.h"
#include "../includes/queries.h"


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
    ARTIGO c1 = consulta_artigo(merc,"Maçãs");
    produto2str(c1);

    /* 3 - Consulta de artigos por intervalo de preço */

    /* 4 - Edição do preço de um determinado artigo */
    ARTIGO c3 = edita_artigo(merc,"Maçãs",3.0);
    produto2str(c3);
    /* 5 - Eliminar um determinado artigo por preço */

    /* 6 - Receber as informações necessárias para criar os artigos pelo terminal */

	return 0;
}