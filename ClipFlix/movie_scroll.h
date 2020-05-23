#ifndef MOVIE_SCROLL_H
#define MOVIE_SCROLL_H

#include <QWidget>

namespace Ui {
class movie_scroll;
}

class movie_scroll : public QWidget
{
    Q_OBJECT

public:
    explicit movie_scroll(QWidget *parent = nullptr);
    ~movie_scroll();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_addFav_clicked();

private:
    Ui::movie_scroll *ui;
};

#endif // MOVIE_SCROLL_H
