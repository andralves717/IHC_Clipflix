#include "data.h"
#include "QDebug"

Data::Data()
{

}
Data::Data(QList<User> users, QList<Movie> movies, QList<Serie> series, QList<Music> musics){
    this->users = users;
    this->movies = movies;
    this->series = series;
    this->musics = musics;
}

bool Data::set_users(QList<User> users){
    this->users = users;
    return true;
}
bool Data::set_movies(QList<Movie> movies){
    this->movies = movies;
    return true;
}
bool Data::set_series(QList<Serie> series){
    this->series = series;
    return true;
}
bool Data::set_musics(QList<Music> musics){
    this->musics = musics;
    return true;
}

bool Data::set_active_user(User username){
    if(!(this->get_users().contains(username))) return false;
    this->active_user = username;
    return true;
}

bool Data::add_user(User user){
    if(this->users.contains(user)) return false;
    this->users.append(user);
    return true;
}
bool Data::add_movie(Movie movie){
    if(this->movies.contains(movie)) return false;
    this->movies.append(movie);
    return true;
}
bool Data::add_serie(Serie serie){
    if(this->series.contains(serie)) return false;
    this->series.append(serie);
    return true;
}
bool Data::add_music(Music music){
    if(this->musics.contains(music)) return false;
    this->musics.append(music);
    return true;
}

QList<User> Data::get_users(){
    return this->users;
}
QList<Movie> Data::get_movies(){
    return this->movies;
}
QList<Serie> Data::get_series(){
    return this->series;
}
QList<Music> Data::get_musics(){
    return this->musics;
}

User *Data::get_active_user(){
    return &this->active_user;
}

bool Data::add_fav_user(Movie m){
    if(this->active_user.add_fav_movie(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::add_fav_user(Serie s){
    if(this->active_user.add_fav_serie(s)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::add_fav_user(Music m){
    if(this->active_user.add_fav_music(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}

bool Data::rm_fav_user(Movie m){
    if(this->active_user.rm_fav_movie(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::rm_fav_user(Serie s){
    if(this->active_user.rm_fav_serie(s)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::rm_fav_user(Music m){
    if(this->active_user.rm_fav_music(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}

bool Data::is_fav_user(Movie m){
    return this->active_user.get_fav_movie().contains(m);
}
bool Data::is_fav_user(Serie m){
    return this->active_user.get_fav_serie().contains(m);
}
bool Data::is_fav_user(Music m){
    return this->active_user.get_fav_music().contains(m);
}

bool Data::add_wl_user(Movie m){
    if(this->active_user.add_wl_movie(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::add_wl_user(Serie s){
    if(this->active_user.add_wl_serie(s)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::add_wl_user(Music m){
    if(this->active_user.add_wl_music(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}

bool Data::rm_wl_user(Movie m){
    if(this->active_user.rm_wl_movie(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::rm_wl_user(Serie s){
    if(this->active_user.rm_wl_serie(s)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}
bool Data::rm_wl_user(Music m){
    if(this->active_user.rm_wl_music(m)){
        int index = this->users.size();
        foreach (User u, this->users) {
            if(u.get_username() == this->active_user.get_username()){
                index = this->users.indexOf(u);
                this->users.replace(index, this->active_user);
                return true;
            }
        }
        return !(index == this->users.size());
    }
    return false;
}

bool Data::is_wl_user(Movie m){
    return this->active_user.get_wl_movie().contains(m);
}
bool Data::is_wl_user(Serie m){
    return this->active_user.get_wl_serie().contains(m);
}
bool Data::is_wl_user(Music m){
    return this->active_user.get_wl_music().contains(m);
}
