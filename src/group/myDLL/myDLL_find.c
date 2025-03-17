
#include "myDLL.h"


// Encontra o Nó a partir do id
no *MyDLLFind(lista *list, uint16_t id){
    
    for (int i = 0; i < list->numero_no; i++) {
        if (list->array_nos[i].chave_no == id) { // verifica se o nó tem a chave corresponhdente à pedida
            // Atualização dos ponteiros  para o nó encontrado
            list->no_atual = i;
            list->p_no_atual = &list->array_nos[i];
        
            return list->p_no_atual;
        }
    }
    return NULL;
}

no *MyDLLFindPrevNext (lista *list, char *find, uint16_t id){

    // Localização do Nó a Chave pedida
    no *dll_find = MyDLLFind(list, id);
    list->p_no_atual = dll_find;

    // Vrifica se o nó existe
    if(list->p_no_atual == NULL) {
        printf("Nenhum nó selecionada.\n");
        return NULL;
    }

    if((strcmp(find, "A") == 0) || (strcmp(find, "a") == 0)){
        // primeiro verificar se estamos no primeiro
        if(list->p_no_atual->no_anterior == -1){
            printf("O Nó com Chave:%hd corresponde ao primeiro Nó.\n", list->p_no_atual->chave_no);
            return list->p_no_atual;
        }
        // Caso não seja o primeiro
        list->no_atual = list->p_no_atual->no_anterior;
        list->p_no_atual = &list->array_nos[list->no_atual];
        printf("Nó encontrado prev: Chave = %d, Dados = %s\n", list->p_no_atual->chave_no, list->p_no_atual->dados_no);
        return list->p_no_atual;

    } else if((strcmp(find, "S") == 0) || (strcmp(find, "s") == 0)){
        // primeiro verificar se estamos no último
        if(list->p_no_atual->proximo_no == -1){
            printf("O Nó com Chave:%hd corresponde ao último Nó.\n", list->p_no_atual->chave_no);
            return list->p_no_atual;
        }
        // Caso não seja o último
        list->no_atual = list->p_no_atual->proximo_no;
        list->p_no_atual = &list->array_nos[list->no_atual];
        printf("Nó encontrado prev: Chave = %d, Dados = %s\n", list->p_no_atual->chave_no, list->p_no_atual->dados_no);
        return list->p_no_atual;

    } else 
        printf("\nErro. Entrada inválida.\n");

    return NULL;

}