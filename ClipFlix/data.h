#ifndef DATA_H
#define DATA_H

#include <QList>
#include "user.h"
#include "movie.h"
#include "serie.h"
#include "music.h"

class Data
{
public:
    Data();
    Data(QList<User> users, QList<Movie> movies, QList<Serie> series, QList<Music> musics);

    bool set_users(QList<User> users);
    bool set_movies(QList<Movie> movies);
    bool set_series(QList<Serie> series);
    bool set_musics(QList<Music> musics);
    bool set_active_user(User username);

    bool add_user(User user);
    bool add_movie(Movie movie);
    bool add_serie(Serie serie);
    bool add_music(Music music);

    QList<User> get_users();
    QList<Movie> get_movies();
    QList<Serie> get_series();
    QList<Music> get_musics();
    User get_active_user();

    bool add_fav_user(Movie m);
    bool add_fav_user(Serie s);
    bool add_fav_user(Music m);

    bool rm_fav_user(Movie m);
    bool rm_fav_user(Serie s);
    bool rm_fav_user(Music m);


private:

    QList<User> users;
    QList<Movie> movies;
    QList<Serie> series;
    QList<Music> musics;
    User active_user;
};

#endif // DATA_H
