#include "../includes/structs.h"
#include <string.h>

ARTIGO consulta_artigo(MERCEARIA m,char nome []){
   
   for(int i = 0; i < m.number ; i++){

       if(strcmp(m.artigos[i].nome,nome)==0){
           return m.artigos[i];
       }
   }  
    ARTIGO r;
    return r;
}

ARTIGO edita_artigo(MERCEARIA m,char nome [], float preco){

    for(int i = 0; i < m.number ; i++){

         if(strcmp(m.artigos[i].nome,nome)==0){

           m.artigos[i].preco=preco;  
           return m.artigos[i];
       }
        
    }
        ARTIGO r;
        return r;
}
