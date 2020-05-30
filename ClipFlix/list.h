#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include "data.h"

namespace Ui {
class List;
}

class List : public QWidget
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = nullptr, int type = 0, Data *d = nullptr);
    ~List();

    void refresh(int type = 0);

private slots:
    void on_clear_clicked();

    void on_pushButton_clicked();

    void set_filters();

private:
    Ui::List *ui;
    int t;
};

#endif // LIST_H
