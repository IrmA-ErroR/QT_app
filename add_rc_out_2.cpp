#include "add_rc_out_2.h"
#include "ui_add_rc_out_2.h"

add_rc_out_2::add_rc_out_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_rc_out_2)
{
    ui->setupUi(this);
}

add_rc_out_2::~add_rc_out_2()
{
    delete ui;
}

void add_rc_out_2::set_prod(int sh_id)
{
    wh_id = sh_id;
    QSqlQuery* query = new QSqlQuery();
    if (query->exec(QString("SELECT id_pr, name_of_product FROM product WHERE storehouse = %1").arg(sh_id)))
    {
        while(query->next())
        {
            ui->rc_out_pr_combo->addItem(query->value(1).toString(), query->value(0).toString());

        }
    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;

}

void add_rc_out_2::on_add_rc_out_clicked()
{
    close();
    QSqlQuery* query = new QSqlQuery();
    QSqlQuery* query1 = new QSqlQuery();
    QString temp_rc_type = "расходная";

    int amt = -1e9;
    query1->exec(QString("SELECT amount_pr FROM product WHERE id_pr = %1").arg(ui->rc_out_pr_combo->currentData().toString()));

    while (query1->next())
    {
        amt = query1->value(0).toInt();
    }

    if (amt - ui->rc_out_amount->text().toInt() < 0 )
    {
        QMessageBox::critical(this, "Warning", "Недостаточно товара на складе");
        delete query;
        delete query1;
        return;
    }



    if (query->exec(QString("CALL add_receipt_out('%1', %2, %3, %4, %5)").arg(temp_rc_type).arg(wh_id).arg(ui->rc_out_pr_combo->currentData().toString()).arg(ui->rc_out_amount->text()).arg(ui->rc_out_cost->text())))
    {
        QMessageBox::information(this, "Notice", "Добавлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;
    delete query1;
}

