#ifndef FUNCOES_GLOBAIS_H
#define FUNCOES_GLOBAIS_H

#include <QTableWidget>


class funcoes_globais
{
public:
    funcoes_globais();

    //Função para remover linhas e evitar a duplicação quando troca de abas
    static void removerLinhas(QTableWidget *tw);
};

#endif // FUNCOES_GLOBAIS_H
