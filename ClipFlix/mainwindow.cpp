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
    d->set_series(serie_list());
    d->set_musics(music_list());
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

    foreach (Movie m, u.get_fav_movie()) {
        cards *c = new cards(this,&m);
        ui->fav_movie_scroll->addWidget(c);
    }
    foreach (Serie s, u.get_fav_serie()) {
        cards *c = new cards(this,&s);
        ui->fav_serie_scroll->addWidget(c);
    }
    foreach (Music m, u.get_fav_music()) {
        cards *c = new cards(this,&m);
        ui->fav_music_scroll->addWidget(c);
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
     /*
     foreach (cards c, ui->fav_movie_scroll_cnt->findChildren<cards>()) {

     }
     foreach (Movie m, da->get_active_user().get_fav_movie()) {
         cards *c = new cards(this,&m);
         if(!ui->fav_movie_scroll_cnt->findChildren<cards>().contains(*c)){
            ui->fav_movie_scroll->addWidget(c);
         }
     }
     foreach (Serie s, da->get_active_user().get_fav_serie()) {
         cards *c = new cards(this,&s);
         if(!ui->fav_serie_scroll_cnt->findChildren<cards>().contains(*c)){
            ui->fav_serie_scroll->addWidget(c);
         }
     }
     foreach (Music m, da->get_active_user().get_fav_music()) {
         cards *c = new cards(this,&m);
         if(!ui->fav_music_scroll_cnt->findChildren<cards>().contains(*c))
            ui->fav_music_scroll->addWidget(c);
     }
     */
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

QList<Serie> MainWindow::serie_list(){
    QList<Serie> ret;
    //La Casa de Papel
    Serie casapapel("La Casa de Papel");
    casapapel.set_rating(84);
    casapapel.set_seasons(4);
    casapapel.set_finished(false);
    casapapel.set_description("An unusual group of robbers attempt to carry out the most perfect robbery in Spanish history - stealing 2.4 billion euros from the Royal Mint of Spain.");
    casapapel.set_years({2017,2019,2020});
    QStringList casapapel_genre = {"Action", "Crime", "Mystery"};
    casapapel.set_genre(casapapel_genre);
    QPixmap casapapel_image(":/images/image/series_1.jpg");
    casapapel.set_image(casapapel_image);
    ret.append(casapapel);

    //Chernobyl
    Serie chernobyl("Chernobyl");
    chernobyl.set_rating(94);
    chernobyl.set_seasons(1);
    chernobyl.set_finished(true);
    chernobyl.set_description("In April 1986, an explosion at the Chernobyl nuclear power plant in the Union of Soviet Socialist Republics becomes one of the world's worst man-made catastrophes.");
    chernobyl.set_years({2019});
    QStringList chernobyl_genre = {"Drama", "History", "Thriller"};
    chernobyl.set_genre(chernobyl_genre);
    QPixmap chernobyl_image(":/images/image/series_2.jpg");
    chernobyl.set_image(chernobyl_image);
    ret.append(chernobyl);

    //Game of Thrones
    Serie got("Game of Thrones");
    got.set_rating(93);
    got.set_seasons(8);
    got.set_finished(true);
    got.set_description("Nine noble families fight for control over the lands of Westeros, while an ancient enemy returns after being dormant for millennia.");
    got.set_years({2011,2012,2013,2014,2015,2016,2017,2019});
    QStringList got_genre = {"Action", "Adventure", "Drama"};
    got.set_genre(got_genre);
    QPixmap got_image(":/images/image/series_3.jpg");
    got.set_image(got_image);
    ret.append(got);

    //The Witcher
    Serie witcher("The Witcher");
    witcher.set_rating(83);
    witcher.set_seasons(1);
    witcher.set_finished(false);
    witcher.set_description("Geralt of Rivia, a solitary monster hunter, struggles to find his place in a world where people often prove more wicked than beasts.");
    witcher.set_years({2019});
    QStringList witcher_genre = {"Action", "Adventure", "Fantasy"};
    witcher.set_genre(witcher_genre);
    QPixmap witcher_image(":/images/image/series_4.jpg");
    witcher.set_image(witcher_image);
    ret.append(witcher);

    return ret;
}
QList<Music> MainWindow::music_list(){
    QList<Music> ret;

    //Chop Suey!
    Music chop("Chop Suey!", "System of a Down", "Toxicity");
    chop.set_year(2001);
    chop.set_genre("Metal");
    QPixmap chop_image(":/images/image/music_1.jpg");
    chop.set_image(chop_image);
    QTime chop_time(0,3,30);
    chop.set_duration(chop_time);
    ret.append(chop);

    //Gangnam Style
    Music gangnam("Gangnam Style", "PSY", "Psy 6 (Six Rules), Part 1");
    gangnam.set_year(2012);
    gangnam.set_genre("K-POP");
    QPixmap gangnam_image(":/images/image/music_2.jpg");
    gangnam.set_image(gangnam_image);
    QTime gangnam_time(0,3,39);
    gangnam.set_duration(gangnam_time);
    ret.append(gangnam);

    //A Paixão
    Music paixao("A Paixão", "Rui Veloso", "Mingos & Os Samurais");
    paixao.set_year(1990);
    paixao.set_genre("Rock");
    QPixmap paixao_image(":/images/image/music_3.jpg");
    paixao.set_image(paixao_image);
    QTime paixao_time(0,3,50);
    paixao.set_duration(paixao_time);
    ret.append(paixao);

    return ret;
}

void MainWindow::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        QList<User> user_tmp = da->get_users();
        User tmp_user = user_tmp.at(0);
        qDebug() << QString::number(tmp_user.get_fav_movie().size())+" Filmes favoritos";
        qDebug() << QString::number(tmp_user.get_fav_serie().size())+" Séries favoritos";
        qDebug() << QString::number(tmp_user.get_fav_music().size())+" Músicas favoritos";
    }
}
