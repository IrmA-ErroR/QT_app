#ifndef ADD_RC_IN_H
#define ADD_RC_IN_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

#include "add_rc_in_2.h"
#include "ui_add_rc_in_2.h"


namespace Ui {
class add_rc_in;
}

class add_rc_in : public QWidget
{
    Q_OBJECT

public:
    explicit add_rc_in(QWidget *parent = nullptr);
    ~add_rc_in();

    int postcombo;

private slots:

    void on_rc_next_clicked();


private:
    Ui::add_rc_in *ui;
    add_rc_in_2 * page;
};

#endif // ADD_RC_IN_H
