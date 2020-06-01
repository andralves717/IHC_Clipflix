#include "serie_scroll.h"
#include "ui_serie_scroll.h"
#include <QMouseEvent>
#include <QDebug>
#include "watch_serie.h"

Data *data_serie;

serie_scroll::serie_scroll(QWidget *parent, Serie s, Data *d) :
    QWidget(parent),
    ui(new Ui::serie_scroll)
{
    ui->setupUi(this);
    data_serie = d;
    serie = s;
    QFont font = ui->year->font();
    font.setPointSize(12);

    QString years = QString::number(s.get_years().constFirst())+"-";
    if(s.finished()){
        if(s.get_seasons() == 1) years = QString::number(s.get_years().constFirst());
        else years += QString::number(s.get_years().constLast());
    }

    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+s.get_title()+"</span></p></body></html>");
    ui->year->setText(years);
    ui->year->setFont(font);
    ui->image->setPixmap(s.get_image());
    ui->duration->setText(QString::number(s.get_seasons())+" seasons");
    ui->duration->setFont(font);
    ui->rating->setText("⭐ "+QString::number((double)s.get_rating()/10)+"/10");
    ui->rating->setFont(font);
    QString genre_string;
    if(s.get_genre().length() > 5) {
        QStringList tmp_str = s.get_genre();
        tmp_str.insert(5,"\n");
        foreach (QString str, tmp_str) {
            genre_string.append(str + ", ");
            if(str == tmp_str.constLast() || str == "\n") genre_string.chop(2);
        }
    } else genre_string = s.get_genre_string();
    ui->genre->setText("Genre: "+genre_string);
    ui->genre->setFont(font);
    this->refresh();

}

serie_scroll::~serie_scroll()
{
    delete ui;
}

void serie_scroll::refresh(){
    if(data_serie->is_fav_user(this->serie)) ui->addFav->setText("Favourite");
    else ui->addFav->setText("Add\n Favourite");
    if(data_serie->is_wl_user(this->serie)) ui->addWL->setText("Added to\nWatch Later");
    else ui->addWL->setText("Add\nWatch Later");
}

void serie_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        qDebug() << this->ui->title->text();
        watch_serie wm(this,serie,data_serie);
        wm.exec();
        this->refresh();
    }
}

void serie_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add\n Favourite"){
        if(data_serie->add_fav_user(this->serie)){
            qDebug() << "Adicionado "+ serie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_serie->rm_fav_user(this->serie)){
            qDebug() << "Removido "+ serie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add\n Favourite");
        }
    }
}

void serie_scroll::on_addWL_clicked()
{
    if(ui->addWL->text()=="Add\nWatch Later"){
        if(data_serie->add_wl_user(this->serie)){
            qDebug() << "Adicionado "+ serie.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Added to\nWatch Later");
        }
    } else {
        if(data_serie->rm_wl_user(this->serie)){
            qDebug() << "Removido "+ serie.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Add\nWatch Later");
        }
    }
}


void serie_scroll::hide(){
    QWidget::hide();
}
void serie_scroll::hide(QString genre, int year){
    if(!(serie.get_genre().contains(genre)) || !(serie.get_years().contains(year))) QWidget::hide();
    return;
}
void serie_scroll::hide(QString genre){
    if(serie.get_genre().contains(genre)) return;
    QWidget::hide();
}
void serie_scroll::hide(int year){
    if(serie.get_years().contains(year)) return;
    QWidget::hide();
}

void serie_scroll::hide(QStringList genre_lst, QList<int> years){
    bool to_hide = true;
    foreach(QString genre, genre_lst){
        if(serie.get_genre().contains(genre)){
            to_hide=false;
            break;
        }
        else to_hide = true;
    }
    if(to_hide){
        QWidget::hide();
        return;
    }
    foreach(int year, years){
        if(serie.get_years().contains(year)) return;
    }
    QWidget::hide();
}

void serie_scroll::hide(QStringList genre_lst){
    foreach(QString genre, genre_lst){
        if(serie.get_genre().contains(genre)) return;
    }
    QWidget::hide();
}
void serie_scroll::hide(QList<int> years){
    foreach(int year, years){
        if(serie.get_years().contains(year)) return;
    }
    QWidget::hide();
}



void serie_scroll::show(){
    QWidget::show();
}
void serie_scroll::show(QString genre, int year){
    if(serie.get_genre().contains(genre) && serie.get_years().contains(year)) QWidget::show();
    return;
}
void serie_scroll::show(QString genre){
    if(serie.get_genre().contains(genre)) QWidget::show();
    return;
}
void serie_scroll::show(int year){
    if(serie.get_years().contains(year)) QWidget::show();
    return;
}

void serie_scroll::show(QStringList genre_lst, QList<int> years){
    bool to_show = false;
    foreach(QString genre, genre_lst){
        if(serie.get_genre().contains(genre)){
            to_show = true;
            break;
        }
        else to_show = false;
    }
    if(to_show){
        foreach(int year, years){
            if(serie.get_years().contains(year)){
                QWidget::show();
                return;
            }
        }
    }
}
void serie_scroll::show(QStringList genre_lst){
    foreach(QString genre, genre_lst){
        if(serie.get_genre().contains(genre)){
            QWidget::show();
            return;
        }
    }
}
void serie_scroll::show(QList<int> years){
    foreach(int year, years){
        if(serie.get_years().contains(year)){
            QWidget::show();
            return;
        }
    }
}
