#include "add_rc_in_2.h"
#include "ui_add_rc_in_2.h"

add_rc_in_2::add_rc_in_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_rc_in_2)
{
    ui->setupUi(this);
}

add_rc_in_2::~add_rc_in_2()
{
    delete ui;
}

void add_rc_in_2::set_prod(int sh_id)
{
    wh_id = sh_id;
    QSqlQuery* query = new QSqlQuery();
    if (query->exec(QString("SELECT id_pr, name_of_product FROM product WHERE storehouse = %1").arg(sh_id)))
    {
        while(query->next())
        {
            ui->rc_pr_combo->addItem(query->value(1).toString(), query->value(0).toString());

        }
    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;

}




void add_rc_in_2::on_rc_in_add_clicked()
{
    close();
    QSqlQuery* query = new QSqlQuery();
    QString temp_rc_type = "приходная";


    if (query->exec(QString("CALL add_receipt_in('%1', %2, '%3', %4, %5, '%6')").arg(temp_rc_type).arg(wh_id).arg(ui->rc_pr_combo->currentData().toString()).arg(ui->rc_amount->text()).arg(ui->rc_total_cost->text()).arg(ui->rc_pr_des->text())))
    {
        QMessageBox::information(this, "Notice", "Добавлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
    delete query;
}

