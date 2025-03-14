<<<<<<< HEAD
#include <myDLL.c>


void MyDLLInit(){};

void MyDLLInsert(){};

void MyDLLRemove(){};
=======
#include <stdlib.h>
#include <ctype.h>
#include "myDLL.h"
#include <string.h>


//Funções auxiliares
void ValidarChave(uint16_t *chave) {

    char entrada[10]; // Buffer maior para capturar entradas inválidas
    int valido = 0;
    long valor;

    while (!valido) {
        printf("Insira chave (máximo 5 dígitos, entre 0 e 65535): ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("\nErro na leitura. Tente novamente.\n");
            continue;
        }

        // Remover '\n' se presente
        entrada[strcspn(entrada, "\n")] = '\0';

        // Verificar se a entrada tem mais de 5 caracteres
        if (strlen(entrada) > 5) {
            printf("\nErro! A chave deve ter no máximo 5 dígitos.\n");

            // LIMPAR BUFFER
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Tentar converter para número
        char *aux;
        //Função obtida no tutorialspoint
        valor = strtol(entrada, &aux, 10);

        if (*aux != '\0') {                         // verificar caracteres inválidos na conversão
            printf("\nErro! Insira apenas números.\n");
            continue;
        }

        if (valor < 0 || valor > 65535) {
            printf("\nErro! O número deve estar entre 0 e 65535.\n");
            continue;
        }

        *chave = (uint16_t)valor;
        valido = 1;                     // Entrada válida-> sair do loop
    }
}


void ValidarDados(unsigned char *dados) {
    //getchar();
    printf("Inserir dados: ");

    // Agora, lê os dados
    if (fgets((char *)dados, tamanho_dados, stdin) == NULL) {
        printf("\nErro na leitura dos dados. Tente novamente.\n");
    }

    // Remover o caractere de nova linha, se presente
    dados[strcspn((char *)dados, "\n")] = '\0';

}



void MyDLLInit(lista *DLL)
{
            
    DLL->no_atual = -1;                           
    DLL->primeiro_no = -1;                        
    DLL->ultimo_no = -1; 
    DLL->numero_no = 0;                         
    DLL->p_no_atual = NULL;                                                 
    
};

void MyDLLInsert(lista *lst, uint16_t chave, const unsigned char *dados) {
    
    if (lst->numero_no >= numero_nos) { // Verifica se a lista está cheia
        printf("\n Lista cheia!\n");
        return;
    }
>>>>>>> hugoV1

    // Verifica se a chave já existe na lista
    for (int i = 0; i < lst->numero_no; i++) {
        if (lst->array_nos[i].chave_no == chave) {
            printf("\n A chave já existe!\n");
            return;
        }
    }

<<<<<<< HEAD
void MyDLLFind(){};

void MyDLLFindNext(){};
=======
    // Criar e configurar o novo nó
    no *novoNo = &lst->array_nos[lst->numero_no];   // Obtém referência para o novo nó
    novoNo->chave_no = chave;                       // Define a chave do nó

    // Copiar os dados para o nó
    strncpy((char *)novoNo->dados_no, (char *)dados, tamanho_dados - 1);
    novoNo->dados_no[tamanho_dados - 1] = '\0'; 
>>>>>>> hugoV1

    novoNo->no_anterior = lst->ultimo_no;           // Define o nó anterior como o último nó atual
    novoNo->proximo_no = -1;              

<<<<<<< HEAD
void MyDLLFindPrevious(){};
=======
    
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
>>>>>>> hugoV1
