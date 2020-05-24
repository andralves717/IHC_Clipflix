#include "serie.h"

Serie::Serie()
{

}

Serie::Serie(QString title){
    this->_title = title;
    this->_finished = true;
}
Serie::Serie(QString title, QList<int> years, int seasons, int rating, QString description){
    this->_title = title;
    this->_years = years;
    this->_seasons = seasons;
    this->_rating = rating;
    this->_description = description;
    this->_finished = true;
}
Serie::Serie(QString title, QList<int> years, int seasons, int rating, QString description, QPixmap image, QStringList genre){
    this->_title = title;
    this->_years = years;
    this->_seasons = seasons;
    this->_rating = rating;
    this->_description = description;
    this->_image = image.scaledToHeight(200,Qt::SmoothTransformation);
    this->_genre = genre;
    this->_finished = true;
}

Serie::~Serie(){

}

bool Serie::set_title(QString title){
    this->_title = title;
    return true;
}
bool Serie::set_years(QList<int> years){
    if(years.size() > 1 && years.constFirst() > years.constLast()) return false;
    this->_years = years;
    return true;
}
bool Serie::set_years(int begin, int end){
    if(begin>end) return false;
    QList<int> total_years;
    for(int i=begin;i<end+1;i++){
        total_years.append(i);
    }
    if(total_years.constFirst() != begin || total_years.constLast() != end) return false;
    this->_years = total_years;
    return true;
}
bool Serie::set_seasons(int seasons){
    this->_seasons = seasons;
    return true;
}
bool Serie::set_rating(int rating){
    this->_rating = rating;
    return true;
}
bool Serie::set_description(QString description){
    this->_description = description;
    return true;
}
bool Serie::set_image(QPixmap image){
    this->_image = image.scaledToHeight(200,Qt::SmoothTransformation);
    return true;
}
bool Serie::set_genre(QStringList genre){
    this->_genre = genre;
    return true;
}

bool Serie::set_finished(bool f){
    this->_finished = f;
    return true;
}

bool Serie::add_year(int year){
    if(_years.contains(year)) return true;
    if(year < _years.constLast()){
        for(int i = 0; i < this->_years.size(); i++){
            if(_years.at(i) > year){
                _years.insert(i,year);
                return true;
            }
        }
        return false;
    }
    _years.append(year);
    return true;
}

QString Serie::get_title(){
    return this->_title;
}
QList<int> Serie::get_years(){
    return this->_years;
}

int Serie::get_first_year(){
    return this->_years.constFirst();
}
int Serie::get_last_year(){
    return this->_years.constLast();
}

int Serie::get_seasons(){
    return this->_seasons;
}
int Serie::get_rating(){
    return this->_rating;
}
QString Serie::get_description(){
    return this->_description;
}
QPixmap Serie::get_image(){
    return this->_image;
}
QStringList Serie::get_genre(){
    return this->_genre;
}

QString Serie::get_genre_string(){
    QString ret;
    foreach (QString s, this->_genre) {
        ret.append(s + ", ");
    }
    ret.chop(2);
    return ret;
}

bool Serie::finished(){
    return this->_finished;
}

bool Serie::operator==(const Serie& s){
    if(     this->_years == s._years &&
            this->_genre == s._genre &&
            this->_title == s._title &&
            this->_rating == s._rating &&
            this->_seasons == s._seasons &&
            this->_finished == s._finished &&
            this->_description == s._description)
                return true;
    return false;
}
