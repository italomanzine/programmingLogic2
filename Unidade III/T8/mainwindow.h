#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionInforma_o_sobre_o_autor_triggered();

    void on_actionSobre_o_algoritmo_triggered();

    void on_exit_clicked();

// CONVERSÕES DE COMPRIMENTO
    void on_mm_m_clicked();

    void on_m_mm_clicked();

    void on_cm_m_clicked();

    void on_m_cm_clicked();

    void on_cm_km_clicked();

    void on_km_cm_clicked();

    void on_m_mile_clicked();

    void on_mile_m_clicked();

    void on_km_mile_clicked();

    void on_mile_km_clicked();

    void on_feet_m_clicked();

    void on_m_feet_clicked();

    void on_inch_m_clicked();

    void on_m_inch_clicked();

    void on_yard_m_clicked();

    void on_m_yard_clicked();

// CONVERSÕES DE PESO
    void on_milligm_gm_clicked();

    void on_gm_milligm_clicked();

    void on_gm_kg_clicked();

    void on_kg_gm_clicked();

    void on_pound_kg_clicked();

    void on_kg_pound_clicked();

    void on_gm_pound_clicked();

    void on_pound_gm_clicked();

    void on_kg_ton_clicked();

    void on_ton_kg_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
