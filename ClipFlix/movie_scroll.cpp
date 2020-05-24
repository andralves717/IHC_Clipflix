#include "movie_scroll.h"
#include "ui_movie_scroll.h"
#include <QMouseEvent>
#include <QDebug>

Data *data_local;

movie_scroll::movie_scroll(QWidget *parent, Movie m, Data *d) :
    QWidget(parent),
    ui(new Ui::movie_scroll)
{
    ui->setupUi(this);
    data_local = d;
    movie = m;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+m.get_title()+"</span></p></body></html>");
    ui->year->setText(QString::number(m.get_year()));
    ui->image->setPixmap(m.get_image());
    ui->duration->setText(QString::number(m.get_duration())+" minutes");
    ui->rating->setText(QString::number((double)m.get_rating()/10)+"/10");
    ui->genre->setText("Genre: "+m.get_genre_string());
}

movie_scroll::~movie_scroll()
{
    delete ui;
}

void movie_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        qDebug() << this->ui->title->text();
    }
}

void movie_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add Favourite"){
        if(data_local->add_fav_user("demo",this->movie)){
            qDebug() << "Adicionado "+ movie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
            ui->addFav->setDown(true);
        }
    } else {
        if(data_local->rm_fav_user("demo",this->movie)){
            qDebug() << "Removido "+ movie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}
