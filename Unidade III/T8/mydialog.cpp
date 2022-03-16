#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    QPixmap pix("/linguagem_prog_II/QT_projects/T8/foto_ItaloManzine.jpg");
     int w = ui->label_picture->width();
     int h = ui->label_picture->height();
     ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MyDialog::~MyDialog()
{
    delete ui;
}
