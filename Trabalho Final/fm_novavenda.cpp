#include "fm_novavenda.h"
#include "ui_fm_novavenda.h"
#include <QMessageBox>
#include <fm_editarprodutovenda.h>
#include "mainwindow.h"
#include "variaveis_globais.h"

QString fm_novavenda::g_idprod;
QString fm_novavenda::g_prod;
QString fm_novavenda::g_qtde;
QString fm_novavenda::g_valUnitario;
QString fm_novavenda::g_valTotal;
bool fm_novavenda::alterou;


fm_novavenda::fm_novavenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_novavenda)
{
    ui->setupUi(this);
    setWindowTitle("Nova Venda");

    //Verifica se a conexão já está aberta
    if(!con.aberto())
    {
        if(!con.abrir())
        {
            QMessageBox::warning(this,"ERRO", "Erro ao abrir o banco de dados");
        }

    }

    //Estilização da Table Widget tw_listaProdutos
    ui->tw_listaProdutos->setColumnCount(5);
    ui->tw_listaProdutos->setColumnWidth(0,100);
    ui->tw_listaProdutos->setColumnWidth(1,200);
    ui->tw_listaProdutos->setColumnWidth(2,100);
    ui->tw_listaProdutos->setColumnWidth(3,100);
    ui->tw_listaProdutos->setColumnWidth(4,100);
    QStringList cabecalhos{"Código", "Produto", "Valor un.", "Qtde", "Total"};
    ui->tw_listaProdutos->setHorizontalHeaderLabels(cabecalhos);
    ui->tw_listaProdutos->setStyleSheet("QTableView{selection-background-color:blue;}");
    ui->tw_listaProdutos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tw_listaProdutos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_listaProdutos->verticalHeader()->setVisible(false);

    ui->txt_codigoProduto->setFocus();
    contLinhas=0;
}

fm_novavenda::~fm_novavenda()
{
    delete ui;
}

