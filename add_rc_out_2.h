#ifndef ADD_RC_OUT_2_H
#define ADD_RC_OUT_2_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>


namespace Ui {
class add_rc_out_2;
}

class add_rc_out_2 : public QWidget
{
    Q_OBJECT

public:
    explicit add_rc_out_2(QWidget *parent = nullptr);
    ~add_rc_out_2();

    void set_prod(int sh_id);

private slots:
    void on_add_rc_out_clicked();

private:
    Ui::add_rc_out_2 *ui;
    int wh_id;
};

#endif // ADD_RC_OUT_2_H
