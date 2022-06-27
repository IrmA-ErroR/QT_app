#ifndef ADD_PRODUCT_H
#define ADD_PRODUCT_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

namespace Ui {
class add_product;
}

class add_product : public QWidget
{
    Q_OBJECT

public:
    explicit add_product(QWidget *parent = nullptr);
    ~add_product();

    int postcombo;

private slots:
    void on_add_pr_combo_wh_currentIndexChanged(int index);

    void on_add_pr_but_clicked();

private:
    Ui::add_product *ui;
};

#endif // ADD_PRODUCT_H
