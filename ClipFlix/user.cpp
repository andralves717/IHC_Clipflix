#include "user.h"

User::User()
{

}
User::User(QString username, QString password){
    this->_username = username;
    this->_password = password;
}
User::User(QString username, QString password, QList<Movie> fav_movies, QList<Serie> fav_series, QList<Music> fav_musics){
    this->_username = username;
    this->_password = password;
    this->_fav_movie = fav_movies;
    this->_fav_serie = fav_series;
    this->_fav_music = fav_musics;
}

User::~User(){}

bool User::set_username(QString username){
    this->_username = username;
    return true;
}
bool User::set_password(QString password){
    this->_password = password;
    return true;
}
bool User::set_fav_movie(QList<Movie> fav_movies){
    this->_fav_movie = fav_movies;
    return true;
}
bool User::set_fav_serie(QList<Serie> fav_series){
    this->_fav_serie = fav_series;
    return true;
}
bool User::set_fav_music(QList<Music> fav_musics){
    this->_fav_music = fav_musics;
    return true;
}

bool User::add_fav_movie(const Movie movie){
    if(this->_fav_movie.contains(movie)) return false;
    this->_fav_movie.append(movie);
    return true;
}
bool User::add_fav_serie(const Serie serie){
    if(this->_fav_serie.contains(serie)) return false;
    this->_fav_serie.append(serie);
    return true;
}
bool User::add_fav_music(const Music music){
    if(this->_fav_music.contains(music)) return false;
    this->_fav_music.append(music);
    return true;
}

bool User::rm_fav_movie(const Movie movie){
    if(!this->_fav_movie.contains(movie)) return false;
    this->_fav_movie.removeAll(movie);
    return true;
}
bool User::rm_fav_serie(const Serie serie){
    if(!this->_fav_serie.contains(serie)) return false;
    this->_fav_serie.removeAll(serie);
    return true;
}
bool User::rm_fav_music(const Music music){
    if(!this->_fav_music.contains(music)) return false;
    this->_fav_music.removeAll(music);
    return true;
}

QString User::get_username(){
    return this->_username;
}
QList<Movie> User::get_fav_movie(){
    return this->_fav_movie;
}
QList<Serie> User::get_fav_serie(){
    return this->_fav_serie;
}
QList<Music> User::get_fav_music(){
    return this->_fav_music;
}

bool User::valid_login(QString username, QString password){
    if(this->_username == username && this->_password == password) return true;
    return false;
}

bool User::operator==(const User& u){
    if(this->_username == u._username) return true;
    return false;
}
