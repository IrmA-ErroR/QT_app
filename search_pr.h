#ifndef SEARCH_PR_H
#define SEARCH_PR_H

#include <QWidget>

#include <QMessageBox>
#include <QSqlQuery> //библтоека запросов
#include <QSqlError>
#include <QDebug>

namespace Ui {
class search_pr;
}

class search_pr : public QWidget
{
    Q_OBJECT

public:
    explicit search_pr(QWidget *parent = nullptr);
    ~search_pr();

private slots:
    void on_find_but_clicked();

private:
    Ui::search_pr *ui;
};

#endif // SEARCH_PR_H
