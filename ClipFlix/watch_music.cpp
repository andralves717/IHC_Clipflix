#include "watch_music.h"
#include "ui_watch_music.h"
#include <QDebug>
#include <QGroupBox>

Data *data_watch_mu;

watch_music::watch_music(QWidget *parent, Music mw, Data *d) :
    QDialog(parent),
    ui(new Ui::watch_music)
{
    ui->setupUi(this);
    data_watch_mu=d;
    this->music_watch = mw;
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:25pt;\">"+music_watch.get_title()+"</span></p></body></html>");
    ui->Year->setText(QString::number(music_watch.get_year()));
    ui->genre->setText("Genre: "+music_watch.get_genre());
    ui->image->setPixmap(music_watch.get_image());
    ui->album->setText("Album: "+music_watch.get_album());
    ui->rating->setText(music_watch.get_author());
    ui->time_label->setText(mw.get_duration().toString("mm:ss") + " minutes");
    this->setWindowTitle("Watch "+music_watch.get_title());
    if(d->is_fav_user(this->music_watch)) ui->addFav->setText("Favourite");
    const QSize btnSize = QSize(75, 34);
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
    ui->pushButton->setFixedSize(btnSize);
    ui->pushButton->setIcon(QIcon(":/images/image/facebook.png"));
    if(d->is_fav_user(this->music_watch)) ui->addFav->setText("Favourite");
    if(d->is_wl_user(this->music_watch)) ui->addWL->setText("Added to\nWatch Later");
    int width = ui->player->width();
    QPixmap player_img(":/images/image/video-player.jpg");
    player_img = player_img.scaledToWidth(width);
    ui->player->setPixmap(player_img);

}

watch_music::~watch_music()
{
    delete ui;
}

void watch_music::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add to\n Favourites"){
        if(data_watch_mu->add_fav_user(this->music_watch)){
            qDebug() << "Adicionado "+ music_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_watch_mu->rm_fav_user(this->music_watch)){
            qDebug() << "Removido "+ music_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add to\n Favourites");
        }
    }
}

void watch_music::on_addWL_clicked()
{
    if(ui->addWL->text()=="Add to\nWatch Later"){
        if(data_watch_mu->add_wl_user(this->music_watch)){
            qDebug() << "Adicionado "+ music_watch.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Added to\nWatch Later");
        }
    } else {
        if(data_watch_mu->rm_wl_user(this->music_watch)){
            qDebug() << "Removido "+ music_watch.get_title()+" do Watch Later com sucesso!";
            ui->addWL->setText("Add to\nWatch Later");
        }
    }
}

void watch_music::on_lineEdit_returnPressed()
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
    ui->verticalLayout_6->addWidget(newQGroupBox);
}

void watch_music::on_pushButton_2_pressed()
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
    ui->verticalLayout_6->addWidget(newQGroupBox);
}

