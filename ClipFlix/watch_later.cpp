#include "watch_later.h"
#include "ui_watch_later.h"

watch_later::watch_later(QWidget *parent, Data *d):
    QWidget(parent),
    ui(new Ui::watch_later)
{
    ui->setupUi(this);
    data_wl = d;

    foreach (Movie m, this->data_wl->get_active_user()->get_wl_movie()) {
        cards *c = new cards(this,m,this->data_wl, 0);
        ui->wl_movie_scroll->addWidget(c);
    }
    foreach (Serie s, this->data_wl->get_active_user()->get_wl_serie()) {
        cards *c = new cards(this,s,this->data_wl, 1);
        ui->wl_serie_scroll->addWidget(c);
    }
    foreach (Music m, this->data_wl->get_active_user()->get_wl_music()) {
        cards *c = new cards(this,m,this->data_wl, 2);
        ui->wl_music_scroll->addWidget(c);
    }
}

watch_later::~watch_later()
{
    delete ui;
}


bool watch_later::refresh(){
    foreach(cards *c, ui->wl_movie_scroll_cnt->findChildren<cards *>()){
        c->hide();
    }
    foreach(cards *c, ui->wl_serie_scroll_cnt->findChildren<cards *>()){
        c->hide();
    }
    foreach(cards *c, ui->wl_music_scroll_cnt->findChildren<cards *>()){
        c->hide();
    }

    foreach (Movie m, this->data_wl->get_active_user()->get_wl_movie()) {
        cards *c = new cards(this,m ,this->data_wl, 0);
        ui->wl_movie_scroll->addWidget(c);
    }
    foreach (Serie s, this->data_wl->get_active_user()->get_wl_serie()) {
        cards *c = new cards(this,s ,this->data_wl, 1);
        ui->wl_serie_scroll->addWidget(c);
    }
    foreach (Music m, this->data_wl->get_active_user()->get_wl_music()) {
        cards *c = new cards(this,m ,this->data_wl, 2);
        ui->wl_music_scroll->addWidget(c);
    }
    return true;
}
