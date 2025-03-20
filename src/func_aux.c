/** \file func_aux.c 
 *  \brief Funções Auxiliares para validar a chave e para validar os dados.
 *  
 *  \authors Joana Duarte(102608), Hugo Miranda(104348)
 *  \date 18 Março 2025
 *  \bug  Sem bugs
 * 
 * 
 */

#include "myDLL.h"

/**
 *  \brief Função auxiliar para validar a chave.
 * 
 *  Esta função recebe um ponteiro para a chave e realiza a validação da mesma.
 * 
 *  \param[in]  chave  Ponteiro para a chave que vai ser validada
 * 
 */

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

        // Remover '\n' , se existir 
        entrada[strcspn(entrada, "\n")] = '\0';         //Referência: https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input

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

        //Converter string para numero
        valor = strtol(entrada, &aux, 10);          //Referência: https://www.geeksforgeeks.org/convert-string-to-int-in-c/#2-convert-string-to-int-using-strtol-function

        if (*aux != '\0') {                         // verificar caracteres inválidos na conversão
            printf("\nErro! Insira apenas números.\n");
            continue;
        }

        if (valor < 0 || valor > 65535) {
            printf("\nErro! O número deve estar entre 0 e 65535.\n");
            continue;
        }

        *chave = (uint16_t)valor;
        valido = 1;   // Entrada válida-> sair do loop
    }
}


/**
 *  \brief Função auxiliar para validar os dados.
 * 
 *  Esta função recebe um ponteiro para um conjunto de dados e verifica a sua validade.
 * 
 *  \param[in] dados Ponteiro para os dados a serem validados.
 * 
 */

void ValidarDados(unsigned char *dados) {
    //getchar();
    printf("Inserir dados: ");

    // Agora, lê os dados
    if (fgets((char *)dados, tamanho_dados, stdin) == NULL) {

        printf("\nErro na leitura dos dados. Tente novamente.\n");
    }

    // Remover o caracter "\n"
    dados[strcspn((char *)dados, "\n")] = '\0';

}