#include "add_ow.h"
#include "ui_add_ow.h"

add_ow::add_ow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_ow)
{
    ui->setupUi(this);
    setWindowTitle("Добавление организации");
}

add_ow::~add_ow()
{
    delete ui;
}

void add_ow::on_add_ow_but_clicked()
{
    close();
    QSqlQuery* query = new QSqlQuery();


    if (query->exec(QString("CALL add_owner('%1','%2','%3')").arg(ui->ow_name_org->text()).arg(ui->ow_person->text()).arg(ui->ow_phone->text())))
    {
        QMessageBox::information(this, "Notice", "Добавлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }

    delete query;
}

