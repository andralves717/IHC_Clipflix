#include "list.h"
#include "ui_list.h"
#include <QRadioButton>
#include <QCheckBox>
#include "movie_scroll.h"
#include "serie_scroll.h"
#include "music_scroll.h"
#include <QDebug>

List::List(QWidget *parent, int type, Data *d) :
    QWidget(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);
    t=type;
    QVBoxLayout *vbox_genre = new QVBoxLayout;
    QCheckBox *genre_check[9];
    QStringList genre_tex;
    switch(type){
        case 0:
            genre_tex.append({"Action", "Adventure", "Animation", "Biography", "Comedy", "Family", "Fantasy", "Musical", "Sci-fi"});
        break;
        case 1:
            genre_tex.append({"Action", "Adventure", "Crime", "Drama", "Fantasy", "History", "Mystery", "Thriller"});
        break;
        case 2:
            genre_tex.append({"Rock", "Metal", "K-POP"});
    }

    for (int i=0; i<genre_tex.size();i++){
        genre_check[i] = new QCheckBox(this);
        genre_check[i]->setText(genre_tex.at(i));
        vbox_genre->addWidget(genre_check[i]);
        connect(genre_check[i],SIGNAL(stateChanged(int)),this ,SLOT(set_filters()));
    }
    ui->group_genre->setLayout(vbox_genre);

    if(type <2){
        QVBoxLayout *vbox_year = new QVBoxLayout;
        QCheckBox *year[10];

        for (int i=0; i<10;i++){
            year[i] = new QCheckBox(this);
            year[i]->setText(QString::number(2020-i));
            vbox_year->addWidget(year[i]);
            connect(year[i],SIGNAL(stateChanged(int)),this ,SLOT(set_filters()));
        }
        ui->group_year->setLayout(vbox_year);
    } else {
        QVBoxLayout *vbox_years = new QVBoxLayout;
        QCheckBox *years[5];

        for (int i=0;i<5;i++) {
            years[i] = new QCheckBox(this);
            years[i]->setText(QString::number((202-i)*10)+"'s");
            vbox_years->addWidget(years[i]);
            connect(years[i],SIGNAL(stateChanged(int)),this ,SLOT(set_filters()));
        }
        ui->group_year->setLayout(vbox_years);
    }




    switch (type) {
        case 0:
            foreach(Movie m, d->get_movies()){
                movie_scroll *ms = new movie_scroll(this, m, d);
                ui->scroll_layout->addWidget(ms);
            }
        break;
        case 1:
            foreach(Serie s, d->get_series()){
                serie_scroll *ss = new serie_scroll(this, s, d);
                ui->scroll_layout->addWidget(ss);
            }
        break;
        case 2:
            foreach(Music m, d->get_musics()){
                music_scroll *ms = new music_scroll(this, m, d);
                ui->scroll_layout->addWidget(ms);
            }
        break;
    }

}

List::~List()
{
    delete ui;
}

void List::on_clear_clicked()
{
    foreach (QCheckBox *genre_object, ui->group_genre->findChildren<QCheckBox *>()) {
        if(genre_object->isChecked()){
            genre_object->setAutoExclusive(false);
            genre_object->setChecked(false);
            genre_object->setAutoExclusive(true);
        }
    }
    foreach (QCheckBox *year_object, ui->group_year->findChildren<QCheckBox *>()) {
        if(year_object->isChecked()){
            year_object->setAutoExclusive(false);
            year_object->setChecked(false);
            year_object->setAutoExclusive(true);
        }
    }
    switch (t) {
        case 0:
            foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                ms->show();
            }
            break;
        case 1:
            foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                ss->show();
            }
            break;
        case 2:
            foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                ms->show();
            }
            break;
    }
}

void List::on_pushButton_clicked()
{
    QString genre;
    int year=0;
    foreach(QRadioButton *genre_object, ui->group_genre->findChildren<QRadioButton *>()){
        if(genre_object->isChecked()){
            genre = genre_object->text();
        }
    }
    foreach(QRadioButton *year_object, ui->group_year->findChildren<QRadioButton *>()){
        if(year_object->isChecked()){
            if(t<2) year = year_object->text().toInt();
            else {
                QString tmp = year_object->text();
                tmp.chop(2);
                year = tmp.toInt();
            }
        }
    }
    if(genre.isEmpty() && year < 1000) {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                }
                break;
        }
    } else if (genre.isEmpty() && year > 1000) {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                    ms->hide(year);
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                    ss->hide(year);
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                    ms->hide(year);
                }
                break;
        }
    } else if ((!genre.isEmpty()) && year < 1000) {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                    ms->hide(genre);
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                    ss->hide(genre);
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                    ms->hide(genre);
                }
                break;
        }

    } else {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                    ms->hide(genre, year);
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                    ss->hide(genre, year);
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                    ms->hide(genre, year);
                }
                break;
        }
    }
}

void List::set_filters(){
    QStringList genre;
    QList<int> year;
    foreach(QCheckBox *genre_object, ui->group_genre->findChildren<QCheckBox *>()){
        if(genre_object->isChecked()){
            qDebug()<<"isto na da";
            genre.append(genre_object->text());
        }
    }
    foreach(QCheckBox *year_object, ui->group_year->findChildren<QCheckBox *>()){
        if(year_object->isChecked()){
            if(t<2) year.append(year_object->text().toInt());
            else {
                QString tmp = year_object->text();
                tmp.chop(2);
                year.append(tmp.toInt());
            }
        }
    }

    qDebug() << "inicio "+QString::number(t);
    qDebug() << "Genre size: " + QString::number(genre.size());
    qDebug() << "Year size: " + QString::number(year.size());

    if(genre.isEmpty() && year.isEmpty()) {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                }
                break;
        }
    } else if (genre.isEmpty() && !(year.isEmpty())) {
        qDebug() << "olá amores";
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                    ms->hide(year);
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                    ss->hide(year);
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                    ms->hide(year);
                }
                break;
        }
    } else if ((!genre.isEmpty()) && year.isEmpty()) {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                    ms->hide(genre);
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                    ss->hide(genre);
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                    ms->hide(genre);
                }
                break;
        }

    } else {
        switch (t) {
            case 0:
                foreach(movie_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<movie_scroll *>()){
                    ms->show();
                    ms->hide(genre, year);
                }
                break;
            case 1:
                foreach(serie_scroll *ss, ui->scrollAreaWidgetContents_4->findChildren<serie_scroll *>()){
                    ss->show();
                    ss->hide(genre, year);
                }
                break;
            case 2:
                foreach(music_scroll *ms, ui->scrollAreaWidgetContents_4->findChildren<music_scroll *>()){
                    ms->show();
                    ms->hide(genre, year);
                }
                break;
        }
    }


}
