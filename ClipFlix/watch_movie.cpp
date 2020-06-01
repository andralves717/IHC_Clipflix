#include "watch_movie.h"
#include "ui_watch_movie.h"
#include <QDebug>

Data *data_watch_m;

watch_movie::watch_movie(QWidget *parent, Movie mw, Data *d) :
    QDialog(parent),
    ui(new Ui::watch_movie)
{
    ui->setupUi(this);
    data_watch_m=d;
    this->movie_watch = mw;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:25pt;\">"+movie_watch.get_title()+"</span></p></body></html>");
    ui->Year->setText(QString::number(movie_watch.get_year()));
    ui->genre->setText("Genre: "+movie_watch.get_genre_string());
    ui->image->setPixmap(movie_watch.get_image());
    ui->rating->setText("⭐ "+QString::number((double)movie_watch.get_rating()/10)+"/10");
    ui->lineEdit->setStyleSheet("QLineEdit{ "
                                "color:black;"
                                "background-color:lightgray;"
                                "border: 2px solid gray;"
                                "border-radius: 10px;"
                                "padding: 0 8px;"
                                "selection-background-color: darkgray;"
                                "font-size: 16px;}"
                                "QLineEdit:focus { "
                                "background-color:lightgray;}");
    ui->lineEdit->setText("Insira um comentário...");
    const QSize btnSize = QSize(75, 34);
    ui->pushButton->setFixedSize(btnSize);
    ui->pushButton->setIcon(QIcon(":/images/image/facebook.png"));
    ui->Duration->setText(QString::number(movie_watch.get_duration())+" minutes");
    this->setWindowTitle("Watch "+movie_watch.get_title());
    if(d->is_fav_user(this->movie_watch)) ui->addFav->setText("Favourite");
    if(d->is_wl_user(this->movie_watch)) ui->addWL->setText("Added to\nWatch Later");
    int width = ui->player->width();
    QPixmap player_img(":/images/image/video-player.jpg");
    player_img = player_img.scaledToWidth(width);
    ui->player->setPixmap(player_img);
}

watch_movie::~watch_movie()
{
    delete ui;
}

void watch_movie::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add to\n Favourites"){
        if(data_watch_m->add_fav_user(this->movie_watch)){
            qDebug() << "Adicionado "+ movie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_watch_m->rm_fav_user(this->movie_watch)){
            qDebug() << "Removido "+ movie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add to\n Favourites");
        }
    }
}

void watch_movie::on_addWL_clicked()
{
     if(ui->addWL->text()=="Add to\nWatch Later"){
        if(data_watch_m->add_wl_user(this->movie_watch)){
            qDebug() << "Adicionado "+ movie_watch.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Added to\nWatch Later");
        }
    } else {
        if(data_watch_m->rm_wl_user(this->movie_watch)){
            qDebug() << "Removido "+ movie_watch.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Add to\nWatch Later");
        }
    }

}

void watch_movie::on_lineEdit_returnPressed()
{
    QLabel * newLabel = new QLabel();
    newLabel->setMinimumHeight(20);
    newLabel->setText(ui->lineEdit->text());
    QGroupBox * newQGroupBox= new QGroupBox();
    QVBoxLayout *vbox= new QVBoxLayout;
    vbox->addWidget(newLabel);
    newQGroupBox->setTitle("User: demo");
    newQGroupBox->setStyleSheet("* {font: 10pt MS Shell Dlg 2;font-weight: bold}");
    newQGroupBox->setMaximumHeight(200);
    newLabel->setStyleSheet("* {font: 8pt MS Shell Dlg 2}");
    newQGroupBox->setLayout(vbox);
    ui->verticalLayout_4->addWidget(newQGroupBox);
}

void watch_movie::on_pushButton_2_pressed()
{
    QLabel * newLabel = new QLabel();
    newLabel->setMinimumHeight(20);
    newLabel->setText(ui->lineEdit->text());
    QGroupBox * newQGroupBox= new QGroupBox();
    QVBoxLayout *vbox= new QVBoxLayout;
    vbox->addWidget(newLabel);
    newQGroupBox->setTitle("User: demo");
    newQGroupBox->setStyleSheet("* {font: 10pt MS Shell Dlg 2;font-weight: bold}");
    newQGroupBox->setMaximumHeight(200);
    newLabel->setStyleSheet("* {font: 8pt MS Shell Dlg 2}");
    newQGroupBox->setLayout(vbox);
    ui->verticalLayout_4->addWidget(newQGroupBox);
}

