#ifndef ADD_OW_H
#define ADD_OW_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

namespace Ui {
class add_ow;
}

class add_ow : public QWidget
{
    Q_OBJECT

public:
    explicit add_ow(QWidget *parent = nullptr);
    ~add_ow();

private slots:
    void on_add_ow_but_clicked();

private:
    Ui::add_ow *ui;
};

#endif // ADD_OW_H
