#ifndef MUSIC_SCROLL_H
#define MUSIC_SCROLL_H

#include <QWidget>
#include "data.h"
#include "music.h"

namespace Ui {
class music_scroll;
}

class music_scroll : public QWidget
{
    Q_OBJECT

public:
    explicit music_scroll(QWidget *parent = nullptr, Music m = Music(), Data *d = nullptr);
    ~music_scroll();

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
    Ui::music_scroll *ui;

    Music music;
};

#endif // MUSIC_SCROLL_H
