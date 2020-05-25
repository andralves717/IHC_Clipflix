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

    void hide();
    void hide(QString genre, int year);
    void hide(int year);
    void hide(QString genre);

    void show();
    void show(QString genre, int year);
    void show(QString genre);
    void show(int year);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_addFav_clicked();

private:
    Ui::music_scroll *ui;

    Music music;
};

#endif // MUSIC_SCROLL_H
