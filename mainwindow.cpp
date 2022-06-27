#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Application");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Model;
}


void MainWindow::on_action_triggered() //подключение
{
    logwin = new login();
    logwin->show();
}

// обновление таблиц
void MainWindow::on_wh_update_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("wh_ow");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Название склада");
    Model->setHeaderData(1,Qt::Horizontal, "Адрес склада");
    Model->setHeaderData(2,Qt::Horizontal, "Владелец склада");
    Model->setHeaderData(3,Qt::Horizontal, "Количество свободных мест");

    ui->wh_table->setModel(Model);
    ui->wh_table->resizeColumnsToContents();
    ui->wh_table->show();

}


void MainWindow::on_ow_update_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("owner_warehouse");
    Model->select();

    Model->setHeaderData(1,Qt::Horizontal, "Название Организации");
    Model->setHeaderData(2,Qt::Horizontal, "ФИО контактного лица");
    Model->setHeaderData(3,Qt::Horizontal, "Телефон контактного лица");

    ui->ow_table->setModel(Model);
    ui->ow_table->hideColumn(0);
    ui->ow_table->resizeColumnsToContents();
    ui->ow_table->show();
}


void MainWindow::on_stuff_update_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("stuff_wh");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Склад");
    Model->setHeaderData(1,Qt::Horizontal, "Должность");
    Model->setHeaderData(2,Qt::Horizontal, "Оклад");
    Model->setHeaderData(3,Qt::Horizontal, "ФИО");
    Model->setHeaderData(4,Qt::Horizontal, "Контактные данные");
    ui->stuff_table ->setModel(Model);
    ui->stuff_table->resizeColumnsToContents();
    ui->stuff_table->show();

}


void MainWindow::on_rc_update_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("receipt_wh");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Склад");
    Model->setHeaderData(1,Qt::Horizontal, "Тип накладной");
    Model->setHeaderData(3,Qt::Horizontal, "Продукт");
    Model->setHeaderData(4,Qt::Horizontal, "Количество");
    Model->setHeaderData(5,Qt::Horizontal, "Общая стоимость");

    ui->rc_table ->setModel(Model);
    ui->rc_table->hideColumn(2);
    ui->rc_table->resizeColumnsToContents();
    ui->rc_table->show();

}


void MainWindow::on_prod_update_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("product_wh");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Наименование продукта");
    Model->setHeaderData(1,Qt::Horizontal, "Цена за шт");
    Model->setHeaderData(2,Qt::Horizontal, "Склад");
    Model->setHeaderData(3,Qt::Horizontal, "Количество ");
    Model->setHeaderData(4,Qt::Horizontal, "*Описание*");

    ui->prod_table->setModel(Model);
    ui->prod_table->resizeColumnsToContents();
    ui->prod_table->show();
}

// добавление данных
void MainWindow::on_wh_add_clicked()
{
    new_wh = new add_wh();
    new_wh->show();
}


void MainWindow::on_wh_table_clicked(const QModelIndex &index)
{
    QString temp_name = "";
    QString temp_addr = "";
    QString temp_ow = "";
    QString temp_space = "";

    temp_name = ui->wh_table->model()->data(ui->wh_table->model()->index(index.row(), 0)).toString();
    temp_addr = ui->wh_table->model()->data(ui->wh_table->model()->index(index.row(), 1)).toString();
    temp_ow = ui->wh_table->model()->data(ui->wh_table->model()->index(index.row(), 2)).toString();
    temp_space = ui->wh_table->model()->data(ui->wh_table->model()->index(index.row(), 3)).toString();

    ui->wh_name_line->setText(temp_name);
    ui->wh_addr_line->setText(temp_addr);
    ui->wh_owner_line->setText(temp_ow);
    ui->wh_space_line->setText(temp_space);


}


