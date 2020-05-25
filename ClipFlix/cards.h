#ifndef CARDS_H
#define CARDS_H

#include <QWidget>
#include "movie.h"
#include "serie.h"
#include "music.h"

namespace Ui {
class cards;
}

class cards : public QWidget
{
    Q_OBJECT

public:
    explicit cards(QWidget *parent = nullptr, Movie *m = new Movie());
    explicit cards(QWidget *parent = nullptr, Serie *s = new Serie());
    explicit cards(QWidget *parent = nullptr, Music *m = new Music());
    ~cards();

    bool operator==(const cards& c);

private:
    Ui::cards *ui;
};

#endif // CARDS_H
