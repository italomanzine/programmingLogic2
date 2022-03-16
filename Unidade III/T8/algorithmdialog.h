#ifndef ALGORITHMDIALOG_H
#define ALGORITHMDIALOG_H

#include <QDialog>

namespace Ui {
class algorithmDialog;
}

class algorithmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit algorithmDialog(QWidget *parent = nullptr);
    ~algorithmDialog();

private:
    Ui::algorithmDialog *ui;
};

#endif // ALGORITHMDIALOG_H
