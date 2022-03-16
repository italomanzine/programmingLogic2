#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QIcon cadFechado;
    QIcon cadAberto;

private slots:
    void on_btn_bloquear_clicked();

    void on_pushButton_clicked();

    void on_actionEstoque_triggered();

    void on_actionColaboradores_triggered();

    void on_actionVendas_triggered();

    void on_actionSobre_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
