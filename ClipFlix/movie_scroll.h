#ifndef MOVIE_SCROLL_H
#define MOVIE_SCROLL_H

#include <QWidget>
#include "data.h"
#include "movie.h"

namespace Ui {
class movie_scroll;
}

class movie_scroll : public QWidget
{
    Q_OBJECT

public:
    explicit movie_scroll(QWidget *parent = nullptr, Movie m = Movie(), Data *d = nullptr);
    ~movie_scroll();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_addFav_clicked();

private:
    Ui::movie_scroll *ui;

    Movie movie;
};

#endif // MOVIE_SCROLL_H
