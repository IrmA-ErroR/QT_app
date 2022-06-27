#ifndef ADD_STUFF_H
#define ADD_STUFF_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

namespace Ui {
class add_stuff;
}

class add_stuff : public QWidget
{
    Q_OBJECT

public:
    explicit add_stuff(QWidget *parent = nullptr);
    ~add_stuff();

    int postcombo;

private slots:


    void on_add_st_clicked();

    void on_st_combo_wh_currentIndexChanged(int index);

private:
    Ui::add_stuff *ui;
};

#endif // ADD_STUFF_H
