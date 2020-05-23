#include "data.h"

data::data()
{

}
data::data(QList<User> users, QList<Movie> movies, QList<Serie> series, QList<Music> musics){
    this->users = users;
    this->movies = movies;
    this->series = series;
    this->musics = musics;
}

bool data::set_users(QList<User> users){
    this->users = users;
    return true;
}
bool data::set_movies(QList<Movie> movies){
    this->movies = movies;
    return true;
}
bool data::set_series(QList<Serie> series){
    this->series = series;
    return true;
}
bool data::set_musics(QList<Music> musics){
    this->musics = musics;
    return true;
}

bool data::add_user(User user){
    if(this->users.contains(user)) return false;
    this->users.append(user);
    return true;
}
bool data::add_movie(Movie movie){
    if(this->movies.contains(movie)) return false;
    this->movies.append(movie);
    return true;
}
bool data::add_serie(Serie serie){
    if(this->series.contains(serie)) return false;
    this->series.append(serie);
    return true;
}
bool data::add_music(Music music){
    if(this->musics.contains(music)) return false;
    this->musics.append(music);
    return true;
}

QList<User> data::get_users(){
    return this->users;
}
QList<Movie> data::get_movies(){
    return this->movies;
}
QList<Serie> data::get_series(){
    return this->series;
}
QList<Music> data::get_musics(){
    return this->musics;
}
