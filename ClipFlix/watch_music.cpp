#include "watch_music.h"
#include "ui_watch_music.h"
#include <QDebug>

Data *data_watch_mu;

watch_music::watch_music(QWidget *parent, Music mw, Data *d) :
    QDialog(parent),
    ui(new Ui::watch_music)
{
    ui->setupUi(this);
    data_watch_mu=d;
    this->music_watch = mw;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:25pt;\">"+music_watch.get_title()+"</span></p></body></html>");
    ui->Year->setText(QString::number(music_watch.get_year()));
    ui->genre->setText("Genre: "+music_watch.get_genre());
    ui->image->setPixmap(music_watch.get_image());
    ui->album->setText("Album: "+music_watch.get_album());
    ui->rating->setText(music_watch.get_author());
    ui->time_label->setText(mw.get_duration().toString("mm:ss") + " minutes");
    this->setWindowTitle("Watch "+music_watch.get_title());

}

watch_music::~watch_music()
{
    delete ui;
}

void watch_music::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add to\n Favourites"){
        if(data_watch_mu->add_fav_user(this->music_watch)){
            qDebug() << "Adicionado "+ music_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_watch_mu->rm_fav_user(this->music_watch)){
            qDebug() << "Removido "+ music_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}
