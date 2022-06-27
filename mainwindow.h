#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlTableModel>
#include <QDebug>

#include "login.h" //подключения окна соединения с бд
#include "ui_login.h"

#include "add_wh.h" //подключение окна добавления склада
#include "ui_add_wh.h"

#include "add_ow.h" //подключение окна добавления организации - владельца склада
#include "ui_add_ow.h"

#include "add_stuff.h" //подключение окна добавления работников
#include "ui_add_stuff.h"

#include "add_rc_in.h" //подключения окна приходной накладной
#include "ui_add_rc_in.h"

#include "add_rc_out.h" //подключения окна расходной накладной
#include "ui_add_rc_out.h"

#include "add_product.h" // подключение окна добавления продукта
#include "ui_add_product.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    login* logwin;
    add_wh* new_wh;
    add_ow* new_owner;
    add_stuff* new_stuff;
    add_rc_in* new_receipt_in;
    add_rc_out* new_receipt_out;
    add_product* new_product;


private slots:
    void on_action_triggered();

    void on_wh_update_clicked();

    void on_ow_update_clicked();

    void on_stuff_update_clicked();

    void on_rc_update_clicked();

    void on_prod_update_clicked();

    void on_wh_add_clicked();

    void on_wh_table_clicked(const QModelIndex &index);

    void on_wh_modify_clicked();

    void on_wh_remove_clicked();

    void on_ow_add_clicked();

    void on_ow_table_clicked(const QModelIndex &index);

    void on_ow_modify_clicked();

    void on_ow_remove_clicked();

    void on_stuff_add_clicked();

    void on_stuff_table_clicked(const QModelIndex &index);

    void on_stuff_modify_clicked();

    void on_stuff_remove_clicked();

    void on_rc_in_clicked();

    void on_rc_out_clicked();

    void on_pr_search_clicked();

    void on_prod_table_clicked(const QModelIndex &index);

    void on_pr_modify_clicked();

    void on_pr_remove_clicked();

    void on_prod_sort_clicked();

    void on_prod_is_clicked();

    void on_prod_add_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *Model;
};
#endif // MAINWINDOW_H
