#ifndef BEST_PROD_H
#define BEST_PROD_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class best_prod;
}

class best_prod : public QWidget
{
    Q_OBJECT

public:
    explicit best_prod(QWidget *parent = nullptr);
    ~best_prod();

private slots:
    void on_best_prod_show_clicked();

private:
    Ui::best_prod *ui;

    QSqlTableModel *Model;
};

#endif // BEST_PROD_H
