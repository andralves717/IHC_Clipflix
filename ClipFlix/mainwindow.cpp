#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QRadioButton>
#include <QDebug>

//#include <QMediaPlayer>
//#include <QVideoWidget>

favourite *fav_page;

MainWindow::MainWindow(QWidget *parent, Data *data) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    d = data;
    qDebug() << d->get_movies().size();
    qDebug() << "oi?";


    ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");

    QPixmap icon(":/images/image/logo.png");
    icon = icon.scaledToHeight(70);
    ui->icon->setPixmap(icon);

    // Recommended Movies

    foreach (Movie m, d->get_movies()) {
        cards *c = new cards(this,&m,0);
        ui->home_movies_scroll->addWidget(c);
    }

    // Recommended Series

    foreach (Serie m, d->get_series()) {
        cards *c = new cards(this,&m,1);
        ui->home_series_scroll->addWidget(c);
    }

    // Recommended Musics

    foreach (Music m, d->get_musics()) {
        cards *c = new cards(this,&m,2);
        ui->home_music_scroll->addWidget(c);
    }


    List *movies = new List(this, 0, d);
    ui->movies_layout->addWidget(movies);
    List *series = new List(this, 1, d);
    ui->series_layout->addWidget(series);
    List *musics = new List(this, 2, d);
    ui->musics_layout->addWidget(musics);

    fav_page = new favourite(this,d->get_active_user());
    ui->fav_layout->addWidget(fav_page);

//    QVideoWidget *video = new QVideoWidget(this);
//    QMediaPlayer *player = new QMediaPlayer;
//    player->setMedia(QUrl(":/tmp/videos/rato.mp4"));
//    player->setVideoOutput(video);
//    video->show();
//    player->play();
//    ui->movies_layout->addWidget(video);
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
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_1_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
    fav_page->refresh();
}



void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");

    switch (index) {
        case 0:
            ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
        break;

        case 1:
            ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
        break;

        case 2:
            ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
        break;

        case 3:
            ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
        break;

        case 4:
            ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");
        break;

    }
}

void MainWindow::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        QList<User> user_tmp = d->get_users();
        User tmp_user = user_tmp.at(0);
        qDebug() << QString::number(tmp_user.get_fav_movie().size())+" Filmes favoritos";
        qDebug() << QString::number(tmp_user.get_fav_serie().size())+" Séries favoritos";
        qDebug() << QString::number(tmp_user.get_fav_music().size())+" Músicas favoritos";
    }
}
