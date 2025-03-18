/** \file myDLL_init.c 
 *  \brief Inicializar a lista duplamente ligada.
 * 
 *  Esta função configura os valores iniciais da estrutura da lista, garantindo 
 *  que ela esteja vazia.
 * 
 *  \authors Joana Duarte(102608), Hugo Miranda(104348)
 *  \date 18 Março 2025
 *  \bug  Sem bugs
 */

#include "myDLL.h"

/**
 
 * 
 * \param[in] lista DLL  Ponteiro para a estrutura da lista a ser inicializada.
 
 */

void MyDLLInit(lista *DLL)
{
            
    DLL->no_atual = -1;                           //-1 para permitir dar debug da lista
    DLL->primeiro_no = -1;                        
    DLL->ultimo_no = -1; 
    DLL->numero_no = 0;                         
    DLL->p_no_atual = NULL;                                                 
    
};