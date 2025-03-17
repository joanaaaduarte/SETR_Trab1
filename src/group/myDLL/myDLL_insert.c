#include "myDLL.h"

void MyDLLInsert(lista *lst, uint16_t chave, const unsigned char *dados) {
    
    if (lst->numero_no >= numero_nos) { // Verifica se a lista está cheia
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

    // Criar e configurar o novo nó
    no *novoNo = &lst->array_nos[lst->numero_no];   // Obtém referência para o novo nó
    novoNo->chave_no = chave;                       // Define a chave do nó

    // Copiar os dados para o nó
    strncpy((char *)novoNo->dados_no, (char *)dados, tamanho_dados - 1);
    novoNo->dados_no[tamanho_dados - 1] = '\0'; 

    novoNo->no_anterior = lst->ultimo_no;           // Define o nó anterior como o último nó atual
    novoNo->proximo_no = -1;              

    
    if (lst->numero_no == 0) {                      // Inserir nó no final da lista  

        lst->no_atual = lst->numero_no;    
        lst->primeiro_no = lst->numero_no;
        lst->ultimo_no = lst->numero_no;   
        lst->p_no_atual = novoNo;           

    } else { // Se já existem nós na lista
        lst->array_nos[lst->numero_no- 1].proximo_no = lst->numero_no;   // Atualiza o "próximo" do nó anterior
        novoNo->no_anterior = lst->numero_no - 1;                        // Atualiza o "anterior" do novo nó para apontar para o anterior
        lst->ultimo_no = lst->numero_no;                                 // Atualiza a cauda da lista para o novo nó
    }

    lst->numero_no++; // Incrementa o contador de nós na lista
}

