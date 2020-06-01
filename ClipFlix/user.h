#include <QString>
#include "movie.h"
#include "serie.h"
#include "music.h"

#ifndef USER_H
#define USER_H


class User
{
public:
    User();
    User(QString username, QString password);
    User(QString username, QString password, QList<Movie> fav_movies, QList<Serie> fav_series, QList<Music> fav_musics);

    ~User();

    bool set_username(QString username);
    bool set_password(QString password);

    bool set_fav_movie(QList<Movie> fav_movies);
    bool set_fav_serie(QList<Serie> fav_series);
    bool set_fav_music(QList<Music> fav_musics);

    bool set_wl_movie(QList<Movie> fav_movies);
    bool set_wl_serie(QList<Serie> fav_series);
    bool set_wl_music(QList<Music> fav_musics);

    bool add_fav_movie(Movie movies);
    bool add_fav_serie(Serie serie);
    bool add_fav_music(Music music);

    bool add_wl_movie(Movie movies);
    bool add_wl_serie(Serie serie);
    bool add_wl_music(Music music);

    bool rm_fav_movie(Movie movies);
    bool rm_fav_serie(Serie serie);
    bool rm_fav_music(Music music);

    bool rm_wl_movie(Movie movies);
    bool rm_wl_serie(Serie serie);
    bool rm_wl_music(Music music);

    QString get_username();
    QString get_password();
    QList<Movie> get_fav_movie();
    QList<Serie> get_fav_serie();
    QList<Music> get_fav_music();

    QList<Movie> get_wl_movie();
    QList<Serie> get_wl_serie();
    QList<Music> get_wl_music();

    bool valid_login(QString username, QString password);

    bool operator==(const User& u);


private:
    QString _username;
    QString _password;

    QList<Movie> _fav_movie;
    QList<Serie> _fav_serie;
    QList<Music> _fav_music;

    QList<Movie> _wl_movie;
    QList<Serie> _wl_serie;
    QList<Music> _wl_music;
};

#endif // USER_H
