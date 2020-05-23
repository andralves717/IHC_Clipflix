#include "movie.h"

Movie::Movie()
{

}

Movie::Movie(QString title){
    this->_title = title;
}
Movie::Movie(QString title, int year, int duration, int rating, QString description){
    this->_title = title;
    this->_year = year;
    this->_duration = duration;
    this->_rating = rating;
    this->_description = description;
}
Movie::Movie(QString title, int year, int duration, int rating, QString description, QPixmap image, QStringList genre){
    this->_title = title;
    this->_year = year;
    this->_duration = duration;
    this->_rating = rating;
    this->_description = description;
    this->_image = image.scaledToHeight(200,Qt::SmoothTransformation);
    this->_genre = genre;
}

Movie::~Movie(){

}

bool Movie::set_title(QString title){
    this->_title = title;
    return true;
}
bool Movie::set_year(int year){
    this->_year = year;
    return true;
}
bool Movie::set_duration(int duration){
    this->_duration = duration;
    return true;
}
bool Movie::set_rationg(int rating){
    this->_rating = rating;
    return true;
}
bool Movie::set_description(QString description){
    this->_description = description;
    return true;
}
bool Movie::set_image(QPixmap image){
    this->_image = image.scaledToHeight(200,Qt::SmoothTransformation);
    return true;
}
bool Movie::set_genre(QStringList genre){
    this->_genre = genre;
    return true;
}

QString Movie::get_title(){
    return this->_title;
}
int Movie::get_year(){
    return this->_year;
}
int Movie::get_duration(){
    return this->_duration;
}
int Movie::get_rating(){
    return this->_rating;
}
QString Movie::get_description(){
    return this->_description;
}
QPixmap Movie::get_image(){
    return this->_image;
}
QStringList Movie::get_genre(){
    return this->_genre;
}

bool Movie::operator==(const Movie& m){
    if(     this->_year == m._year &&
            this->_genre == m._genre &&
            this->_title == m._title &&
            this->_rating == m._rating &&
            this->_duration == m._duration &&
            this->_description == m._description)
                return true;
    return false;
}
