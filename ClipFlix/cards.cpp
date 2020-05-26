#include "cards.h"
#include "ui_cards.h"
#include <QDebug>
#include <QMouseEvent>

cards::cards(QWidget *parent, Movie *m, int type) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    card_movie = m;
    t=type;
    ui->image->setPixmap(m->get_image());
    scroll_title = new ScrollText(this);
    scroll_title->setText(m->get_title());
    scroll_title->setMaximumWidth(m->get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
}
cards::cards(QWidget *parent, Serie *s, int type) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    card_serie = s;
    t=type;
    scroll_title = new ScrollText(this);
    scroll_title->setText(s->get_title());
    scroll_title->setMaximumWidth(s->get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
    ui->image->setPixmap(s->get_image());
}
cards::cards(QWidget *parent, Music *m, int type) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    card_music = m;
    t=type;
    scroll_title = new ScrollText(this);
    scroll_title->setText(m->get_title());
    scroll_title->setMaximumWidth(m->get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
    ui->image->setPixmap(m->get_image());
}

cards::~cards()
{
    delete ui;
}

void cards::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        switch (t) {
        case 0:
            qDebug() << scroll_title->text();
            break;
        case 1:
            qDebug() << scroll_title->text();
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
