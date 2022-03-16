#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "algorithmdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Conversor");
    ui->Result->setText("0,0");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionInforma_o_sobre_o_autor_triggered()
{
     MyDialog mDialog;
     mDialog.setModal(true);
     mDialog.exec();

}


void MainWindow::on_actionSobre_o_algoritmo_triggered()
{
    algorithmDialog mDialog;
    mDialog.setModal(true);
    mDialog.exec();
}


void MainWindow::on_exit_clicked()
{
    close();
}

// CONVERSÕES DE COMPRIMENTO
void MainWindow::on_mm_m_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .001 ) );
}


void MainWindow::on_m_mm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1000 ) );
}


void MainWindow::on_cm_m_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .01 ) );
}


void MainWindow::on_m_cm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 100 ) );
}


void MainWindow::on_cm_km_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .00001 ) );
}


void MainWindow::on_km_cm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 100000 ) );
}


void MainWindow::on_m_mile_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .00062 ) );
}


void MainWindow::on_mile_m_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1609.344 ) );
}


void MainWindow::on_km_mile_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .6213712 ) );
}


void MainWindow::on_mile_km_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1.60934 ) );
}


void MainWindow::on_feet_m_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .3048 ) );
}


void MainWindow::on_m_feet_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 3.28084 ) );
}


void MainWindow::on_inch_m_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .0254 ) );
}


void MainWindow::on_m_inch_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 39.37008 ) );
}


void MainWindow::on_yard_m_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 0.9144 ) );
}


void MainWindow::on_m_yard_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1.09361 ) );
}

// CONVERSÕES DE PESO
void MainWindow::on_milligm_gm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .001 ) );
}


void MainWindow::on_gm_milligm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1000 ) );
}


void MainWindow::on_gm_kg_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .001 ) );
}


void MainWindow::on_kg_gm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1000 ) );
}


void MainWindow::on_pound_kg_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .45359 ) );
}


void MainWindow::on_kg_pound_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 2.20462 ) );
}


void MainWindow::on_gm_pound_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .0022 ) );
}


void MainWindow::on_pound_gm_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 453.59237 ) );
}


void MainWindow::on_kg_ton_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * .001 ) );
}


void MainWindow::on_ton_kg_clicked()
{
    ui->Result->setText( QString::number( ui->und->value() * 1000 ) );
}

