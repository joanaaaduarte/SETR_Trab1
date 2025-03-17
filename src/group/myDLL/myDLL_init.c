#include "myDLL.h"

void MyDLLInit(lista *DLL)
{
            
    DLL->no_atual = -1;                           
    DLL->primeiro_no = -1;                        
    DLL->ultimo_no = -1; 
    DLL->numero_no = 0;                         
    DLL->p_no_atual = NULL;                                                 
    
};