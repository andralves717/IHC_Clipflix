#include "movie_scroll.h"
#include "ui_movie_scroll.h"
#include <QMouseEvent>
#include <QDebug>
#include "watch_movie.h"

Data *data_movie;

movie_scroll::movie_scroll(QWidget *parent, Movie m, Data *d) :
    QWidget(parent),
    ui(new Ui::movie_scroll)
{
    ui->setupUi(this);
    data_movie = d;
    movie = m;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+m.get_title()+"</span></p></body></html>");
    ui->year->setText(QString::number(m.get_year()));
    ui->image->setPixmap(m.get_image());
    ui->duration->setText(QString::number(m.get_duration())+" minutes");
    ui->rating->setText("⭐ "+QString::number((double)m.get_rating()/10)+"/10");
    ui->genre->setText("Genre: "+m.get_genre_string());
}

movie_scroll::~movie_scroll()
{
    delete ui;
}

void movie_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        watch_movie wm(this,movie);
        wm.exec();
    }
}

void movie_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add Favourite"){
        if(data_movie->add_fav_user(this->movie)){
            qDebug() << "Adicionado "+ movie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_movie->rm_fav_user(this->movie)){
            qDebug() << "Removido "+ movie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}

void movie_scroll::hide(){
    QWidget::hide();
}
void movie_scroll::hide(QString genre, int year){
    if(!(movie.get_genre().contains(genre)) || !(movie.get_year() == year)) QWidget::hide();
    return;
}
void movie_scroll::hide(QString genre){
    if(movie.get_genre().contains(genre)) return;
    QWidget::hide();
}
void movie_scroll::hide(int year){
    if(movie.get_year() == year) return;
    QWidget::hide();
}


void movie_scroll::show(){
    QWidget::show();
}
void movie_scroll::show(QString genre, int year){
    if(movie.get_genre().contains(genre) && movie.get_year() == year) QWidget::show();
    return;
}
void movie_scroll::show(QString genre){
    if(movie.get_genre().contains(genre)) QWidget::show();
    return;
}
void movie_scroll::show(int year){
    if(movie.get_year() == year) QWidget::show();
    return;
}
