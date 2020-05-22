#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_Qt_triggered();

    void on_actionExit_triggered();

    void on_actionHome_triggered();

    void on_actionMovies_triggered();

    void on_actionMusic_triggered();

    void on_actionSeries_triggered();

    void on_actionFavourite_triggered();

private:
    Ui::MainWindow *ui;
    login *l;
};

#endif // MAINWINDOW_H
