#include "movie_scroll.h"
#include "ui_movie_scroll.h"
#include <QMouseEvent>
#include <QDebug>
#include "watch_movie.h"

Data *data_movie;

movie_scroll::movie_scroll(QWidget *parent, Movie m, Data *d) :
    QWidget(parent),
    ui(new Ui::movie_scroll)
{
    ui->setupUi(this);
    data_movie = d;
    movie = m;
    QFont font = ui->year->font();
    font.setPointSize(12);
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:20pt;\">"+m.get_title()+"</span></p></body></html>");
    ui->year->setText(QString::number(m.get_year()));
    ui->year->setFont(font);
    ui->image->setPixmap(m.get_image());
    ui->duration->setText(QString::number(m.get_duration())+" minutes");
    ui->duration->setFont(font);
    ui->rating->setText("⭐ "+QString::number((double)m.get_rating()/10)+"/10");
    ui->rating->setFont(font);
    QString genre_string;
    if(m.get_genre().length() > 5) {
        QStringList tmp_str = m.get_genre();
        tmp_str.insert(5,"\n");
        foreach (QString s, tmp_str) {
            genre_string.append(s + ", ");
            if(s == tmp_str.constLast() || s == "\n") genre_string.chop(2);
        }
    } else genre_string = m.get_genre_string();
    ui->genre->setText("Genre: "+genre_string);
    ui->genre->setFont(font);
    //if(ui->genre->width())
}

movie_scroll::~movie_scroll()
{
    delete ui;
}

void movie_scroll::mousePressEvent ( QMouseEvent * event ) {
    if(event->button() == Qt::LeftButton ){
        watch_movie wm(this,movie);
        wm.exec();
    }
}

void movie_scroll::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add\n Favourite"){
        if(data_movie->add_fav_user(this->movie)){
            qDebug() << "Adicionado "+ movie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_movie->rm_fav_user(this->movie)){
            qDebug() << "Removido "+ movie.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add\n Favourite");
        }
    }
}

void movie_scroll::hide(){
    QWidget::hide();
}
void movie_scroll::hide(QString genre, int year){
    if(!(movie.get_genre().contains(genre)) || !(movie.get_year() == year)) QWidget::hide();
    return;
}
void movie_scroll::hide(QString genre){
    if(movie.get_genre().contains(genre)) return;
    QWidget::hide();
}
void movie_scroll::hide(int year){
    if(movie.get_year() == year) return;
    QWidget::hide();
}

void movie_scroll::hide(QStringList genre_lst, QList<int> years){
    bool to_hide = true;
    foreach(QString genre, genre_lst){
        if(movie.get_genre().contains(genre)){
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
        if(movie.get_year()==year) return;
    }
    QWidget::hide();
}
void movie_scroll::hide(QStringList genre_lst){
    foreach(QString genre, genre_lst){
        if(movie.get_genre().contains(genre)) return;
    }
    QWidget::hide();
}
void movie_scroll::hide(QList<int> years){
    foreach(int year, years){
        if(movie.get_year()==year) return;
    }
    QWidget::hide();
}


void movie_scroll::show(){
    QWidget::show();
}
void movie_scroll::show(QString genre, int year){
    if(movie.get_genre().contains(genre) && movie.get_year() == year) QWidget::show();
    return;
}
void movie_scroll::show(QString genre){
    if(movie.get_genre().contains(genre)) QWidget::show();
    return;
}
void movie_scroll::show(int year){
    if(movie.get_year() == year) QWidget::show();
    return;
}


void movie_scroll::show(QStringList genre_lst, QList<int> years){
    bool to_show = false;
    foreach(QString genre, genre_lst){
        if(movie.get_genre().contains(genre)){
            to_show = true;
            break;
        }
        else to_show = false;
    }
    if(to_show){
        foreach(int year, years){
            if(movie.get_year()==year){
                QWidget::show();
                return;
            }
        }
    }
}
void movie_scroll::show(QStringList genre_lst){
    foreach(QString genre, genre_lst){
        if(movie.get_genre().contains(genre)){
            QWidget::show();
            return;
        }
    }
}
void movie_scroll::show(QList<int> years){
    foreach(int year, years){
        if(movie.get_year()==year){
            QWidget::show();
            return;
        }
    }
}
