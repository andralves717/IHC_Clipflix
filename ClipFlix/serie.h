#include <QString>
#include <QPixmap>

#ifndef SERIE_H
#define SERIE_H


class Serie
{
public:
    Serie();
    Serie(QString title);
    Serie(QString title, QList<int> years, int seasons, int rating, QString description);
    Serie(QString title, QList<int> years, int seasons, int rating, QString description, QPixmap image, QStringList genre);

    ~Serie();

    bool set_title(QString title);
    bool set_years(QList<int> years);
    bool set_years(int begin, int end);
    bool set_seasons(int seasons);
    bool set_rating(int rating);
    bool set_description(QString description);
    bool set_image(QPixmap image);
    bool set_genre(QStringList genre);
    bool set_finished(bool f);

    bool add_year(int year);

    QString get_title();
    QList<int> get_years();
    int get_first_year();
    int get_last_year();
    int get_seasons();
    int get_rating();
    QString get_description();
    QPixmap get_image();
    QStringList get_genre();
    bool finished();

    QString get_genre_string();

    bool operator==(const Serie& s);

private:
    QString _title;
    QList<int> _years;
    int _seasons;
    int _rating;
    QString _description;
    QPixmap _image;
    QStringList _genre;
    bool _finished;


};

#endif // SERIE_H
