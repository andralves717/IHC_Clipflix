#ifndef CARDS_H
#define CARDS_H

#include <QWidget>
#include "movie.h"
#include "serie.h"
#include "music.h"
#include "scrolltext.h"

namespace Ui {
class cards;
}

class cards : public QWidget
{
    Q_OBJECT

public:
    explicit cards(QWidget *parent = nullptr, Movie *m = new Movie(), int type = 0);
    explicit cards(QWidget *parent = nullptr, Serie *s = new Serie(), int type = 1);
    explicit cards(QWidget *parent = nullptr, Music *m = new Music(), int type = 2);
    ~cards();

    bool operator==(const cards& c);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::cards *ui;
    ScrollText *scroll_title;

    Movie *card_movie;
    Serie *card_serie;
    Music *card_music;
    int t;
};

#endif // CARDS_H
