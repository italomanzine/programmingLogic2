#include "fm_gestaocolaboradores.h"
#include "ui_fm_gestaocolaboradores.h"
#include <QMessageBox>
#include <QSql>
#include "funcoes_globais.h"

fm_gestaoColaboradores::fm_gestaoColaboradores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_gestaoColaboradores)
{
    ui->setupUi(this);
    setWindowTitle("Gestão Colaboradores");

    if(!con.aberto())
    {
        if(!con.abrir())
        {
            QMessageBox::warning(this,"ERRO", "Erro ao abrir o banco de dados");
        }

        ui->cb_acesso_novoColab->addItem("A");
        ui->cb_acesso_novoColab->addItem("B");
        ui->cb_ge_acesso->addItem("A");
        ui->cb_ge_acesso->addItem("B");
        ui->txt_nome_novoColab->setFocus();

        ui->tabWidget->setCurrentIndex(0);

        ui->tw_ge_listaColab->setColumnCount(2);
        ui->tw_ge_listaColab->setColumnWidth(0,50);
        ui->tw_ge_listaColab->setColumnWidth(1,100);
        QStringList cabecalhos={"ID", "Nome"};
        ui->tw_ge_listaColab->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_ge_listaColab->setStyleSheet("QTableView {selection-background-color:blue}");
        ui->tw_ge_listaColab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_ge_listaColab->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_ge_listaColab->verticalHeader()->setVisible(false);
    }
}

fm_gestaoColaboradores::~fm_gestaoColaboradores()
{
    delete ui;
}

void fm_gestaoColaboradores::on_btn_novo_novoColab_clicked()
{
    ui->txt_nome_novoColab->clear();
    ui->txt_username_novoColab->clear();
    ui->txt_senha_novoColab->clear();
    ui->txt_fone_novoColab->clear();
    ui->cb_acesso_novoColab->setCurrentIndex(0);
    ui->txt_nome_novoColab->setFocus();
}

void fm_gestaoColaboradores::on_btn_gravar_novoColab_clicked()
{
    QString nome=ui->txt_nome_novoColab->text();
    QString username=ui->txt_username_novoColab->text();
    QString senha=ui->txt_senha_novoColab->text();
    QString telefone=ui->txt_fone_novoColab->text();
    QString acesso=ui->cb_acesso_novoColab->currentText();


    QSqlQuery query;
    query.prepare("insert into tb_colaboradores (nome_colab, username_colab, senha_colab, fone_colab, acesso_colab) values"
                  "('"+nome+"', '"+username+"', '"+senha+"', '"+telefone+"', '"+acesso+"') ");

    if(!query.exec())
    {
        QMessageBox::warning(this, "ERRO", "Erro ao inserir novo colaborador");
    }else{
        QMessageBox::information(this, "GRAVADO", "Colaborador gravado com sucesso");
        ui->txt_nome_novoColab->clear();
        ui->txt_username_novoColab->clear();
        ui->txt_senha_novoColab->clear();
        ui->txt_fone_novoColab->clear();
        ui->cb_acesso_novoColab->setCurrentIndex(0);
        ui->txt_nome_novoColab->setFocus();
    }
}

void fm_gestaoColaboradores::on_tabWidget_currentChanged(int index)
{
    if(index==1)
    {
        funcoes_globais::removerLinhas(ui->tw_ge_listaColab);
        int contLinhas=0;
        //Remover os produtos do TW
        QSqlQuery query;
        //query.prepare("select id_colab, nome_colab, from tb_colaboradores order by id_colab");
        query.prepare("select * from tb_colaboradores order by id_colab");
        if(query.exec())
        {
            // Rotina pra inserção das linhas na tela
            while(query.next())
            {
                ui->tw_ge_listaColab->insertRow(contLinhas);
                ui->tw_ge_listaColab->setItem(contLinhas,0,new QTableWidgetItem(query.value(0).toString()));
                ui->tw_ge_listaColab->setItem(contLinhas,1,new QTableWidgetItem(query.value(1).toString()));
                ui->tw_ge_listaColab->setRowHeight(contLinhas,20);
                contLinhas++;
            }

    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao listar colaboradores");
    }

    }
}


void fm_gestaoColaboradores::on_tw_ge_listaColab_itemSelectionChanged()
{
    int id = ui->tw_ge_listaColab->item(ui->tw_ge_listaColab->currentRow(),0)->text().toInt(); //converte o valor do id em texto para inteiro
    QSqlQuery query;
    query.prepare("select * from tb_colaboradores where id_colab="+QString::number(id));
    if(query.exec())
    {
        query.first();
        ui->txt_ge_nome->setText(query.value(1).toString());
        ui->txt_ge_username->setText(query.value(2).toString());
        ui->txt_ge_senha->setText(query.value(3).toString());
        ui->txt_ge_fone->setText(query.value(4).toString());
        ui->cb_ge_acesso->setCurrentText(query.value(5).toString());
    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao carregar as informações");
    }
}


