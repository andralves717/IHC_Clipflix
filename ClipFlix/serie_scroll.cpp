#include "serie_scroll.h"
#include "ui_serie_scroll.h"
#include <QMouseEvent>
#include <QDebug>
#include "watch_serie.h"

Data *data_serie;

serie_scroll::serie_scroll(QWidget *parent, Serie s, Data *d) :
    QWidget(parent),
    ui(new Ui::serie_scroll)
{
    ui->setupUi(this);
    data_serie = d;
    serie = s;
    QString years = "("+QString::number(s.get_years().constFirst())+"-";
    if(s.finished()){
        if(s.get_seasons() == 1) years = QString::number(s.get_years().constFirst());
        else years += QString::number(s.get_years().constLast()) + ")";
    }
    else years + ")";

    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+s.get_title()+"</span></p></body></html>");
    ui->year->setText(years);
    ui->image->setPixmap(s.get_image());
    ui->duration->setText(QString::number(s.get_seasons())+" seasons");
    ui->rating->setText("⭐ "+QString::number((double)s.get_rating()/10)+"/10");
    ui->genre->setText("Genre: "+s.get_genre_string());
}

serie_scroll::~serie_scroll()
{
    delete ui;
}

void serie_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        qDebug() << this->ui->title->text();
        watch_serie wm(this,serie);
        wm.exec();
    }
}

void serie_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add Favourite"){
        if(data_serie->add_fav_user(this->serie)){
            qDebug() << "Adicionado "+ serie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_serie->rm_fav_user(this->serie)){
            qDebug() << "Removido "+ serie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}

void serie_scroll::hide(){
    QWidget::hide();
}
void serie_scroll::hide(QString genre, int year){
    if(!(serie.get_genre().contains(genre)) || !(serie.get_years().contains(year))) QWidget::hide();
    return;
}
void serie_scroll::hide(QString genre){
    if(serie.get_genre().contains(genre)) return;
    QWidget::hide();
}
void serie_scroll::hide(int year){
    if(serie.get_years().contains(year)) return;
    QWidget::hide();
}


void serie_scroll::show(){
    QWidget::show();
}
void serie_scroll::show(QString genre, int year){
    if(serie.get_genre().contains(genre) && serie.get_years().contains(year)) QWidget::show();
    return;
}
void serie_scroll::show(QString genre){
    if(serie.get_genre().contains(genre)) QWidget::show();
    return;
}
void serie_scroll::show(int year){
    if(serie.get_years().contains(year)) QWidget::show();
    return;
}
