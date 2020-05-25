#include "cards.h"
#include "ui_cards.h"

cards::cards(QWidget *parent, Movie *m) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    ui->image->setPixmap(m->get_image());
    scroll_title = new ScrollText(this);
    scroll_title->setText(m->get_title());
    scroll_title->setMaximumWidth(m->get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
}
cards::cards(QWidget *parent, Serie *s) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    scroll_title = new ScrollText(this);
    scroll_title->setText(s->get_title());
    scroll_title->setMaximumWidth(s->get_image().width());
    ui->verticalLayout->addWidget(scroll_title);
    ui->image->setPixmap(s->get_image());
}
cards::cards(QWidget *parent, Music *m) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
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

bool cards::operator==(const cards& c){
    return this->scroll_title->text() == c.scroll_title->text();
}
