#include "cards.h"
#include "ui_cards.h"

cards::cards(QWidget *parent, Movie *m) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    ui->title->setText(m->get_title());
    ui->image->setPixmap(m->get_image());
}
cards::cards(QWidget *parent, Serie *s) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    ui->title->setText(s->get_title());
    ui->image->setPixmap(s->get_image());
}
cards::cards(QWidget *parent, Music *m) :
    QWidget(parent),
    ui(new Ui::cards)
{
    ui->setupUi(this);
    ui->title->setText(m->get_title());
    ui->image->setPixmap(m->get_image());
}

cards::~cards()
{
    delete ui;
}

bool cards::operator==(const cards& c){
    return this->ui->title->text() == c.ui->title->text();
}
