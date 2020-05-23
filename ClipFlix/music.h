#include <QString>
#include <QPixmap>
#include <QTime>

#ifndef MUSIC_H
#define MUSIC_H


class Music
{
public:
    Music();
    Music(QString title, QString author);
    Music(QString title, QString author, QString album);
    Music(QString title, QString author, QString album, int year, QTime duration, QPixmap image, QString genre);

    ~Music();

    bool set_title(QString title);
    bool set_author(QString author);
    bool set_album(QString album);
    bool set_year(int year);
    bool set_duration(QTime duration);
    bool set_image(QPixmap image);
    bool set_genre(QString genre);

    QString get_title();
    QString get_author();
    QString get_album();
    int get_year();
    QTime get_duration();
    QPixmap get_image();
    QString get_genre();

    bool operator==(const Music& m);


private:
    QString _title;
    QString _author;
    QString _album;
    QTime _duration;
    int _year;
    QString _genre;
    QPixmap _image;
};

#endif // MUSIC_H