void fm_gestaoColaboradores::on_btn_ge_filtrar_clicked()
{
    QString busca;
    funcoes_globais::removerLinhas(ui->tw_ge_listaColab);
    if(ui->txt_ge_filtro->text()=="")
    {
        if(ui->rb_ge_idColab->isChecked())
        {
            busca="select * from tb_colaboradores order by id_colab";
            //busca="select id_produtos, produto, from tb_produtos order by id_produtos";
        }else{
            busca="select * from tb_colaboradores order by nome_colab";
            //busca="select id_produtos, produto, from tb_produtos order by produto";
        }
    }else{
        if(ui->rb_ge_idColab->isChecked())
        {
            busca="select * from tb_colaboradores where id_colab ='" +ui->txt_ge_filtro->text()+ "' order by id_colab";
            //busca="select id_produtos, produto, from tb_produtos where is_produtos=" +ui->txt_ge_filtrar->text()+ "order by id_produtos";
        }else{
            busca="select * from tb_colaboradores where nome_colab like '%" +ui->txt_ge_filtro->text()+ "%' order by nome_colab";
            //busca="select id_produtos, produto, from tb_produtos where produto like '%" +ui->txt_ge_filtrar->text()+ "%' order by produto"; //Pesquisa por todos os produtos que contenham em alguma parte do seu nome a string digitada
        }
    }

    int contLinhas=0;
    QSqlQuery query;
    query.prepare(busca);
    if(query.exec())
    {
        while(query.next())
        {
            ui->tw_ge_listaColab->insertRow(contLinhas);
            ui->tw_ge_listaColab->setItem(contLinhas,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_ge_listaColab->setItem(contLinhas,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_ge_listaColab->setRowHeight(contLinhas,20);
            contLinhas++;
        }
    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao filtrar o produto");
    }

    ui->txt_ge_filtro->clear();
    ui->txt_ge_filtro->setFocus();
}


void fm_gestaoColaboradores::on_btn_ge_gravar_clicked()
{
    if(ui->tw_ge_listaColab->currentRow()==1)
    {
        QMessageBox::warning(this, "ERRO", "Selecione um colocaborador");
        return;
    }

    QString id=ui->tw_ge_listaColab->item(ui->tw_ge_listaColab->currentRow(),0)->text();
    QSqlQuery query;
    QString nome=ui->txt_ge_nome->text();
    QString username=ui->txt_ge_username->text();
    QString senha=ui->txt_ge_senha->text();
    QString fone=ui->txt_ge_fone->text();
    QString acesso=ui->cb_ge_acesso->currentText();

    query.prepare("update tb_colaboradores set nome_colab='"+nome+"', username_colab='"+username+"', senha_colab='"+senha+"', fone_colab='"+fone+"', acesso_colab='"+acesso+"' where id_colab =" +id+ "");
    if(query.exec())
    {
        int linha = ui->tw_ge_listaColab->currentRow();
        ui->tw_ge_listaColab->item(linha,1)->setText(nome);
        QMessageBox::information(this, "ATUALIZADO", "Colaborador atualizado com sucesso");

    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao atualizar o colaborador");
    }
}


void fm_gestaoColaboradores::on_btn_ge_excluir_clicked()
{
    if(ui->tw_ge_listaColab->currentRow()==1)
    {
        QMessageBox::warning(this, "ERRO", "Selecione um colocaborador");
        return;
    }

    QMessageBox::StandardButton opc = QMessageBox::question(this, "EXCLUIR", "Deseja realmente excluir o colaborador?", QMessageBox::Yes | QMessageBox::No);
    if(opc==QMessageBox::Yes)
    {
        int linha = ui->tw_ge_listaColab->currentRow();
        QString id = ui->tw_ge_listaColab->item(linha,0)->text();
        QSqlQuery query;
        query.prepare("delete from tb_colaboradores where id_colab="+id );
        if(query.exec())
        {
            ui->tw_ge_listaColab->removeRow(linha);
            QMessageBox::information(this, "EXCLUÍDO", "Colaborador excluído com sucesso");
        }else{
            QMessageBox::warning(this, "ERRO", "Erro ao excluir o colaborador");
        }
    }
}

