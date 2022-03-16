#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <fm_logar.h>
#include <fm_novavenda.h>
#include <fm_gestaoestoque.h>
#include <fm_gestaocolaboradores.h>
#include <fm_gestaovendas.h>
#include "variaveis_globais.h"
#include "about.h"

int variaveis_globais::id_colab;
QString variaveis_globais::nome_colab;
QString variaveis_globais::acesso_colab;
QString variaveis_globais::username_colab;
bool variaveis_globais::logado;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ERP Projeto Final");

    variaveis_globais::logado=false;
    cadFechado.addFile(":/img/lock.png");
    cadAberto.addFile(":/img/un_lock.png");

    ui->btn_bloquear->setText("");
    ui->btn_bloquear->setIcon(cadFechado);
    ui->statusbar->addWidget(ui->btn_bloquear);
    ui->statusbar->addWidget(ui->lb_nome);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_bloquear_clicked()
{
    if(!variaveis_globais::logado)
    {
        //chamar tela de desbloqueio
        fm_logar f_logar;
        f_logar.exec();

        if(variaveis_globais::logado)
        {
            ui->btn_bloquear->setIcon(cadAberto);
            ui->lb_nome->setText(variaveis_globais::nome_colab);
        }

    }else{
        variaveis_globais::logado=false;
        ui->btn_bloquear->setIcon(cadFechado);
        ui->lb_nome->setText("Sem colaborador");
    }
}


void MainWindow::on_pushButton_clicked()
{
    //Condiciona abertura da janela nova venda à colaboradores logados
    if(variaveis_globais::logado)
    {
        fm_novavenda f_novavenda;
        f_novavenda.exec();
    }else{
        QMessageBox::information(this, "LOGIN", "Não existe colaborador logado");
    }
}

//Condiciona abertura das guias a colaboradores com acesso tipo A
void MainWindow::on_actionEstoque_triggered()
{
    if(variaveis_globais::logado)
    {
        if(variaveis_globais::acesso_colab=="A")
        {
            fm_gestaoEstoque f_gestaoEstoque;
            f_gestaoEstoque.exec();
        }else{
            QMessageBox::information(this, "ACESSO", "Acesso não permitido");
        }
    }
}


void MainWindow::on_actionColaboradores_triggered()
{
    if(variaveis_globais::logado)
    {
        if(variaveis_globais::acesso_colab=="A")
        {
            fm_gestaoColaboradores f_gestaoColaboradores;
            f_gestaoColaboradores.exec();
        }else{
            QMessageBox::information(this, "ACESSO", "Acesso não permitido");
        }
    }
}


void MainWindow::on_actionVendas_triggered()
{
    if(variaveis_globais::logado)
    {
        if(variaveis_globais::acesso_colab=="A")
        {
            fm_gestaoVendas f_gestaoVendas;
            f_gestaoVendas.exec();
        }else{
            QMessageBox::information(this, "ACESSO", "Acesso não permitido");
        }
    }
}


void MainWindow::on_actionSobre_triggered()
{
    about fSobre;
    fSobre.setModal(true);
    fSobre.exec();
}

