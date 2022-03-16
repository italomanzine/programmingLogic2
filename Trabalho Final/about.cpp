#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    setWindowTitle("Nova Venda");

    QPixmap pix("/linguagem_prog_II/QT_projects/projeto_final/foto_ItaloManzine.jpg");
     int w = ui->label_picture->width();
     int h = ui->label_picture->height();
     ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

about::~about()
{
    delete ui;
}
