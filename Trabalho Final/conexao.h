#ifndef CONEXAO_H
#define CONEXAO_H
#include <QtSql>

class Conexao
{
public:
    QSqlDatabase bancoDeDados;
    QString local;
    QString banco;
    Conexao()
    {
        local=qApp->applicationDirPath();
        //banco=local+"/db/controlEstoque.db";
        banco="D:\\linguagem_prog_II\\QT_projects\\projeto_final\\db\\controlEstoque.db";
        bancoDeDados= QSqlDatabase::addDatabase("QSQLITE");
    }

    void fechar()
    {
        bancoDeDados.close();
    }

    bool abrir()
    {
        //inicia o banco de dados
        bancoDeDados.setDatabaseName(banco);

        //verifica se está conhectado ao banco de dados
        if(!bancoDeDados.open())
        {
            return false;
        }else{
            return true;
        }
    }

    //verifica se o banco de dados está aberto
    bool aberto()
    {
        if(bancoDeDados.isOpen())
        {
            return true;
        }else{
            return false;
        }
    }

};

#endif // CONEXAO_H
