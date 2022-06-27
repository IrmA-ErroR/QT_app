#include "add_rc_out.h"
#include "ui_add_rc_out.h"

add_rc_out::add_rc_out(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_rc_out)
{
    ui->setupUi(this);
    setWindowTitle("Расходная накладная");

    QSqlQuery* query = new QSqlQuery(); //выпадающий список складов
    query->exec("SELECT id_sh, name_of_storehouse FROM storehouse");

    while(query->next())
    {
        ui->rc_out_combo_wh->addItem(query->value(1).toString(), query->value(0).toString());

    }

    delete query;

}

add_rc_out::~add_rc_out()
{
    delete ui;
    delete page;
}





void add_rc_out::on_rc_out_next_clicked()
{
    close();

    int wh_id = ui->rc_out_combo_wh->currentData().toInt();
    page = new add_rc_out_2();
    page->set_prod(wh_id);
    page->show();

}

