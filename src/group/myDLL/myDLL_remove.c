/** \file myDLL_remove.c 
 *  \brief Remoção de um elemento da lista
 * 
  * 
 * Esta função remove um nó identificado pela sua chave, garantindo a reestruturação da lista 
 * para manter a integridade dos ponteiros e evitar espaços vazios entre os elementos.
 * 
 *  \authors Joana Duarte(102608), Hugo Miranda(104348)
 *  \date 18 Março 2025
 *  \bug  Sem bugs
 */


#include "myDLL.h"


/**
 * \brief Remove um nó da lista duplamente ligada com base na chave fornecida.
 * 
 * \param[in] list Ponteiro para a estrutura da lista.
 * \param[in] id Chave do nó a ser removido.
 */

void MyDLLRemove(lista *list, uint16_t id){

        // 1o Verirficar se a lista está vazia
        if(list->numero_no == 0){
            printf("\nA lista está vazia.\n");
            return;
        }

        // Camada da função MyDLLFind para localizar o nó que se pretendxe remover
        no* no_remover = MyDLLFind(list, id);

        // Verificar se existe o nó com a chave pedida
        if(!no_remover) {
            printf("\nElemento com chave %d nao encontrado\n", id);
            return;
        } 

        int remover_chave = list->no_atual; // indice do nó a remover
        // Atualização dos ponteiros do nó anterior e do próximo

        // Se não for o 1o nó 
        if(no_remover->no_anterior != -1)
            list->array_nos[no_remover->no_anterior].proximo_no = no_remover->proximo_no; // no_remover->proximo_no: indice do no seguinte ao nó que queremos remover removido; 
                                                                                          // list->array_nos[no_remover->no_anterior]: acede ao nó seguinte
                                                                                          // .proximo_no: passa a apontar para o nó seguinte
        else 
            list->primeiro_no = no_remover->proximo_no; // Isto se for o primeiro nó.

        // Se não for o último
        if(no_remover->proximo_no !=-1)
            list->array_nos[no_remover->proximo_no].no_anterior = no_remover->no_anterior; // no_remover->proximo_no: indice do no seguinte ao nó que queremos remover removido; 
                                                                                           // list->array_nos[no_remover->no_anterior]: acede ao nó seguinte
                                                                                           // no_anterior: passa a apontar para o nó anterior 
        else
            list->ultimo_no = no_remover->no_anterior; // No caso de ser o primeiro

        // Dar reset ao ponteiro do nó removido
        if(list->no_atual == remover_chave){
            list->no_atual = -1;
            list->p_no_atual = NULL;
        }

        // recuar os elementos dos nós seguintes para não ficarem espaços vazios entre si
        for(int i = remover_chave; i < list->numero_no -1; i++){
            list->array_nos[i] = list->array_nos[i+1];
        }
        list->numero_no--; // Decrementa o número de nós existente

        // atualização dos valores dos restantes nós (ajuste do índice dos nós)
        for(int i = 0; i < list->numero_no; i++){
            if(list->array_nos[i].no_anterior > remover_chave) // Atualizar o índice anterior
                list->array_nos[i].no_anterior--; 
            if(list->array_nos[i].proximo_no > remover_chave) // Atualizar o índice seguinte
                list->array_nos[i].proximo_no--; 
        }

        printf("\nElemento com Chave %d removido com sucesso.\n", id);
}