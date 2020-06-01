#ifndef WATCH_LATER_H
#define WATCH_LATER_H

#include <QWidget>
#include "cards.h"
#include "data.h"

namespace Ui {
class watch_later;
}

class watch_later : public QWidget
{
    Q_OBJECT

public:
    explicit watch_later(QWidget *parent = nullptr, Data *d = nullptr);
    ~watch_later();

    bool refresh();

private:
    Ui::watch_later *ui;
    Data *data_wl;
};

#endif // WATCH_LATER_H
