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

    bool add_fav_movie(Movie movie);
    bool add_fav_serie(Serie serie);
    bool add_fav_music(Music music);

    QString get_username();
    QString get_password();
    QList<Movie> get_fav_movie();
    QList<Serie> get_fav_serie();
    QList<Music> get_fav_music();

    bool valid_login(QString username, QString password);


private:
    QString _username;
    QString _password;
    QList<Movie> _fav_movie;
    QList<Serie> _fav_serie;
    QList<Music> _fav_music;
};

#endif // USER_H
