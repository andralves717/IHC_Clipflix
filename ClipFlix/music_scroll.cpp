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
    QFont font = ui->year->font();
    font.setPointSize(12);
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+m.get_title()+"</span></p></body></html>");
    ui->year->setText(QString::number(m.get_year()));
    ui->year->setFont(font);
    ui->image->setPixmap(m.get_image());
    ui->genre->setText("Genre: "+m.get_genre());
    ui->genre->setFont(font);
    ui->album->setText("Album: "+m.get_album());
    ui->album->setFont(font);
    ui->author->setText(m.get_author());
    ui->author->setFont(font);
//    ui->timeEdit->setTime(m.get_duration());
//    ui->timeEdit->setDisabled(true);
    ui->time_label->setText(m.get_duration().toString("mm:ss") + " minutes");
    ui->time_label->setFont(font);
    this->refresh();
}

music_scroll::~music_scroll()
{
    delete ui;
}

void music_scroll::refresh(){
    if(data_music->is_fav_user(this->music)) ui->addFav->setText("Favourite");
    else ui->addFav->setText("Add\n Favourite");
    if(data_music->is_wl_user(this->music)) ui->addFav->setText("Added to\nWatch Later");
    else ui->addWL->setText("Add\nWatch Later");
}

void music_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        qDebug() << this->ui->title->text();
        watch_music wm(this,music,data_music);
        wm.exec();
        this->refresh();
    }
}

void music_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add\n Favourite"){
        if(data_music->add_fav_user(this->music)){
            qDebug() << "Adicionado "+ music.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_music->rm_fav_user(this->music)){
            qDebug() << "Removido "+ music.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add\n Favourite");
        }
    }
}

void music_scroll::on_addWL_clicked()
{
    if(ui->addWL->text()=="Add\nWatch Later"){
        if(data_music->add_wl_user(this->music)){
            qDebug() << "Adicionado "+ music.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Added to\nWatch Later");
        }
    } else {
        if(data_music->rm_wl_user(this->music)){
            qDebug() << "Removido "+ music.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Add\nWatch Later");
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

void music_scroll::hide(QStringList genre_lst, QList<int> years){
    bool to_hide = true;
    foreach(QString genre, genre_lst){
        if(music.get_genre().contains(genre)){
            to_hide=false;
            break;
        }
        else to_hide = true;
    }
    if(to_hide){
        QWidget::hide();
        return;
    }
    foreach(int year, years){
        if(music.get_year() >= year && music.get_year() < year+10) return;
    }
    QWidget::hide();
}
void music_scroll::hide(QStringList genre_lst){
    foreach(QString genre, genre_lst){
        if(music.get_genre().contains(genre)) return;
    }
    QWidget::hide();
}
void music_scroll::hide(QList<int> years){
    foreach(int year, years){
        if(music.get_year() >= year && music.get_year() < year+10) return;
    }
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

void music_scroll::show(QStringList genre_lst, QList<int> years){
    bool to_show = false;
    foreach(QString genre, genre_lst){
        if(music.get_genre().contains(genre)){
            to_show = true;
            break;
        }
        else to_show = false;
    }
    if(to_show){
        foreach(int year, years){
            if(music.get_year() >= year && music.get_year() < year+10){
                QWidget::show();
                return;
            }
        }
    }
}
void music_scroll::show(QStringList genre_lst){
    foreach(QString genre, genre_lst){
        if(music.get_genre().contains(genre)){
            QWidget::show();
            return;
        }
    }
}
void music_scroll::show(QList<int> years){
    foreach(int year, years){
        if(music.get_year() >= year && music.get_year() < year+10){
            QWidget::show();
            return;
        }
    }
}
