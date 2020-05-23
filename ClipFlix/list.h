#ifndef LIST_H
#define LIST_H

#include <QWidget>

namespace Ui {
class List;
}

class List : public QWidget
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = nullptr, int type = 0);
    ~List();

private slots:
    void on_clear_clicked();

private:
    Ui::List *ui;
};

#endif // LIST_H
