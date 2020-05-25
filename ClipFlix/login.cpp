#include "login.h"
#include "ui_login.h"
#include <QShortcut>
#include <QDebug>

bool login_d = false;

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QLabel *login_message = new QLabel(this);
    ui->statusbar->addWidget(login_message);

    new QShortcut(QKeySequence(Qt::Key_Enter), this, SLOT(on_pushButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Return), this, SLOT(on_pushButton_clicked()));
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username = ui->line_user->text();
    QString password = ui->line_pass->text();
    QList<User> users = d->get_users();
    foreach (User u, users) {
        if(username == u.get_username()){
            if(password == u.get_password()) {
                ui->statusbar->showMessage("Sucessful Login");
                d->set_active_user(u);
                hide();
                login_d = true;
                MainWindow *w = new MainWindow(this,d);
                w->show();
                return;
            } else ui->statusbar->showMessage("Wrong Password");
        } else {
            ui->statusbar->showMessage("Wrong Username");
            login_d = false;
        }
    }


}

bool login::login_done(){
    return login_d;
}

bool login::add_data(Data *data){
    this->d = data;
    return true;
}
