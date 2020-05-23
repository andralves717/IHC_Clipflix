#include "list.h"
#include "ui_list.h"
#include <QRadioButton>
#include "movie_scroll.h"

List::List(QWidget *parent, int type) :
    QWidget(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);

    QVBoxLayout *vbox_genre = new QVBoxLayout;
    QRadioButton *genre[9];
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
        genre[i] = new QRadioButton(this);
        genre[i]->setText(genre_tex.at(i));
        vbox_genre->addWidget(genre[i]);
    }
    ui->group_genre->setLayout(vbox_genre);

    QVBoxLayout *vbox_year = new QVBoxLayout;
    QRadioButton *year[4];

    for (int i=0; i<4;i++){
        year[i] = new QRadioButton(this);
        year[i]->setText(QString::number(2020-i));
        vbox_year->addWidget(year[i]);
    }

    ui->group_year->setLayout(vbox_year);

    movie_scroll *movies = new movie_scroll(this);
    ui->scroll_layout->addWidget(movies);
    ui->scroll_layout->addWidget(movies);
}

List::~List()
{
    delete ui;
}

void List::on_clear_clicked()
{
    foreach (QRadioButton *genre_object, ui->group_genre->findChildren<QRadioButton *>()) {
        if(genre_object->isChecked()){
            genre_object->setAutoExclusive(false);
            genre_object->setChecked(false);
            genre_object->setAutoExclusive(true);
        }
    }
    foreach (QRadioButton *year_object, ui->group_year->findChildren<QRadioButton *>()) {
        if(year_object->isChecked()){
            year_object->setAutoExclusive(false);
            year_object->setChecked(false);
            year_object->setAutoExclusive(true);
        }
    }
}
