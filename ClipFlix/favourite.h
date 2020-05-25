#ifndef FAVOURITE_H
#define FAVOURITE_H

#include <QWidget>
#include "cards.h"
#include "user.h"

namespace Ui {
class favourite;
}

class favourite : public QWidget
{
    Q_OBJECT

public:
    explicit favourite(QWidget *parent = nullptr, User *u = new User());
    ~favourite();

    bool refresh();

private:
    Ui::favourite *ui;
    User *user;
};

#endif // FAVOURITE_H
