#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QRadioButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    l = new login(this);
    l->show();

    ui->setupUi(this);


    ui->pushButton_1->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_3->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_4->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;} QPushButton:hover {color: rgb(0,188,212);}");
    ui->pushButton_5->setStyleSheet("QPushButton {background-color: rgb(46,52,54);border: 0px;color:rgb(0,188,212);} QPushButton:hover {color: rgb(0,188,212);}");

    //Movies Tab

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

    // Real Movie Tab

    QVBoxLayout *vbox_genre = new QVBoxLayout;
    QRadioButton *genre[9];
    QStringList genre_tex = {"Action", "Adventure", "Animation", "Biography", "Comedy", "Family", "Fantasy", "Musical", "Sci-fi"};

    for (int i=0; i<9;i++){
        genre[i] = new QRadioButton(this);
        genre[i]->setText(genre_tex.at(i));
        vbox_genre->addWidget(genre[i]);
    }
    ui->group_genre->setLayout(vbox_genre);

    QVBoxLayout *vbox_year = new QVBoxLayout;
    QRadioButton *year[4];

    for (int i=0; i<4;i++){
        year[i] = new QRadioButton(this);
        year[i]->setText(QString::number(2020-i));
        vbox_year->addWidget(year[i]);
    }

    ui->group_year->setLayout(vbox_year);


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

void MainWindow::on_clear_clicked()
{
    foreach (QRadioButton *genre_object, ui->group_genre->findChildren<QRadioButton *>()) {
        if(genre_object->isChecked()){
            genre_object->setAutoExclusive(false);
            genre_object->setChecked(false);
            genre_object->setAutoExclusive(true);
        }
    }
    foreach (QRadioButton *year_object, ui->group_year->findChildren<QRadioButton *>()) {
        if(year_object->isChecked()){
            year_object->setAutoExclusive(false);
            year_object->setChecked(false);
            year_object->setAutoExclusive(true);
        }
    }
}
