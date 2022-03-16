#include "fm_gestaovendas.h"
#include "ui_fm_gestaovendas.h"
#include <QtSql>
#include <QDebug>

fm_gestaoVendas::fm_gestaoVendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_gestaoVendas)
{
    ui->setupUi(this);
    setWindowTitle("Gestão Vendas");

    ui->tw_listaProdutosVendas->horizontalHeader()->setVisible(true);
    ui->tw_listaProdutosVendas->setColumnCount(5);
    QStringList cabecalho1={ "Movimentação", "Produto", "Qtde", "Valor Und.", "Valor T."};
    ui->tw_listaProdutosVendas->setHorizontalHeaderLabels(cabecalho1);
    ui->tw_listaProdutosVendas->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tw_listaProdutosVendas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_listaProdutosVendas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_listaProdutosVendas->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tw_listaVendas->horizontalHeader()->setVisible(true);
    ui->tw_listaVendas->setColumnCount(6);
    QStringList cabecalho2={ "ID", "Data", "Hora", "Colab.", "V.Total", "T.Pgto"};
    ui->tw_listaVendas->setHorizontalHeaderLabels(cabecalho2);
    ui->tw_listaVendas->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tw_listaVendas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_listaVendas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_listaVendas->setEditTriggers(QAbstractItemView::NoEditTriggers);


    con.abrir();
    int contLinhas=0;
    QSqlQuery query;
    query.prepare("select * from tb_vendas");
    query.exec();
    query.first();
    do{
        ui->tw_listaVendas->insertRow(contLinhas);
        ui->tw_listaVendas->setItem(contLinhas,0, new QTableWidgetItem(query.value(0).toString()));
        ui->tw_listaVendas->setItem(contLinhas,1, new QTableWidgetItem(query.value(1).toString()));
        ui->tw_listaVendas->setItem(contLinhas,2, new QTableWidgetItem(query.value(2).toString()));
        ui->tw_listaVendas->setItem(contLinhas,3, new QTableWidgetItem(query.value(3).toString()));
        ui->tw_listaVendas->setItem(contLinhas,4, new QTableWidgetItem(query.value(4).toString()));
        ui->tw_listaVendas->setItem(contLinhas,5, new QTableWidgetItem(query.value(5).toString()));
        contLinhas++;
    }while(query.next());

    con.fechar();
}

fm_gestaoVendas::~fm_gestaoVendas()
{
    delete ui;
}

void fm_gestaoVendas::on_tw_listaVendas_itemSelectionChanged()
{
    //ui->tw_listaProdutosVendas->clear();
    ui->tw_listaProdutosVendas->setRowCount(0);

    con.abrir();
    int contLinhas=0;
    QSqlQuery query;
    query.prepare("select id_movimentacao, produto, qtde, valor_un, valor_total from tb_produtosVendas where id_venda="+ui->tw_listaVendas->item(ui->tw_listaVendas->currentRow(),0)->text());
    query.exec();
    query.first();
    do{
        ui->tw_listaProdutosVendas->insertRow(contLinhas);
        ui->tw_listaProdutosVendas->setItem(contLinhas,0, new QTableWidgetItem(query.value(0).toString()));
        ui->tw_listaProdutosVendas->setItem(contLinhas,1, new QTableWidgetItem(query.value(1).toString()));
        ui->tw_listaProdutosVendas->setItem(contLinhas,2, new QTableWidgetItem(query.value(2).toString()));
        ui->tw_listaProdutosVendas->setItem(contLinhas,3, new QTableWidgetItem(query.value(3).toString()));
        ui->tw_listaProdutosVendas->setItem(contLinhas,4, new QTableWidgetItem(query.value(4).toString()));
        contLinhas++;
    }while(query.next());

    con.fechar();
}


void fm_gestaoVendas::on_btn_filtrar_clicked()
{
    ui->tw_listaVendas->setRowCount(0);

    con.abrir();
    int contLinhas=0;
    QSqlQuery query;
    query.prepare("select * from tb_vendas where data_venda between'"+ui->de_dataini->text()+ "' and '"+ui->de_datafim->text()+"' ");
    query.exec();
    query.first();
    do{
        ui->tw_listaVendas->insertRow(contLinhas);
        ui->tw_listaVendas->setItem(contLinhas,0, new QTableWidgetItem(query.value(0).toString()));
        ui->tw_listaVendas->setItem(contLinhas,1, new QTableWidgetItem(query.value(1).toString()));
        ui->tw_listaVendas->setItem(contLinhas,2, new QTableWidgetItem(query.value(2).toString()));
        ui->tw_listaVendas->setItem(contLinhas,3, new QTableWidgetItem(query.value(3).toString()));
        ui->tw_listaVendas->setItem(contLinhas,4, new QTableWidgetItem(query.value(4).toString()));
        ui->tw_listaVendas->setItem(contLinhas,5, new QTableWidgetItem(query.value(5).toString()));
        contLinhas++;
    }while(query.next());

    con.fechar();
}

