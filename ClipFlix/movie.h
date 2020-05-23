#include <QString>
#include <QPixmap>

#ifndef MOVIE_H
#define MOVIE_H


class Movie
{
public:
    Movie();
    Movie(QString title);
    Movie(QString title, int year, int duration, int rating, QString description);
    Movie(QString title, int year, int duration, int rating, QString description, QPixmap image, QStringList genre);

    ~Movie();

    bool set_title(QString title);
    bool set_year(int year);
    bool set_duration(int duration);
    bool set_rationg(int rating);
    bool set_description(QString description);
    bool set_image(QPixmap image);
    bool set_genre(QStringList genre);

    QString get_title();
    int get_year();
    int get_duration();
    int get_rating();
    QString get_description();
    QPixmap get_image();
    QStringList get_genre();

    bool operator==(const Movie& m);

private:
    QString _title;
    int _year;
    int _duration;
    int _rating;
    QString _description;
    QPixmap _image;
    QStringList _genre;
};

#endif // MOVIE_H
