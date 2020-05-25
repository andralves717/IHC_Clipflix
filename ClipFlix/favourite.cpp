#include "favourite.h"
#include "ui_favourite.h"

favourite::favourite(QWidget *parent, User *u) :
    QWidget(parent),
    ui(new Ui::favourite)
{
    ui->setupUi(this);
    user = u;

    foreach (Movie m, user->get_fav_movie()) {
        cards *c = new cards(this,&m);
        ui->fav_movie_scroll->addWidget(c);
    }
    foreach (Serie s, user->get_fav_serie()) {
        cards *c = new cards(this,&s);
        ui->fav_serie_scroll->addWidget(c);
    }
    foreach (Music m, user->get_fav_music()) {
        cards *c = new cards(this,&m);
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

    foreach (Movie m, user->get_fav_movie()) {
        cards *c = new cards(this,&m);
        ui->fav_movie_scroll->addWidget(c);
    }
    foreach (Serie s, user->get_fav_serie()) {
        cards *c = new cards(this,&s);
        ui->fav_serie_scroll->addWidget(c);
    }
    foreach (Music m, user->get_fav_music()) {
        cards *c = new cards(this,&m);
        ui->fav_music_scroll->addWidget(c);
    }
    return true;
}
