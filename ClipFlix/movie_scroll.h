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

    void refresh();

    void hide();
    void hide(QString genre, int year);
    void hide(int year);
    void hide(QString genre);

    void show();
    void show(QString genre, int year);
    void show(QString genre);
    void show(int year);

    void hide(QStringList genre_lst, QList<int> years);
    void hide(QList<int> years);
    void hide(QStringList genre_lst);

    void show(QStringList genre_lst, QList<int> years);
    void show(QStringList genre_lst);
    void show(QList<int> years);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_addFav_clicked();
    void on_addWL_clicked();

private:
    Ui::movie_scroll *ui;

    Movie movie;
};

#endif // MOVIE_SCROLL_H
