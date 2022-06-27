#include "add_product.h"
#include "ui_add_product.h"

add_product::add_product(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_product)
{
    ui->setupUi(this);
    setWindowTitle("Добавление товара");

    QSqlQuery* query = new QSqlQuery(); //выпадающий список
    query->exec("SELECT id_sh, name_of_storehouse FROM storehouse");

    while(query->next())
    {
        ui->add_pr_combo_wh ->addItem(query->value(1).toString(), query->value(0).toString());
    }

    postcombo = 0;

    delete query;
}

add_product::~add_product()
{
    delete ui;
}

void add_product::on_add_pr_combo_wh_currentIndexChanged(int index)
{
    postcombo = index;
}


void add_product::on_add_pr_but_clicked()
{
    close();
    QSqlQuery* query = new QSqlQuery();


    if (query->exec(QString("CALL add_product('%1', %2)").arg(ui->add_pr_name->text()).arg(ui->add_pr_combo_wh->currentData().toString())))
    {
        QMessageBox::information(this, "Notice", "Добавлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
}

