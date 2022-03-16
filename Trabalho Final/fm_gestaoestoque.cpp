#include "fm_gestaoestoque.h"
#include "ui_fm_gestaoestoque.h"
#include <QtSql>
#include "funcoes_globais.h"

fm_gestaoEstoque::fm_gestaoEstoque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_gestaoEstoque)
{
    ui->setupUi(this);
    setWindowTitle("Gestão Estoque");

    if(!con.abrir())
    {
        QMessageBox::warning(this, "ERRO", "Erro ao abrir o banco de dados");
    }else{
        QSqlQuery query;
        query.prepare("select * from tb_produtos");
        if(query.exec())
        {

        }else{
            QMessageBox::warning(this, "ERRO", "Erro ao listar os produtos");
        }
    }

    ui->tw_ge_produtos->setColumnCount(2);
    ui->tabWidget->setCurrentIndex(0);
}

fm_gestaoEstoque::~fm_gestaoEstoque()
{
    delete ui;
    con.fechar();
}

void fm_gestaoEstoque::on_btn_novoProduto_clicked()
{
    ui->txt_codigoProduto->clear();
    ui->txt_descricaoProduto->clear();
    ui->txt_fornecedor->clear();
    ui->txt_qtdeEstoque->clear();
    ui->txt_valorCompra->clear();
    ui->txt_valorVenda->clear();
    ui->txt_codigoProduto->setFocus();
}

//Grava um novo produto no banco de dados
void fm_gestaoEstoque::on_btn_gravarNovoProduto_clicked()
{
    QString aux;
    QString codigo=ui->txt_codigoProduto->text();
    QString produto=ui->txt_descricaoProduto->text();
    QString fornecedor=ui->txt_fornecedor->text();
    QString quantidade=ui->txt_qtdeEstoque->text();

    aux=ui->txt_valorCompra->text();
    std::replace(aux.begin(), aux.end(), ',', '.'); // Converte a ',' que o usuário digitou em em '.'
    QString valCompra=aux;

    aux=ui->txt_valorVenda->text();
    std::replace(aux.begin(), aux.end(), ',', '.'); // Converte a ',' que o usuário digitou em em '.'
    QString valVenda=aux;

    QSqlQuery query;
    query.prepare("insert into tb_produtos (id_produtos, produto, id_fornecedor, qtde_estoque, valor_compra, valor_venda) values"
                  "("+QString::number(codigo.toInt())+", '"+produto+"', "+QString::number(fornecedor.toInt())+", "+QString::number(quantidade.toInt())+", "+QString::number(valCompra.toFloat())+", "+QString::number(valVenda.toFloat())+" ) ");

    if(!query.exec())
    {
        QMessageBox::warning(this, "ERRO", "Erro ao inserir produto");
    }else{
        QMessageBox::information(this, "GRAVADO", "Produto inserido com sucesso");
        ui->txt_codigoProduto->clear();
        ui->txt_descricaoProduto->clear();
        ui->txt_fornecedor->clear();
        ui->txt_qtdeEstoque->clear();
        ui->txt_valorCompra->clear();
        ui->txt_valorVenda->clear();
        ui->txt_codigoProduto->setFocus();
    }
}



void fm_gestaoEstoque::on_tabWidget_currentChanged(int index)
{
    if(index==1)
    {
        funcoes_globais::removerLinhas(ui->tw_ge_produtos);
        int contLinhas=0;
        //Remover os produtos do TW
        QSqlQuery query;
        //query.prepare("select id_produtos, produto, from tb_produtos order by produto");
        query.prepare("select * from tb_produtos order by produto");
        if(query.exec())
        {
            // Rotina pra inserção das linhas na tela
            while(query.next())
            {
                ui->tw_ge_produtos->insertRow(contLinhas);
                ui->tw_ge_produtos->setItem(contLinhas,0,new QTableWidgetItem(query.value(0).toString()));
                ui->tw_ge_produtos->setItem(contLinhas,1,new QTableWidgetItem(query.value(1).toString()));
                ui->tw_ge_produtos->setRowHeight(contLinhas,20);
                contLinhas++;
            }

            //Estilização da Table Widget tw_ge_produtos
            ui->tw_ge_produtos->setColumnWidth(0,150);
            ui->tw_ge_produtos->setColumnWidth(1,230);
            QStringList cabecalhos={"Código", "Produto"};
            ui->tw_ge_produtos->setHorizontalHeaderLabels(cabecalhos);
            ui->tw_ge_produtos->setStyleSheet("QTableView {selection-background-color:blue}");
            ui->tw_ge_produtos->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tw_ge_produtos->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tw_ge_produtos->verticalHeader()->setVisible(false);

        }else{
            QMessageBox::warning(this, "ERRO", "Erro ao listar os produto");
        }

    }
}


