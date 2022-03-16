#include "funcoes_globais.h"

funcoes_globais::funcoes_globais()
{

}

//Função para remover linhas e evitar a duplicação quando troca de abas
void funcoes_globais::removerLinhas(QTableWidget *tw)
{
    while(tw->rowCount()>0)
    {
        tw->removeRow(0);
    }
}
