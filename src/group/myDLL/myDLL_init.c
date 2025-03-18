/** \brief myDDL_init.c 
 *  \brief 
 * 
 *  \authors Joana Duarte, Hugo Miranda
 *  \date 18 Março 2025
 */

#include "myDLL.h"

/**
 * Esta função configura os valores iniciais da estrutura da lista, garantindo 
 * que ela esteja vazia.
 * 
 * \param[in] DLL Ponteiro para a estrutura da lista a ser inicializada.
 
 */

void MyDLLInit(lista *DLL)
{
            
    DLL->no_atual = -1;                           
    DLL->primeiro_no = -1;                        
    DLL->ultimo_no = -1; 
    DLL->numero_no = 0;                         
    DLL->p_no_atual = NULL;                                                 
    
};