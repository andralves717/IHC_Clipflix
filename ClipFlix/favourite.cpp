#include "favourite.h"
#include "ui_favourite.h"

favourite::favourite(QWidget *parent, Data *d) :
    QWidget(parent),
    ui(new Ui::favourite)
{
    ui->setupUi(this);
    data_fav = d;

    foreach (Movie m, this->data_fav->get_active_user()->get_fav_movie()) {
        cards *c = new cards(this,m,this->data_fav, 0);
        ui->fav_movie_scroll->addWidget(c);
    }
    foreach (Serie s, this->data_fav->get_active_user()->get_fav_serie()) {
        cards *c = new cards(this,s,this->data_fav, 1);
        ui->fav_serie_scroll->addWidget(c);
    }
    foreach (Music m, this->data_fav->get_active_user()->get_fav_music()) {
        cards *c = new cards(this,m,this->data_fav, 2);
        ui->fav_music_scroll->addWidget(c);
    }
}

favourite::~favourite()
{
    delete ui;
}

bool favourite::refresh(){
    foreach(cards *c, ui->fav_movie_scroll_cnt->findChildren<cards *>()){
        c->hide();
    }
    foreach(cards *c, ui->fav_serie_scroll_cnt->findChildren<cards *>()){
        c->hide();
    }
    foreach(cards *c, ui->fav_music_scroll_cnt->findChildren<cards *>()){
        c->hide();
    }

    foreach (Movie m, this->data_fav->get_active_user()->get_fav_movie()) {
        cards *c = new cards(this,m ,this->data_fav, 0);
        ui->fav_movie_scroll->addWidget(c);
    }
    foreach (Serie s, this->data_fav->get_active_user()->get_fav_serie()) {
        cards *c = new cards(this,s ,this->data_fav, 1);
        ui->fav_serie_scroll->addWidget(c);
    }
    foreach (Music m, this->data_fav->get_active_user()->get_fav_music()) {
        cards *c = new cards(this,m ,this->data_fav, 2);
        ui->fav_music_scroll->addWidget(c);
    }
    return true;
}
