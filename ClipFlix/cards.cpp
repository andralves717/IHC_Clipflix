#include "cards.h"
#include "ui_cards.h"
#include <QDebug>
#include <QMouseEvent>
#include "watch_movie.h"
#include "watch_serie.h"
#include "watch_music.h"


cards::cards(QWidget *parent, Movie m, Data *d, int type) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    card_movie = m;
    this->data_card = d;
    t=type;
    ui->image->setPixmap(m.get_image());
    scroll_title = new ScrollText(this);
    scroll_title->setText(m.get_title());
    scroll_title->setMaximumWidth(m.get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
}
cards::cards(QWidget *parent, Serie s, Data *d, int type) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    card_serie = s;
    this->data_card = d;
    t=type;
    scroll_title = new ScrollText(this);
    scroll_title->setText(s.get_title());
    scroll_title->setMaximumWidth(s.get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
    ui->image->setPixmap(s.get_image());
}
cards::cards(QWidget *parent, Music m, Data *d, int type) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    card_music = m;
    this->data_card = d;
    t=type;
    scroll_title = new ScrollText(this);
    scroll_title->setText(m.get_title());
    scroll_title->setMaximumWidth(m.get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
    ui->image->setPixmap(m.get_image());
}

cards::~cards()
{
    delete ui;
}

void cards::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        if(this->t == 0){
            watch_movie wm(this,card_movie,data_card);
            wm.exec();
        } else if( this->t == 1) {
            watch_serie ws(this,card_serie,data_card);
            ws.exec();
        } else {
            watch_music wmu(this,card_music,data_card);
            wmu.exec();
        }


        switch (this->t) {
        case 0:
            qDebug() << scroll_title->text();
            //watch_movie wm(this,card_movie,data_card);
            //wm.exec();
            break;
        case 1:
            qDebug() << scroll_title->text();
            //watch_serie ws(this,card_serie,data_card);
            //ws.exec();
            break;
        case 2:
            qDebug() << scroll_title->text();
            break;
        }
    }
}

bool cards::operator==(const cards& c){
    return this->scroll_title->text() == c.scroll_title->text();
}
