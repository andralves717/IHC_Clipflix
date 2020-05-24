#include "music.h"

Music::Music()
{

}

Music::Music(QString title, QString author){
    this->_title = title;
    this->_author = author;
}

Music::Music(QString title, QString author, QString album){
    this->_title = title;
    this->_author = author;
    this->_album = album;
}

Music::Music(QString title, QString author, QString album, int year, QTime duration, QPixmap image, QString genre){
    this->_title = title;
    this->_author = author;
    this->_album = album;
    this->_year = year;
    this->_duration = duration;
    this->_image = image.scaledToHeight(200,Qt::SmoothTransformation);
    this->_genre = genre;
}

Music::~Music(){

}

bool Music::set_title(QString title){
    this->_title = title;
    return true;
}
bool Music::set_author(QString author){
    this->_author = author;
    return true;
}
bool Music::set_album(QString album){
    this->_album = album;
    return true;
}
bool Music::set_year(int year){
    this->_year = year;
    return true;
}
bool Music::set_duration(QTime duration){
    this->_duration = duration;
    return true;
}
bool Music::set_image(QPixmap image){
    this->_image = image.scaledToHeight(200,Qt::SmoothTransformation);
    return true;
}
bool Music::set_genre(QString genre){
    this->_genre = genre;
    return true;
}

QString Music::get_title(){
    return this->_title;
}
QString Music::get_author(){
    return this->_author;
}
QString Music::get_album(){
    return this->_album;
}
int Music::get_year(){
    return this->_year;
}
QTime Music::get_duration(){
    return this->_duration;
}
QPixmap Music::get_image(){
    return this->_image;
}
QString Music::get_genre(){
    return this->_genre;
}

bool Music::operator==(const Music& m){
    if(     this->_year == m._year &&
            this->_genre == m._genre &&
            this->_title == m._title &&
            this->_duration == m._duration &&
            this->_album == m._album &&
            this->_author == m._author)
                return true;
    return false;
}