//Migra as informações do produto selecionado para os Line edit a esquerda do Table Widget
void fm_gestaoEstoque::on_tw_ge_produtos_itemSelectionChanged()
{
    int id = ui->tw_ge_produtos->item(ui->tw_ge_produtos->currentRow(),0)->text().toInt(); //converte o valor do id em texto para inteiro
    QSqlQuery query;
    query.prepare("select * from tb_produtos where id_produtos="+QString::number(id));
    if(query.exec())
    {
        query.first();
        ui->txt_ge_codigoProduto->setText(query.value(0).toString());
        ui->txt_ge_produto->setText(query.value(1).toString());
        ui->txt_ge_fornecedor->setText(query.value(2).toString());
        ui->txt_ge_qtde->setText(query.value(3).toString());
        ui->txt_ge_valorCompra->setText(query.value(4).toString());
        ui->txt_ge_valorVenda->setText(query.value(5).toString());
    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao carregar as informações");
    }
}

//Edita atributos dos produtos na aba gestão de produtos
void fm_gestaoEstoque::on_btn_ge_gravar_clicked()
{
    //verifica se tem algum produto selecionado
    if(ui->txt_ge_codigoProduto->text()=="")
    {
        QMessageBox::warning(this, "ERRO", "Selecione um produto");
    }else{
        int id = ui->tw_ge_produtos->item(ui->tw_ge_produtos->currentRow(),0)->text().toInt();
        QString aux;
        QString prod = ui->txt_ge_produto->text();
        QString forn = ui->txt_ge_fornecedor->text();
        QString qtde = ui->txt_ge_qtde->text();

        aux = ui->txt_ge_valorCompra->text();
        std::replace(aux.begin(),aux.end(), ',', '.');
        QString valCompra=aux;

        aux = ui->txt_ge_valorVenda->text();
        std::replace(aux.begin(),aux.end(), ',', '.');
        QString valVenda=aux;

        QSqlQuery query;
        query.prepare("update tb_produtos set id_produtos="+QString::number(id)+ ", produto='"+prod+"', id_fornecedor="+QString::number(forn.toInt())+", qtde_estoque="+QString::number(qtde.toInt())+", valor_compra="+QString::number(valCompra.toDouble())+", valor_venda="+QString::number(valVenda.toDouble())+" where id_produtos="+QString::number(id)+" ");
        if(query.exec())
        {
            int linha = ui->tw_ge_produtos->currentRow();
            ui->tw_ge_produtos->item(linha,0)->setText(ui->txt_ge_codigoProduto->text());
            ui->tw_ge_produtos->item(linha,1)->setText(prod);
            QMessageBox::information(this, "ATUALIZADO", "Produto atualizado com sucesso");

        }else{
            QMessageBox::warning(this, "ERRO", "Erro ao atualizar o produto");
        }
    }
}

//Exclui um produto do banco de dados
void fm_gestaoEstoque::on_btn_ge_excluir_clicked()
{
    if(ui->txt_ge_codigoProduto->text()=="")
    {
        QMessageBox::warning(this, "ERRO", "Selecione um produto");
    }else{
        QMessageBox::StandardButton opc = QMessageBox::question(this, "EXCLUIR", "Deseja realmente excluir o produto?", QMessageBox::Yes | QMessageBox::No);
        if(opc==QMessageBox::Yes)
        {
            int linha = ui->tw_ge_produtos->currentRow();
            int id = ui->tw_ge_produtos->item(linha,0)->text().toInt();
            QSqlQuery query;
            query.prepare("delete from tb_produtos where id_produtos="+QString::number(id));
            if(query.exec())
            {
                ui->tw_ge_produtos->removeRow(linha);
                QMessageBox::information(this, "EXCLUÍDO", "Produto excluído com sucesso");
            }else{
                QMessageBox::warning(this, "ERRO", "Erro ao excluir o produto");
            }
        }
    }
}

//Função para pesquisar/filtrar produtos na lista
void fm_gestaoEstoque::on_btn_ge_pesquisar_clicked()
{
    QString busca;
    funcoes_globais::removerLinhas(ui->tw_ge_produtos);
    if(ui->txt_ge_filtrar->text()=="")
    {
        if(ui->rb_ge_codigo->isChecked())
        {
            busca="select * from tb_produtos order by id_produtos";
            //busca="select id_produtos, produto, from tb_produtos order by id_produtos";
        }else{
            busca="select * from tb_produtos order by produto";
            //busca="select id_produtos, produto, from tb_produtos order by produto";
        }
    }else{
        if(ui->rb_ge_codigo->isChecked())
        {
            busca="select * from tb_produtos where id_produtos ='" +ui->txt_ge_filtrar->text()+ "' order by id_produtos";
            //busca="select id_produtos, produto, from tb_produtos where is_produtos=" +ui->txt_ge_filtrar->text()+ "order by id_produtos";
        }else{
            busca="select * from tb_produtos where produto like '%" +ui->txt_ge_filtrar->text()+ "%' order by produto";
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
            ui->tw_ge_produtos->insertRow(contLinhas);
            ui->tw_ge_produtos->setItem(contLinhas,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_ge_produtos->setItem(contLinhas,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_ge_produtos->setRowHeight(contLinhas,20);
            contLinhas++;
        }
    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao filtrar o produto");
    }

    ui->txt_ge_filtrar->clear();
    ui->txt_ge_filtrar->setFocus();
}

