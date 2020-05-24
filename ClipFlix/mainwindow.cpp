#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QRadioButton>
#include <QDebug>
#include "list.h"
#include "data.h"

Data *da;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    l = new login(this);
    l->show();

    ui->setupUi(this);

    User u("demo","demo");
    Data *d = new Data();
    d->add_user(u);
    d->set_movies(movie_list());
    d->set_active_user(u);

    da = d;


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
    List *movies = new List(this, 0, d);
    ui->movies_layout->addWidget(movies);
    List *series = new List(this, 1, d);
    ui->series_layout->addWidget(series);
    List *musics = new List(this, 2, d);
    ui->musics_layout->addWidget(musics);

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


QList<Movie> MainWindow::movie_list(){
    QList<Movie> ret;
    Movie frozen("Frozen 2", 2019, 103, 72, "Anna, Elsa, Kristoff, Olaf and Sven leave Arendelle to travel to an ancient, autumn-bound forest of an enchanted land. They set out to find the origin of Elsa's powers in order to save their kingdom. ");
    QStringList frozen_genre = {"Comedy", "Adventure", "Fantasy", "Animation", "Family", "Musical" };
    QPixmap frozen_image(":/images/image/movie_1.jpg");
    frozen.set_genre(frozen_genre);
    frozen.set_image(frozen_image);
    ret.append(frozen);
    Movie spiderman("Spider-Man: Far from Home", 2019, 129, 81, "Following the events of Vingadores: Endgame (2019), Spider-Man must step up to take on new threats in a world that has changed forever. ");
    QStringList spiderman_genre = {"Action", "Adventure", "Sci-fi"};
    QPixmap spiderman_image(":/images/image/movie_2.jpg");
    spiderman.set_genre(spiderman_genre);
    spiderman.set_image(spiderman_image);
    ret.append(spiderman);
    Movie toy("SOU PORTUGUÊS", 2020, 199, 99, "The great life of the most famous portuguese singer.\
              Since childhood, going through his youth when he started his career \
              until today.");
    QStringList toy_genre = {"Comedy", "Biography"};
    QPixmap toy_image(":/images/image/movie_3.jpg");
    toy.set_genre(toy_genre);
    toy.set_image(toy_image);
    ret.append(toy);

    return ret;
}

void MainWindow::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        QList<User> user_tmp = da->get_users();
        User tmp_user = user_tmp.at(0);
        qDebug() << tmp_user.get_fav_movie().size();
    }
}
