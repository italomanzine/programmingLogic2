#ifndef FM_NOVAVENDA_H
#define FM_NOVAVENDA_H

#include <QDialog>
#include "conexao.h"
#include <QTableWidget>

namespace Ui {
class fm_novavenda;
}

class fm_novavenda : public QDialog
{
    Q_OBJECT

public:
    explicit fm_novavenda(QWidget *parent = nullptr);
    ~fm_novavenda();

    Conexao con;
    int contLinhas;
    void resetarCampos();
    double calcularTotal(QTableWidget *tw, int coluna);
    static QString g_idprod, g_prod, g_qtde, g_valUnitario, g_valTotal;
    static bool alterou;
    void removerLinhas(QTableWidget *tw);


private slots:
    void on_txt_codigoProduto_returnPressed();

    void on_btn_excluirProduto_clicked();


    void on_btn_editarProduto_clicked();

    void on_btn_finalizarVenda_clicked();

private:
    Ui::fm_novavenda *ui;
};

#endif // FM_NOVAVENDA_H
