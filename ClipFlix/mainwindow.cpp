#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <string>

int g_page=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    l = new login(this);
    l->show();

    ui->setupUi(this);

    //Movies Tab
    ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");

    QLabel *movie_label[3];
    QPixmap mo_pic[3];
    for (int i=0;i<(int) (sizeof(mo_pic)/sizeof(QPixmap));i++) {
        movie_label[i] = new QLabel(this);
        mo_pic[i].load(":/images/image/movie_"+QString::number(i+1)+".jpg");
        mo_pic[i] = mo_pic[i].scaledToHeight(200,Qt::SmoothTransformation);
        movie_label[i]->setPixmap(mo_pic[i]);
        ui->home_movies_scroll->addWidget(movie_label[i]);

    }

    // Series Tab

    QLabel *serie_label[4];
    QPixmap s_pic[4];
    for (int i=0;i<(int) (sizeof(s_pic)/sizeof(QPixmap));i++) {
        serie_label[i] = new QLabel(this);
        s_pic[i].load(":/images/image/series_"+QString::number(i+1)+".jpg");
        s_pic[i] = s_pic[i].scaledToHeight(200,Qt::SmoothTransformation);
        serie_label[i]->setPixmap(s_pic[i]);
        ui->home_series_scroll->addWidget(serie_label[i]);

    }

    // Music Tab

    QLabel *music_label[3];
    QPixmap m_pic[3];
    for (int i=0;i<(int) (sizeof(m_pic)/sizeof(QPixmap));i++) {
        music_label[i] = new QLabel(this);
        m_pic[i].load(":/images/image/music_"+QString::number(i+1)+".jpg");
        m_pic[i] = m_pic[i].scaledToHeight(200,Qt::SmoothTransformation);
        music_label[i]->setPixmap(m_pic[i]);
        ui->home_music_scroll->addWidget(music_label[i]);

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deseja Sair?","Tem a certeza que deseja sair do ClipFlix?",QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

void MainWindow::on_actionHome_triggered()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_actionMovies_triggered()
{
     ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_actionSeries_triggered()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_actionMusic_triggered()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_actionFavourite_triggered()
{
    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(g_page!=0){
        g_page=0;
        ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(g_page!=1){
        g_page=1;
        ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(g_page!=2){
        g_page=2;
        ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(g_page!=3){
        g_page=3;
        ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
    }
}


void MainWindow::on_pushButton_1_clicked()
{
    if(g_page!=4){
        g_page=4;
        ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
        ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
    }
}


