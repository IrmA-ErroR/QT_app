#include "add_stuff.h"
#include "ui_add_stuff.h"

add_stuff::add_stuff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_stuff)
{
    ui->setupUi(this);
    setWindowTitle("Добавление работника");

    QSqlQuery* query = new QSqlQuery(); //выпадающий список
    query->exec("SELECT id_sh, name_of_storehouse FROM storehouse");

    while(query->next())
    {
        ui->st_combo_wh ->addItem(query->value(1).toString(), query->value(0).toString());
    }

    postcombo = 0;

    delete query;
}

add_stuff::~add_stuff()
{
    delete ui;
}



void add_stuff::on_add_st_clicked()
{
    close();
    QSqlQuery* query = new QSqlQuery();


    if (query->exec(QString("CALL add_stuff('%1', %2, %3, '%4', '%5')").arg(ui->st_position->text()).arg(ui->st_salary->text()).arg(ui->st_combo_wh->currentData().toString()).arg(ui->st_name->text()).arg(ui->st_phone->text())))
    {
        QMessageBox::information(this, "Notice", "Добавлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", query->lastError().text());
    }
}


void add_stuff::on_st_combo_wh_currentIndexChanged(int index)
{
    postcombo = index;
}

