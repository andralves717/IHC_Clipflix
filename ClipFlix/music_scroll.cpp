#include "music_scroll.h"
#include "ui_music_scroll.h"
#include <QMouseEvent>
#include <QDebug>
#include "watch_music.h"

Data *data_music;

music_scroll::music_scroll(QWidget *parent, Music m, Data *d) :
    QWidget(parent),
    ui(new Ui::music_scroll)
{
    ui->setupUi(this);
    data_music = d;
    music = m;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+m.get_title()+"</span></p></body></html>");
    ui->year->setText(QString::number(m.get_year()));
    ui->image->setPixmap(m.get_image());
    ui->genre->setText("Genre: "+m.get_genre());
    ui->album->setText("Album: "+m.get_album());
    ui->author->setText(m.get_author());
    ui->timeEdit->setTime(m.get_duration());
    ui->timeEdit->setDisabled(true);
}

music_scroll::~music_scroll()
{
    delete ui;
}

void music_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        qDebug() << this->ui->title->text();
        watch_music wm(this,music);
        wm.exec();
    }
}

void music_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add Favourite"){
        if(data_music->add_fav_user(this->music)){
            qDebug() << "Adicionado "+ music.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_music->rm_fav_user(this->music)){
            qDebug() << "Removido "+ music.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}

void music_scroll::hide(){
    QWidget::hide();
}
void music_scroll::hide(QString genre, int year){
    if(!(music.get_genre().contains(genre)) || !(music.get_year() >= year && music.get_year() < year+10)) QWidget::hide();
    return;
}
void music_scroll::hide(QString genre){
    if(music.get_genre().contains(genre)) return;
    QWidget::hide();
}
void music_scroll::hide(int year){
    if(music.get_year() >= year && music.get_year() < year+10) return;
    QWidget::hide();
}


void music_scroll::show(){
    QWidget::show();
}
void music_scroll::show(QString genre, int year){
    if(music.get_genre().contains(genre) && music.get_year() >= year && music.get_year() < year+10) QWidget::show();
    return;
}
void music_scroll::show(QString genre){
    if(music.get_genre().contains(genre)) QWidget::show();
    return;
}
void music_scroll::show(int year){
    if(music.get_year() >= year && music.get_year() < year+10) QWidget::show();
    return;
}
