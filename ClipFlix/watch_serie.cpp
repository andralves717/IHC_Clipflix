#include "watch_serie.h"
#include "ui_watch_serie.h"
#include <QDebug>
#include <QGroupBox>

Data *data_watch_s;

watch_serie::watch_serie(QWidget *parent, Serie mw, Data *d) :
    QDialog(parent),
    ui(new Ui::watch_serie)
{
    ui->setupUi(this);
    data_watch_s=d;

    this->serie_watch = mw;
    QString years = "("+QString::number(serie_watch.get_years().constFirst())+"-";
    if(serie_watch.finished()){
        if(serie_watch.get_seasons() == 1) years = QString::number(serie_watch.get_years().constFirst());
        else years += QString::number(serie_watch.get_years().constLast()) + ")";
    }
    else years + ")";
    ui->title->setTextFormat(Qt::RichText);
    ui->title->setText("<html><head/><body><p><span style=\" font-size:25pt;\">"+serie_watch.get_title()+"</span></p></body></html>");
    ui->Year->setText(years);
    ui->genre->setText("Genre: "+serie_watch.get_genre_string());
    ui->image->setPixmap(serie_watch.get_image());
    ui->rating->setText("⭐ "+QString::number((double)serie_watch.get_rating()/10)+"/10");
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
    ui->Duration->setText(QString::number(serie_watch.get_seasons())+" seasons");
    this->setWindowTitle("Watch "+serie_watch.get_title());
    if(d->is_fav_user(this->serie_watch)) ui->addFav->setText("Favourite");
    if(d->is_wl_user(this->serie_watch)) ui->addWL->setText("Added to\nWatch Later");
}

watch_serie::~watch_serie()
{
    delete ui;
}

void watch_serie::on_addFav_clicked()
{
    if(ui->addFav->text()=="Add to\n Favourites"){
        if(data_watch_s->add_fav_user(this->serie_watch)){
            qDebug() << "Adicionado "+ serie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Favourite");
        }
    } else {
        if(data_watch_s->rm_fav_user(this->serie_watch)){
            qDebug() << "Removido "+ serie_watch.get_title()+" aos favoritos com sucesso!";
            ui->addFav->setText("Add to\n Favourites");
        }
    }
}

void watch_serie::on_addWL_clicked()
{
    if(ui->addWL->text()=="Add to\nWatch Later"){
        if(data_watch_s->add_wl_user(this->serie_watch)){
            qDebug() << "Adicionado "+ serie_watch.get_title()+" ao Watch Later com sucesso!";
            ui->addWL->setText("Added to\nWatch Later");
        }
    } else {
        if(data_watch_s->rm_wl_user(this->serie_watch)){
            qDebug() << "Removido "+ serie_watch.get_title()+" do Watch Later com sucesso!";
            ui->addWL->setText("Add to\nWatch Later");
        }
    }
}

void watch_serie::on_lineEdit_returnPressed()
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

void watch_serie::on_pushButton_2_pressed()
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

