#ifndef FAVOURITE_H
#define FAVOURITE_H

#include <QWidget>
#include "cards.h"
#include "data.h"

namespace Ui {
class favourite;
}

class favourite : public QWidget
{
    Q_OBJECT

public:
    explicit favourite(QWidget *parent = nullptr, Data *d = nullptr);
    ~favourite();

    bool refresh();

private:
    Ui::favourite *ui;
    Data *data_fav;
};

#endif // FAVOURITE_H
