#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define tamanho_dados 60
#define numero_nos 4

typedef struct 
{
    uint16_t chave_no;                     /** identifica o nó*/
    unsigned char dados_no[tamanho_dados]; /** dados do nó*/
    int no_anterior;                       /** indice do nó anterior*/ 
    int proximo_no;                        /** indice do proximo nó*/
}no;

typedef struct 
{
    no array_nos [numero_nos];              /** array de nós*/
    int no_atual;                           /** indice do nó atual*/
    int primeiro_no;                        /** indice do primeiro no*/
    int ultimo_no;                          /** indece do ultimo no*/
    int numero_no;                          /** numero total de nós*/
    no  *p_no_atual;                        /** ponteiro para nó atual*/
}lista;

//Funções auxiliares
void ValidarChave(uint16_t *chave);
void ValidarDados(unsigned char *dados);
void LimparBuffer();

void MyDLLInit(lista *DLL);
void MyDLLInsert(lista *lst, uint16_t chave, const unsigned char *dados);
void MyDLLRemove(lista *list, uint16_t id);
no *MyDLLFind(lista *list, uint16_t id);
no *MyDLLFindPrevNext (lista *list,char *find, uint16_t id);