void MainWindow::on_wh_modify_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    QSqlQuery* query1  = new QSqlQuery();


    int temp_id_ow = -1;
    query1->exec(QString("SELECT id_o FROM owner_warehouse WHERE name_of_organisation = '%1'").arg(ui->wh_owner_line->text()));

    while (query1->next())
    {
        temp_id_ow = query1->value(0).toInt();
    }


    if (query->exec(QString("CALL modify_wh('%1','%2', %3, %4)").arg(ui->wh_name_line->text()).arg(ui->wh_addr_line->text()).arg(temp_id_ow).arg(ui->wh_space_line->text())))
    {
        QMessageBox::information(this, "Notice", "Изменено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;
    delete query1;
}


void MainWindow::on_wh_remove_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    if (query->exec(QString("CALL delete_wh('%1')").arg(ui->wh_name_line->text())))
    {
        QMessageBox::information(this, "Notice", "Удалено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }

    delete query;
}


void MainWindow::on_ow_add_clicked()
{
    new_owner = new add_ow();
    new_owner->show();
}


void MainWindow::on_ow_table_clicked(const QModelIndex &index)
{
    QString temp_name_org = "";
    QString temp_person = "";
    QString temp_contact = "";


    temp_name_org = ui->ow_table->model()->data(ui->ow_table->model()->index(index.row(), 1)).toString();
    temp_person = ui->ow_table->model()->data(ui->ow_table->model()->index(index.row(), 2)).toString();
    temp_contact = ui->ow_table->model()->data(ui->ow_table->model()->index(index.row(), 3)).toString();


    ui->ow_name_line->setText(temp_name_org);
    ui->ow_person_line->setText(temp_person);
    ui->ow_phone_line->setText(temp_contact);

}


void MainWindow::on_ow_modify_clicked()
{
    QSqlQuery* query = new QSqlQuery();


    if (query->exec(QString("CALL modify_ow('%1','%2', '%3')").arg(ui->ow_name_line->text()).arg(ui->ow_person_line->text()).arg(ui->ow_phone_line->text())))
    {
        QMessageBox::information(this, "Notice", "Изменено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;

}


void MainWindow::on_ow_remove_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    if (query->exec(QString("CALL delete_ow('%1')").arg(ui->ow_name_line->text())))
    {
        QMessageBox::information(this, "Notice", "Удалено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }

    delete query;
}


void MainWindow::on_stuff_add_clicked()
{
    new_stuff = new add_stuff;
    new_stuff->show();
}



void MainWindow::on_stuff_table_clicked(const QModelIndex &index)
{
    QString temp_st_wh = "";
    QString temp_job = "";
    QString temp_salary = "";
    QString temp_st_name = "";
    QString temp_phone = "";


    temp_st_wh = ui->stuff_table->model()->data(ui->stuff_table->model()->index(index.row(), 0)).toString();
    temp_job = ui->stuff_table->model()->data(ui->stuff_table->model()->index(index.row(), 1)).toString();
    temp_salary = ui->stuff_table->model()->data(ui->stuff_table->model()->index(index.row(), 2)).toString();
    temp_st_name = ui->stuff_table->model()->data(ui->stuff_table->model()->index(index.row(), 3)).toString();
    temp_phone = ui->stuff_table->model()->data(ui->stuff_table->model()->index(index.row(), 4)).toString();

    ui->st_wh_line->setText(temp_st_wh);
    ui->st_job_line->setText(temp_job);
    ui->st_salary_line->setText(temp_salary);
    ui->st_name_line->setText(temp_st_name);
    ui->st_phone_line->setText(temp_phone);

}


void MainWindow::on_stuff_modify_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    QSqlQuery* query1  = new QSqlQuery();


    int temp_id_sh = -1;
    query1->exec(QString("SELECT id_sh FROM storehouse WHERE name_of_storehouse = '%1'").arg(ui->st_wh_line->text()));

    while (query1->next())
    {
        temp_id_sh = query1->value(0).toInt();
    }


    if (query->exec(QString("CALL modify_stuff(%1,'%2', %3, '%4', '%5')").arg(temp_id_sh).arg(ui->st_job_line->text()).arg(ui->st_salary_line->text()).arg(ui->st_name_line->text()).arg(ui->st_phone_line->text())))
    {
        QMessageBox::information(this, "Notice", "Изменено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;
    delete query1;
}


void MainWindow::on_stuff_remove_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    if (query->exec(QString("CALL delete_stuff('%1')").arg(ui->st_name_line->text())))
    {
        QMessageBox::information(this, "Notice", "Удалено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }

    delete query;
}


void MainWindow::on_rc_in_clicked()
{
    new_receipt_in = new add_rc_in();
    new_receipt_in->show();
}


void MainWindow::on_rc_out_clicked()
{
    new_receipt_out = new add_rc_out();
    new_receipt_out->show();
}




void MainWindow::on_pr_search_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    if (query->exec(QString("SELECT cur_f('%1')").arg(ui->pr_search_line->text())))
    {
        int price = -1;
        while (query->next())
        {
            price = query->value(0).toInt();
        }
        if (price > -1)
        {
        QMessageBox::information(this, "Notice", QVariant(price).toString());

        }
        else
        {
        QMessageBox::critical(this, "Warning", "Неизвестное наименование");
        }
    }

    delete query;
}



void MainWindow::on_prod_table_clicked(const QModelIndex &index)
{
    QString temp_name_pr = "";
    QString temp_price = "";
    QString temp_wh = "";
    QString temp_des= "";


    temp_name_pr = ui->prod_table->model()->data(ui->prod_table->model()->index(index.row(), 0)).toString();
    temp_price = ui->prod_table->model()->data(ui->prod_table->model()->index(index.row(), 1)).toString();
    temp_wh = ui->prod_table->model()->data(ui->prod_table->model()->index(index.row(), 2)).toString();
    temp_des = ui->prod_table->model()->data(ui->prod_table->model()->index(index.row(), 4)).toString();

    ui->pr_name_line->setText(temp_name_pr);
    ui->pr_price_line->setText(temp_price);
    ui->pr_sh_line->setText(temp_wh);
    ui->pr_des_line->setText(temp_des);
}


void MainWindow::on_pr_modify_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQuery* query1  = new QSqlQuery();
    int temp_id_sh = -1;
    query1->exec(QString("SELECT id_sh FROM storehouse WHERE name_of_storehouse = '%1'").arg(ui->pr_sh_line->text()));

    while (query1->next())
    {
        temp_id_sh = query1->value(0).toInt();
    }


    if (query->exec(QString("CALL modify_product('%1', %2, '%3')").arg(ui->pr_name_line->text()).arg(temp_id_sh).arg(ui->pr_des_line->text())))
    {
        QMessageBox::information(this, "Notice", "Изменено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;
    delete query1;

}


void MainWindow::on_pr_remove_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    if (query->exec(QString("CALL delete_product('%1')").arg(ui->pr_name_line->text())))
    {
        QMessageBox::information(this, "Notice", "Удалено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }

    delete query;
}


void MainWindow::on_prod_sort_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("prod_sort");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Наименование продукта");
    Model->setHeaderData(1,Qt::Horizontal, "Цена за шт");
    Model->setHeaderData(2,Qt::Horizontal, "Склад");
    Model->setHeaderData(3,Qt::Horizontal, "Количество");
    Model->setHeaderData(4,Qt::Horizontal, "*Описание*");

    ui->prod_table->setModel(Model);
    ui->prod_table->resizeColumnsToContents();
    ui->prod_table->show();
}


void MainWindow::on_prod_is_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("prod_is");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Наименование продукта");
    Model->setHeaderData(1,Qt::Horizontal, "Цена за шт");
    Model->setHeaderData(2,Qt::Horizontal, "Скалад");
    Model->setHeaderData(3,Qt::Horizontal, "Количество");
    Model->setHeaderData(4,Qt::Horizontal, "*Описание*");

    ui->prod_table ->setModel(Model);
    ui->prod_table->resizeColumnsToContents();
    ui->prod_table->show();
}


void MainWindow::on_prod_add_clicked()
{
    new_product = new add_product();
    new_product->show();

}


void MainWindow::on_pushButton_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("sf_job");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "Работодатель");
    Model->setHeaderData(1,Qt::Horizontal, "Склад");
    Model->setHeaderData(2,Qt::Horizontal, "Должность");
    Model->setHeaderData(3,Qt::Horizontal, "Оклад");

    ui->stuff_table ->setModel(Model);
    ui->stuff_table->resizeColumnsToContents();
    ui->stuff_table->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    Model = new QSqlTableModel();
    Model->setTable("award");
    Model->select();

    Model->setHeaderData(0,Qt::Horizontal, "ФИО работника");
    Model->setHeaderData(1,Qt::Horizontal, "Оклад");
    Model->setHeaderData(2,Qt::Horizontal, "Склад");
    Model->setHeaderData(3,Qt::Horizontal, "Премия");

    ui->stuff_table ->setModel(Model);
    ui->stuff_table->resizeColumnsToContents();
    ui->stuff_table->show();
}

