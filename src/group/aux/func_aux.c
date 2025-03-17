#include "myDLL.h"

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