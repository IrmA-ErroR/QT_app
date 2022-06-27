#ifndef ADD_WH_H
#define ADD_WH_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

namespace Ui {
class add_wh;
}

class add_wh : public QWidget
{
    Q_OBJECT

public:
    explicit add_wh(QWidget *parent = nullptr);
    ~add_wh();

    int postcombo;

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_add_wh_button_clicked();

private:
    Ui::add_wh *ui;
};

#endif // ADD_WH_H
