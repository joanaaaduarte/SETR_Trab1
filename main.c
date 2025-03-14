#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "myDLL.h"

void ExibirLista(const lista *lst) {
    if (lst->numero_no == 0) {
        printf("\nA lista está vazia!\n");
        return; 
    }

    printf("\nLista de Nós:\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < lst->numero_no; i++) {
        printf("Nó %d\n", i);
        printf("  Chave: %u\n", lst->array_nos[i].chave_no);
        printf("  Dados: %s\n", lst->array_nos[i].dados_no);
        printf("  Nó Anterior: %d\n", lst->array_nos[i].no_anterior);
        printf("  Próximo Nó: %d\n", lst->array_nos[i].proximo_no);
        printf("---------------------------------------------------\n");
    }
}

int main() {
    int escolha;
    lista minha_lista;
    MyDLLInit(&minha_lista);

    uint16_t chave;
    unsigned char dados[tamanho_dados];

    while (1) {
        
        printf("\n1-> Inserir um Nó\n2-> Exibir lista\n3-> Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &escolha) != 1) {
            printf("Erro! Entrada inválida.\n");
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
                printf("Programa Encerrado...\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}