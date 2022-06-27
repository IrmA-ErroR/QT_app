#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include <QtSql> //библиотеки для работы с бд и уведомлений
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_But_Connection_clicked();

private:
    Ui::login *ui;

    QSqlDatabase db; //объект базы данных
};

#endif // LOGIN_H
