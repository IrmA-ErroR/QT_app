#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    setWindowTitle("Подключение");

    ui->User_Pass->setEchoMode(QLineEdit::Password);

    ui->Address_DB->setText("localhost");
    ui->Name_DB->setText("Module");
    ui->User_Name->setText("postgres");
    //ui->User_Pass->setText("postgres");
}

login::~login()
{
    delete ui;
}

void login::on_But_Connection_clicked() // нажатие на кнопку подключения
{
    close();
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(ui->Address_DB->text());
    db.setDatabaseName(ui->Name_DB->text());
    db.setUserName(ui->User_Name->text());
    db.setPassword(ui->User_Pass->text());

    if (db.open())
    {
        QMessageBox::information(this, "Notice", "Соединение установлено");

    }
    else
    {
        QMessageBox::critical(this, "Warning", "Не удалось подключиться к базе данных");
    }

}

