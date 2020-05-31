#ifndef WATCH_MOVIE_H
#define WATCH_MOVIE_H

#include <QDialog>
#include "movie.h"
#include "data.h"

namespace Ui {
class watch_movie;
}

class watch_movie : public QDialog
{
    Q_OBJECT

public:
    explicit watch_movie(QWidget *parent = nullptr, Movie movie_watch = Movie(), Data *d = nullptr);
    ~watch_movie();

private slots:
    void on_addFav_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_pressed();


private:
    Ui::watch_movie *ui;

    Movie movie_watch;

};

#endif // WATCH_MOVIE_H
