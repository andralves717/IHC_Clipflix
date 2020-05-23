/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *info;
    QFormLayout *formLayout;
    QLabel *label_user;
    QLineEdit *line_user;
    QLabel *label_pass;
    QLineEdit *line_pass;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(432, 229);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        info = new QLabel(centralwidget);
        info->setObjectName(QString::fromUtf8("info"));

        verticalLayout->addWidget(info);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_user = new QLabel(centralwidget);
        label_user->setObjectName(QString::fromUtf8("label_user"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_user);

        line_user = new QLineEdit(centralwidget);
        line_user->setObjectName(QString::fromUtf8("line_user"));

        formLayout->setWidget(0, QFormLayout::FieldRole, line_user);

        label_pass = new QLabel(centralwidget);
        label_pass->setObjectName(QString::fromUtf8("label_pass"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_pass);

        line_pass = new QLineEdit(centralwidget);
        line_pass->setObjectName(QString::fromUtf8("line_pass"));
        line_pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, line_pass);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", nullptr));
        info->setText(QApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Sign In</span></p></body></html>", nullptr));
        label_user->setText(QApplication::translate("login", "Username", nullptr));
        line_user->setText(QApplication::translate("login", "Please type your username here.", nullptr));
        label_pass->setText(QApplication::translate("login", "Password", nullptr));
        line_pass->setText(QString());
        pushButton->setText(QApplication::translate("login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
