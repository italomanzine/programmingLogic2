#include "algorithmdialog.h"
#include "ui_algorithmdialog.h"

algorithmDialog::algorithmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::algorithmDialog)
{
    ui->setupUi(this);
}

algorithmDialog::~algorithmDialog()
{
    delete ui;
}
