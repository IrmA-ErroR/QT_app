#include "search_pr.h"
#include "ui_search_pr.h"

search_pr::search_pr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_pr)
{
    ui->setupUi(this);
}

search_pr::~search_pr()
{
    delete ui;
}

void search_pr::on_find_but_clicked()
{
    close();
    QString text = ui->search_line->text();
    if (text.isEmpty())
    {

        QMessageBox::critical(this, "Warning", "EMPTY INPUT");

     }
    else
    {


    }

}

