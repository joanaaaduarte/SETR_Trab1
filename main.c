/** \file main.c 
 
 * 
 * Este programa permite testar os módulos myDLL.c e myDLL.h de uma Double Linked List (DLL). É possível inserir, remover e procurar nós de uma lista.
 * 
  * \authors Joana Duarte, nmec: 102608
 *  \authors Hugo Miranda, nemc: 104348
 *  \date 25 Março 2025
 *  \bug   Sem bugs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "myDLL.h"

/**
 * \brief Exibe todos os nós da lista.
 * 
 *  ESta função serve para imprimir a lista (DLL).
 * 
 * \param[in] lst Ponteiro para a estrutura da lista.
 */

void ExibirLista(const lista *lst) {
    if (lst->numero_no == 0) {
        printf("\nA lista está vazia!\n");
        return; 
    }

    printf("\nLista de Nós:\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < lst->numero_no; i++) {
        printf("Nó %d\n", i);
        printf("Chave: %u\n", lst->array_nos[i].chave_no);
        printf("Dados: %s\n", lst->array_nos[i].dados_no);
        printf("Nó Anterior: %d\n", lst->array_nos[i].no_anterior);
        printf("Próximo Nó: %d\n", lst->array_nos[i].proximo_no);
        printf("---------------------------------------------------\n");
    }
}

/**
 * \brief Função principal para manipulação da lista (DLL).
 * 
 * O programa fornece um menu interativo permitindo ao usuário poder escolher as diferentes opções:
 * 
 * 1-> Inserir um novo Nó;
 * 2-> Exibir lista de Nós;
 * 3-> Remover Nó da lista;
 * 4-> Encontrar Nó;
 * 5-> Encontrar anterior/seguinte do Nó pretendido;
 * 6 -> Sair;
 *  
 * \return Retorna 0 ao finalizar o programa.
 */

int main() {
    int escolha;
    lista minha_lista;
    MyDLLInit(&minha_lista);

    uint16_t chave; 
    char data[10];
    unsigned char dados[tamanho_dados];

    while (1) {
        
        printf("\n1-> Inserir um novo Nó;\n"
                 "2-> Exibir lista de Nós;\n"
                 "3-> Remover Nó da lista;\n"
                 "4-> Encontrar Nó;\n"
                 "5-> Encontrar anterior/seguinte do Nó pretendido;\n"
                 "6-> Sair;\n");

        printf("Escolha uma opção: ");

        if (scanf("%d", &escolha) != 1) {
            printf("\nErro! Entrada inválida.\n");
            while (getchar() != '\n'); // Limpar o buffer
            continue;
        }
        while (getchar() != '\n'); // Limpar o buffer 

        switch (escolha) {
            case 1:
                ValidarChave(&chave);
                ValidarDados(dados);
                MyDLLInsert(&minha_lista, chave, dados);
                break;
            case 2:
                ExibirLista(&minha_lista);
                break;
            case 3:
                printf("\nInserir chave da lista a remover:");
                scanf("%hd", &chave);
                MyDLLRemove(&minha_lista, chave);
                break;
            case 4:
                printf("\nChave do nó pretende encontrar: ");
                scanf("%hd", &chave);
                no *encontrado = MyDLLFind(&minha_lista, chave);
                if(encontrado != NULL){
                    printf("\nNó encontrado: Chave = %d, Dados = %s\n", encontrado->chave_no, encontrado->dados_no);
                } else {
                    printf("\nErro: Nenhum elemento encontrado com a chave %d.\n", chave);
                }
                break;    
            case 5:
                printf("\nChave do nó pretende encontrar:");
                scanf("%hd", &chave);
                printf("\nSeguinte (inserir 'S' ou 's') ou Anterior (inserir 'A' ou 'a'):");
                scanf("%s", data);
                MyDLLFindPrevNext(&minha_lista, data, chave);
                break;
            case 6:
                printf("\nPrograma Encerrado.\n");
                return 0;
            default:
                printf("\nOpção inválida! Selecione uma opção válida\n");
        }
    }
    return 0;
}