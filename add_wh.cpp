#include "add_wh.h"
#include "ui_add_wh.h"

add_wh::add_wh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_wh)
{
    ui->setupUi(this);
    setWindowTitle("Добавление склада");

    QSqlQuery* query = new QSqlQuery(); //выпадающий список
    query->exec("SELECT id_o, name_of_organisation FROM owner_warehouse");

    while(query->next())
    {
        ui->comboBox->addItem(query->value(1).toString(), query->value(0).toString());

    }

    postcombo = 0;
}

add_wh::~add_wh()
{
    delete ui;
}

void add_wh::on_comboBox_currentIndexChanged(int index)
{
    postcombo = index;
}


void add_wh::on_add_wh_button_clicked()
{
    close();
    QSqlQuery* query = new QSqlQuery();

    if (query->exec(QString("CALL add_wh('%1','%2', %3, %4)").arg(ui->name_wh->text()).arg(ui->addr_wh->text()).arg(ui->comboBox->currentData().toString()).arg(ui->space_wh->text())))
    {
        QMessageBox::information(this, "Notice", "Добавлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }

    delete query;
}

