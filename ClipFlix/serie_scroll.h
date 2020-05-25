#ifndef SERIE_SCROLL_H
#define SERIE_SCROLL_H

#include <QWidget>
#include "data.h"
#include "serie.h"

namespace Ui {
class serie_scroll;
}

class serie_scroll : public QWidget
{
    Q_OBJECT

public:
    explicit serie_scroll(QWidget *parent = nullptr, Serie s = Serie(), Data *d = nullptr);
    ~serie_scroll();

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
    Ui::serie_scroll *ui;

    Serie serie;
};

#endif // SERIE_SCROLL_H
