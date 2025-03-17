#include "myDLL.h"

void MyDLLRemove(lista *list, uint16_t id){

        if(list->numero_no == 0){
            printf("\nA lista está vazia.\n");
            return;
        }

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
            list->array_nos[no_remover->no_anterior].proximo_no = no_remover->proximo_no;
        else 
            list->primeiro_no = no_remover->proximo_no; // Isto se for o primeiro nó.

        // Se não for o último
        if(no_remover->proximo_no!=-1)
            list->array_nos[no_remover->proximo_no].no_anterior = no_remover->no_anterior;

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

        list->numero_no--;

        // atualização dos valores dos restantes nós
        for(int i = 0; i < list->numero_no; i++){
            if(list->array_nos[i].no_anterior > remover_chave)
                list->array_nos[i].no_anterior--;
            if(list->array_nos[i].proximo_no > remover_chave)
                list->array_nos[i].proximo_no--;
        }


        printf("\nElemento com Chave %d removido com sucesso.\n", id);
}