//Insere os produtos no carrinho de compras
void fm_novavenda::on_txt_codigoProduto_returnPressed()
{
    QSqlQuery query;
    QString id = ui->txt_codigoProduto->text();
    double valTotal;
    query.prepare("select id_produtos, produto, valor_venda from tb_produtos where id_produtos="+id);
    if(query.exec())
    {
        query.first();
        if(query.value(0).toString()!="")
        {
            ui->tw_listaProdutos->insertRow(contLinhas);
            ui->tw_listaProdutos->setItem(contLinhas, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_listaProdutos->setItem(contLinhas, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_listaProdutos->setItem(contLinhas, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tw_listaProdutos->setItem(contLinhas, 3, new QTableWidgetItem(ui->txt_qtde->text()));
            valTotal=ui->txt_qtde->text().toDouble()*query.value(2).toDouble();
            ui->tw_listaProdutos->setItem(contLinhas, 4, new QTableWidgetItem(QString::number(valTotal)));
            ui->tw_listaProdutos->setRowHeight(contLinhas,20);
            contLinhas++;
            ui->lb_totalVendas->setText("R$ "+QString::number(calcularTotal(ui->tw_listaProdutos,4)));
        }else{
            QMessageBox::warning(this,"ERRO", "Produto não encontrado");
        }

        resetarCampos();

    }else{
        QMessageBox::warning(this,"ERRO", "Erro ao inserir o produto");
    }
}

void fm_novavenda::resetarCampos()
{
    ui->txt_codigoProduto->clear();
    ui->txt_qtde->setText("1");
    ui->txt_codigoProduto->setFocus();
}

void fm_novavenda::removerLinhas(QTableWidget *tw)
{
    while(tw->rowCount()>0)
    {
        tw->removeRow(0);
    }
}

double fm_novavenda::calcularTotal(QTableWidget *tw, int coluna)
{
    int totalLinhas;
    double total;

    totalLinhas = tw->rowCount();
    for(int i=0; i<totalLinhas; i++)
    {
        total+=tw->item(i,coluna)->text().toDouble();
    }
    return total;
}

//Função para excluir o produto no carrinho de compras
void fm_novavenda::on_btn_excluirProduto_clicked()
{
    if(ui->tw_listaProdutos->currentColumn()!=-1)
    {
        QMessageBox::StandardButton opc = QMessageBox::question(this, "EXCLUIR", "Deseja realmente excluir o produto?", QMessageBox::Yes | QMessageBox::No);
        if(opc==QMessageBox::Yes)
        {
            ui->tw_listaProdutos->removeRow(ui->tw_listaProdutos->currentRow());
            ui->lb_totalVendas->setText("R$ "+QString::number(calcularTotal(ui->tw_listaProdutos,4)));
            contLinhas--;
        }
    }else{
        QMessageBox::warning(this,"ERRO", "Selecione um produto primeiro");
    }
}


//Função para editar um produto durante a compra
void fm_novavenda::on_btn_editarProduto_clicked()
{
    if(ui->tw_listaProdutos->currentColumn()!=-1)
    {
        int linha = ui->tw_listaProdutos->currentRow();

        g_idprod = ui->tw_listaProdutos->item(linha,0)->text();
        g_prod = ui->tw_listaProdutos->item(linha,1)->text();
        g_valUnitario = ui->tw_listaProdutos->item(linha,2)->text();
        g_qtde = ui->tw_listaProdutos->item(linha,3)->text();
        fm_editarprodutovenda f_editarprodutovenda;
        f_editarprodutovenda.exec();

        if(alterou)
        {
            ui->tw_listaProdutos->item(linha,2)->setText(g_valUnitario);
            ui->tw_listaProdutos->item(linha,3)->setText(g_qtde);
            ui->tw_listaProdutos->item(linha,4)->setText(g_valTotal);

            ui->lb_totalVendas->setText("R$ "+QString::number(calcularTotal(ui->tw_listaProdutos,4)));
        }
    }
}


void fm_novavenda::on_btn_finalizarVenda_clicked()
{
    if(ui->tw_listaProdutos->rowCount()>0)
    {
        int idVenda;
        QString msgFimVenda;
        double total=calcularTotal(ui->tw_listaProdutos,4);
        //QString data=QDate::currentDate().toString("yyyy-MM-dd");
        QString data=QDate::currentDate().toString("dd-MM-yyyy");
        QString hora=QTime::currentTime().toString("hh:mm:ss");
        QSqlQuery query;
        query.prepare("insert into tb_vendas (data_venda, hora_venda, id_colaborador, valor_total, id_tipo_pagamento) values('"+data+"', '"+hora+"', "+QString::number(variaveis_globais::id_colab)+", "+QString::number(total)+", 1)");
        if(!query.exec()){
            QMessageBox::warning(this,"ERRO", "Erro ao registrar nova venda");
        }else{
            query.prepare("select id_venda from tb_vendas order by id_venda desc limit 1");
            query.exec();
            query.first();
            idVenda=query.value(0).toInt();
            msgFimVenda = "ID Venda: "+QString::number(idVenda)+"\nValor total: R$"+QString::number(total);

            int totalLinhas=ui->tw_listaProdutos->rowCount();
            int linha=0;
            while(linha<totalLinhas)
            {
                QString prod=ui->tw_listaProdutos->item(linha,1)->text();
                QString qtde=ui->tw_listaProdutos->item(linha,3)->text();
                QString valUn=ui->tw_listaProdutos->item(linha,2)->text();
                QString valTot=ui->tw_listaProdutos->item(linha,4)->text();
                query.prepare("insert into tb_produtosVendas (id_venda, produto, qtde, valor_un, valor_total) values("+QString::number(idVenda)+", '"+prod+"', "+qtde+", "+valUn+", "+valTot+")");
                query.exec();
                linha++;
            }

            QMessageBox::information(this,"Venda concluída", msgFimVenda);
            resetarCampos();
            removerLinhas(ui->tw_listaProdutos);
            ui->lb_totalVendas->setText("R$ 0.00");
        }
    }else{
        QMessageBox::warning(this,"ERRO", "Não existem produtos nessa venda\nPrimeiro adicione um produto");
    }
}

