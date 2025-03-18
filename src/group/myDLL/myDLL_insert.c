/** \brief myDDL_insert.c 
 *  \brief Adicionar elemento na lista
 * 
 * Esta função permite inserir um novo nó na lista, garantindo que não haja duplicação de chaves 
 * e respeitando o limite de elementos que a lista pode ter lista.
 * 
 * 
 *  \authors Joana Duarte, Hugo Miranda
 *  \date 18 Março 2025
 */

#include "myDLL.h"

/**
 * \brief Insere um novo nó na lista duplamente ligada.
 * 
 * \param[in] lst Ponteiro para a estrutura da lista onde o nó será inserido.
 * \param[in] chave Identificador único do nó a ser inserido.
 * \param[in] dados Ponteiro para os dados a serem armazenados no nó.
 * 
 */

void MyDLLInsert(lista *lst, uint16_t chave, const unsigned char *dados) {

    // Criar  novo nó
    no *novoNo = &lst->array_nos[lst->numero_no];   
    novoNo->chave_no = chave;                       

    // Verifica se a lista está cheia
    if (lst->numero_no < numero_nos){
    }else{ 
        printf("\n Lista cheia!\n");

        return;
    }

    // Verifica se a chave já existe na lista
    for (int i = 0; i < lst->numero_no; i++) {
        if (lst->array_nos[i].chave_no == chave) {
            printf("\n A chave já existe!\n");
            return;
        }
    }
    
    memcpy(novoNo->dados_no, dados, tamanho_dados);
    novoNo->no_anterior = lst->ultimo_no;           
    novoNo->proximo_no = -1;           
    
    if (lst->numero_no != 0) {         // Se já existem nós na lista                  
        lst->array_nos[lst->numero_no- 1].proximo_no = lst->numero_no;   
        novoNo->no_anterior = lst->numero_no - 1;                        
        lst->ultimo_no = lst->numero_no;                                  
    } else { 
        lst->no_atual = lst->numero_no;    
        lst->primeiro_no = lst->numero_no;
        lst->ultimo_no = lst->numero_no;   
        lst->p_no_atual = novoNo;      
    }

    lst->numero_no++; 
}

