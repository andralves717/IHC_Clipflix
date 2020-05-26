#ifndef WATCH_SERIE_H
#define WATCH_SERIE_H

#include <QDialog>
#include "serie.h"
#include "data.h"

namespace Ui {
class watch_serie;
}

class watch_serie : public QDialog
{
    Q_OBJECT

public:
    explicit watch_serie(QWidget *parent = nullptr, Serie serie_watch = Serie(), Data *d = nullptr);
    ~watch_serie();

private slots:
    void on_addFav_clicked();

private:
    Ui::watch_serie *ui;

    Serie serie_watch;
};

#endif // WATCH_SERIE_H
