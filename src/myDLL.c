/** \file myDLL.c 
 *  \brief Implementação das funções para desenvolver uma lista duplamente ligada.
 * 
 * \authors Joana Duarte, nmec: 102608
 * \authors Hugo Miranda, nemc: 104348
 * \date 18 Março 2025
 * \bug  Sem bugs
 */

 #include "myDLL.h"

 /**    
  *   \brief Inicializar a lista duplamente ligada.
  * 
  *  Esta função configura os valores iniciais da estrutura da lista, garantindo  que ela esteja vazia.
  * 
  * \param[in] DLL -> Ponteiro para a estrutura da lista a ser inicializada.
  *
  */
 
 void MyDLLInit(lista *DLL)
 {
             
     DLL->no_atual = -1;                           //-1 que significa indice "nulo" , referência:https://stackoverflow.com/questions/54463503/array-implementation-of-doubly-linked-list
     DLL->primeiro_no = -1;                        
     DLL->ultimo_no = -1; 
     DLL->numero_no = 0;                         
     DLL->p_no_atual = NULL;                                                 
     
 };

 /**
 *   \brief Insere um novo nó na lista duplamente ligada, garantindo o bom funcionamento da lista.
 *
 *  Esta função permite inserir um novo nó na lista, garantindo que não haja duplicação de chaves 
 *  e respeitando o limite de elementos que a lista pode ter lista.
 * 
 * \param[in] lst   -> Ponteiro para a estrutura da lista onde o nó será inserido.
 * \param[in] chave -> Identificador único do nó a ser inserido.
 * \param[in] dados -> Ponteiro para os dados a serem armazenados no nó.
 * 
 */

void MyDLLInsert(lista *lst, uint16_t chave, const unsigned char *dados) {  //ESta referência foi util para perceber como funciona a função insert:https://www.geeksforgeeks.org/insert-a-node-at-the-end-of-doubly-linked-list/

    // Criar  novo nó
    no *novoNo = &lst->array_nos[lst->numero_no];   
    novoNo->chave_no = chave;                       

    // Verifica se a lista está cheia
    if (lst->numero_no < numero_nos){
    }else{ 
        printf("\n Lista cheia!\n");

        return;
    }


    for (int i = 0; i < lst->numero_no; i++) {

        if (lst->array_nos[i].chave_no == chave) {      // Verifica se a chave já existe na lista

            printf("\n A chave já existe!\n");

            return;
        }
    }
    
    //copia os dados para o nóó
    memcpy(novoNo->dados_no, dados, tamanho_dados); //Referência: https://labex.io/tutorials/cpp-how-to-safely-copy-memory-in-c-419094

    novoNo->proximo_no = -1;        

    //atuliza o nó anterior
    novoNo->no_anterior = lst->ultimo_no;           
              
    //Atualizar as referẽncias 
    if (lst->numero_no != 0) {         // Se já existem nós na lista      

        lst->array_nos[lst->numero_no- 1].proximo_no = lst->numero_no;   
        novoNo->no_anterior = lst->numero_no - 1;                        
        lst->ultimo_no = lst->numero_no;            

    } else {                        //senão existirem nós
        lst->no_atual = lst->numero_no;    
        lst->primeiro_no = lst->numero_no;
        lst->ultimo_no = lst->numero_no;   
        lst->p_no_atual = novoNo;      
    }

    lst->numero_no++; 
}

/**
 * \brief Remove um nó da lista duplamente ligada com base na chave fornecida.
 * 
 * Esta função remove um nó identificado pela sua chave, garantindo a reestruturação da lista 
 * para manter a integridade dos ponteiros e evitar espaços vazios entre os elementos.
 * 
 * \param[in] list -> Ponteiro para a estrutura da lista.
 * \param[in] id   -> Chave do nó a ser removido.
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

/**
 * \brief Encontra um nó a partir da chave.
 * 
 * Esta função percorre a lista duplamente ligada e retorna um ponteiro para o nó encontrado que tem a chave fornecida.
 * 
 * \param[in] list -> Ponteiro para a estrutura da lista.
 * \param[in] id   -> Identificador do nó a ser encontrado.
 * \return Ponteiro para o nó encontrado.
 */


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


 /**
 * \brief Retorna o elemento anterior ou seguinte do elemento com a chave especificada.
 * 
 * \param[in] list -> Ponteiro para a estrutura da lista.
 * \param[in] find -> Indica nó anterior ou seguinte que o utilizador pretende encontrar.
 * \param[in] id   -> Identificador do nó.
 * \return Ponteiro para o nó encontrado ou NULL se o nóo não for encontrado.
 */


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