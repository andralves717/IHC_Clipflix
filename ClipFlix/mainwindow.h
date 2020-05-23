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



    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_5_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    login *l;
};

#endif // MAINWINDOW_H
