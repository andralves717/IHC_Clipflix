#include "movie_scroll.h"
#include "ui_movie_scroll.h"
#include <QMouseEvent>
#include <QDebug>

movie_scroll::movie_scroll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::movie_scroll)
{
    ui->setupUi(this);
}

movie_scroll::~movie_scroll()
{
    delete ui;
}

void movie_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        qDebug() << "oioio";
    }
}

void movie_scroll::on_addFav_clicked()
{
    qDebug() << "fav";
}
