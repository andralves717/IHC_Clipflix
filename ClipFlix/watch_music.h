#ifndef WATCH_MUSIC_H
#define WATCH_MUSIC_H

#include <QDialog>
#include "music.h"
#include "data.h"

namespace Ui {
class watch_music;
}

class watch_music : public QDialog
{
    Q_OBJECT

public:
    explicit watch_music(QWidget *parent = nullptr, Music music_watch = Music(), Data *d = nullptr);
    ~watch_music();

private slots:
    void on_addFav_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_pressed();

    void on_addWL_clicked();

private:
    Ui::watch_music *ui;

    Music music_watch;
};

#endif // WATCH_MUSIC_H
