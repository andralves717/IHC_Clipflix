#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QLabel *login_message = new QLabel(this);
    ui->statusbar->addWidget(login_message);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username = ui->line_user->text();
    QString password = ui->line_pass->text();

    if(username == "demo"){
        if(password == "demo") {
            ui->statusbar->showMessage("Sucessful Login");
            hide();

        }else
            ui->statusbar->showMessage("Wrong Password");
    } else
        ui->statusbar->showMessage("Wrong Username");
}
