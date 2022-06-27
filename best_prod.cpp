#include "best_prod.h"
#include "ui_best_prod.h"

best_prod::best_prod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::best_prod)
{
    ui->setupUi(this);
}

best_prod::~best_prod()
{
    delete ui;
}

void best_prod::on_best_prod_show_clicked()
{
    int index = -1;
    QSqlQuery* query = new QSqlQuery();
    query->exec("SELECT id_pr FROM product WHERE MAX(price)");

    Model = new QSqlTableModel();
    Model->setTable("SELECT name_of_product, max(price) AS 'Best' FROM product WHERE id_pr = index");
    Model->select();


    delete query;

    Model->setHeaderData(1,Qt::Horizontal, "Название товара");
    Model->setHeaderData(2,Qt::Horizontal, "Цена");

    ui->best_prod_table->setModel(Model);
    ui->best_prod_table->resizeColumnsToContents();
    ui->best_prod_table->show();
}

