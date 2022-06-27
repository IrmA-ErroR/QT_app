#include "add_rc_in.h"
#include "ui_add_rc_in.h"

add_rc_in::add_rc_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_rc_in)
{
    ui->setupUi(this);
    setWindowTitle("Приходная накладная");

    QSqlQuery* query = new QSqlQuery(); //выпадающий список
    query->exec("SELECT id_sh, name_of_storehouse FROM storehouse");

    while(query->next())
    {
        ui->rc_combo_wh->addItem(query->value(1).toString(), query->value(0).toString());


    }

    postcombo = 0;


    query->exec("SELECT id_sh, name_of_storehouse FROM storehouse");

    while(query->next())
    {
        ui->rc_combo_wh->addItem(query->value(1).toString(), query->value(0).toString());


    }


    delete query;



}

add_rc_in::~add_rc_in()
{
    delete ui;
    delete page;
}



void add_rc_in::on_rc_next_clicked()
{
    close();

    int wh_id = ui->rc_combo_wh->currentData().toInt();
    page = new add_rc_in_2();
    page->set_prod(wh_id);
    page->show();

}

