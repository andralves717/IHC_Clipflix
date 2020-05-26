#include "watch_movie.h"
#include "ui_watch_movie.h"
#include <QDebug>

Data *data_watch_m;

watch_movie::watch_movie(QWidget *parent, Movie mw, Data *d) :
    QDialog(parent),
    ui(new Ui::watch_movie)
{
    ui->setupUi(this);
    data_watch_m=d;
    this->movie_watch = mw;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:25pt;\">"+movie_watch.get_title()+"</span></p></body></html>");
    ui->Year->setText(QString::number(movie_watch.get_year()));
    ui->genre->setText("Genre: "+movie_watch.get_genre_string());
    ui->image->setPixmap(movie_watch.get_image());
    ui->rating->setText("⭐ "+QString::number((double)movie_watch.get_rating()/10)+"/10");
    ui->Duration->setText(QString::number(movie_watch.get_duration())+" minutes");
    this->setWindowTitle("Watch "+movie_watch.get_title());
}

watch_movie::~watch_movie()
{
    delete ui;
}

void watch_movie::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add to\n Favourites"){
        if(data_watch_m->add_fav_user(this->movie_watch)){
            qDebug() << "Adicionado "+ movie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_watch_m->rm_fav_user(this->movie_watch)){
            qDebug() << "Removido "+ movie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}
