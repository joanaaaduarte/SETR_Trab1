/** \brief myDDL.h 
 *  \brief 
 * 
 * Este arquivo contém a estrutura de dados e as funções para a implementação de uma 
 * lista duplamente ligada estática, permitindo inserção, remoção e busca de nós.
 * 
 * 
 *  \authors Joana Duarte, Hugo Miranda
 *  \date 18 Março 2025
 */

 #ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define tamanho_dados 60
#define numero_nos 4

/**
 * \brief Estrutura que representa um nó na lista duplamente ligada.
 */

typedef struct 
{
    uint16_t chave_no;                     /** identifica o nó*/
    unsigned char dados_no[tamanho_dados]; /** dados do nó*/
    int no_anterior;                       /** indice do nó anterior*/ 
    int proximo_no;                        /** indice do proximo nó*/
}no;

/**
 * \brief Estrutura que representa a lista duplamente ligada.
 */

typedef struct 
{
    no array_nos [numero_nos];              /** array de nós*/
    int no_atual;                           /** indice do nó atual*/
    int primeiro_no;                        /** indice do primeiro no*/
    int ultimo_no;                          /** indece do ultimo no*/
    int numero_no;                          /** numero total de nós*/
    no  *p_no_atual;                        /** ponteiro para nó atual*/
}lista;

/* Funções auxiliares */

void ValidarChave(uint16_t *chave);
void ValidarDados(unsigned char *dados);
void LimparBuffer();

/* My DLL*/
void MyDLLInit(lista *DLL);
void MyDLLInsert(lista *lst, uint16_t chave, const unsigned char *dados);
void MyDLLRemove(lista *list, uint16_t id);
no *MyDLLFind(lista *list, uint16_t id);
no *MyDLLFindPrevNext (lista *list,char *find, uint16_t id);

#endif /* MYDLL_H */