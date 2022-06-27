#ifndef ADD_RC_OUT_H
#define ADD_RC_OUT_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

#include "add_rc_out_2.h"

namespace Ui {
class add_rc_out;
}

class add_rc_out : public QWidget
{
    Q_OBJECT

public:
    explicit add_rc_out(QWidget *parent = nullptr);
    ~add_rc_out();



private slots:

    void on_rc_out_next_clicked();

private:
    Ui::add_rc_out *ui;
    add_rc_out_2 * page;
};

#endif // ADD_RC_OUT_H
