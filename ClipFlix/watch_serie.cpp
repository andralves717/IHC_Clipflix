#include "watch_serie.h"
#include "ui_watch_serie.h"
#include <QDebug>

Data *data_watch_s;

watch_serie::watch_serie(QWidget *parent, Serie mw, Data *d) :
    QDialog(parent),
    ui(new Ui::watch_serie)
{
    ui->setupUi(this);
    data_watch_s=d;

    this->serie_watch = mw;
    QString years = "("+QString::number(serie_watch.get_years().constFirst())+"-";
    if(serie_watch.finished()) years + QString::number(serie_watch.get_years().constLast()) + ")";
    else years + ")";
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:25pt;\">"+serie_watch.get_title()+"</span></p></body></html>");
    ui->Year->setText(years);
    ui->genre->setText("Genre: "+serie_watch.get_genre_string());
    ui->image->setPixmap(serie_watch.get_image());
    ui->rating->setText("⭐ "+QString::number((double)serie_watch.get_rating()/10)+"/10");
    ui->Duration->setText(QString::number(serie_watch.get_seasons())+" seasons");
    this->setWindowTitle("Watch "+serie_watch.get_title());
}

watch_serie::~watch_serie()
{
    delete ui;
}

void watch_serie::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add to\n Favourites"){
        if(data_watch_s->add_fav_user(this->serie_watch)){
            qDebug() << "Adicionado "+ serie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_watch_s->rm_fav_user(this->serie_watch)){
            qDebug() << "Removido "+ serie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add Favourite");
        }
    }
}
