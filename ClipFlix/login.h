#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "mainwindow.h"
#include "data.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool login_done();

    bool add_data(Data *data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    Data *d;
};

#endif // LOGIN_H
