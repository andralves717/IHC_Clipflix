#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "movie.h"
#include "serie.h"
#include "music.h"
#include "cards.h"
#include "list.h"
#include "data.h"
#include "favourite.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QList<Movie> movie_list();
    QList<Serie> serie_list();
    QList<Music> music_list();

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

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    login *l;
};

#endif // MAINWINDOW_H
