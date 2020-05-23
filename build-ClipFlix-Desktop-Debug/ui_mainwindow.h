/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_Qt;
    QAction *actionExit;
    QAction *actionHome;
    QAction *actionMovies;
    QAction *actionSeries;
    QAction *actionMusic;
    QAction *actionFavourite;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *titulo;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QFrame *line;
    QStackedWidget *tabWidget;
    QWidget *home;
    QGridLayout *gridLayout_4;
    QScrollArea *scroll_home;
    QWidget *scroll_home_contents;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QScrollArea *home_movies;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *home_movies_scroll;
    QLabel *label_2;
    QScrollArea *home_series;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *home_series_scroll;
    QLabel *label_3;
    QScrollArea *home_Music;
    QWidget *scrollAreaWidgetContents_5;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *home_music_scroll;
    QWidget *movies;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QGroupBox *group_genre;
    QGroupBox *group_year;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clear;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *series;
    QGridLayout *gridLayout_9;
    QWidget *music;
    QGridLayout *gridLayout_10;
    QWidget *favourite;
    QGridLayout *gridLayout_5;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuMenu;
    QMenu *menuGo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(854, 550);
        MainWindow->setMinimumSize(QSize(854, 550));
        MainWindow->setSizeIncrement(QSize(16, 9));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);\n"
"color: white;"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHome = new QAction(MainWindow);
        actionHome->setObjectName(QString::fromUtf8("actionHome"));
        actionMovies = new QAction(MainWindow);
        actionMovies->setObjectName(QString::fromUtf8("actionMovies"));
        actionSeries = new QAction(MainWindow);
        actionSeries->setObjectName(QString::fromUtf8("actionSeries"));
        actionMusic = new QAction(MainWindow);
        actionMusic->setObjectName(QString::fromUtf8("actionMusic"));
        actionFavourite = new QAction(MainWindow);
        actionFavourite->setObjectName(QString::fromUtf8("actionFavourite"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        titulo = new QLabel(centralWidget);
        titulo->setObjectName(QString::fromUtf8("titulo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titulo->sizePolicy().hasHeightForWidth());
        titulo->setSizePolicy(sizePolicy);
        titulo->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(titulo);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        pushButton_5->setFont(font);
        pushButton_5->setCheckable(false);

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 23));
        pushButton_4->setFont(font);
        pushButton_4->setCheckable(false);
        pushButton_4->setChecked(false);

        horizontalLayout_7->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 23));
        pushButton_3->setFont(font);
        pushButton_3->setCheckable(false);

        horizontalLayout_7->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_7->addWidget(pushButton_2);

        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setFont(font);

        horizontalLayout_7->addWidget(pushButton_1);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 0, 1, 1);

        tabWidget = new QStackedWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(20);
        tabWidget->setFont(font1);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        gridLayout_4 = new QGridLayout(home);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scroll_home = new QScrollArea(home);
        scroll_home->setObjectName(QString::fromUtf8("scroll_home"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scroll_home->sizePolicy().hasHeightForWidth());
        scroll_home->setSizePolicy(sizePolicy1);
        scroll_home->setFrameShape(QFrame::NoFrame);
        scroll_home->setFrameShadow(QFrame::Plain);
        scroll_home->setWidgetResizable(true);
        scroll_home_contents = new QWidget();
        scroll_home_contents->setObjectName(QString::fromUtf8("scroll_home_contents"));
        scroll_home_contents->setGeometry(QRect(0, 0, 804, 750));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scroll_home_contents->sizePolicy().hasHeightForWidth());
        scroll_home_contents->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(scroll_home_contents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(scroll_home_contents);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(15);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        home_movies = new QScrollArea(scroll_home_contents);
        home_movies->setObjectName(QString::fromUtf8("home_movies"));
        sizePolicy3.setHeightForWidth(home_movies->sizePolicy().hasHeightForWidth());
        home_movies->setSizePolicy(sizePolicy3);
        home_movies->setMinimumSize(QSize(0, 210));
        home_movies->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        home_movies->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 16, 208));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy4);
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        home_movies_scroll = new QHBoxLayout();
        home_movies_scroll->setSpacing(6);
        home_movies_scroll->setObjectName(QString::fromUtf8("home_movies_scroll"));

        horizontalLayout_4->addLayout(home_movies_scroll);

        home_movies->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(home_movies);

        label_2 = new QLabel(scroll_home_contents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        home_series = new QScrollArea(scroll_home_contents);
        home_series->setObjectName(QString::fromUtf8("home_series"));
        sizePolicy3.setHeightForWidth(home_series->sizePolicy().hasHeightForWidth());
        home_series->setSizePolicy(sizePolicy3);
        home_series->setMinimumSize(QSize(0, 210));
        home_series->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 16, 208));
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy4);
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        home_series_scroll = new QHBoxLayout();
        home_series_scroll->setSpacing(6);
        home_series_scroll->setObjectName(QString::fromUtf8("home_series_scroll"));

        horizontalLayout_3->addLayout(home_series_scroll);

        home_series->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(home_series);

        label_3 = new QLabel(scroll_home_contents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        home_Music = new QScrollArea(scroll_home_contents);
        home_Music->setObjectName(QString::fromUtf8("home_Music"));
        sizePolicy3.setHeightForWidth(home_Music->sizePolicy().hasHeightForWidth());
        home_Music->setSizePolicy(sizePolicy3);
        home_Music->setMinimumSize(QSize(0, 210));
        home_Music->setWidgetResizable(true);
        home_Music->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 16, 208));
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents_5->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_5->setSizePolicy(sizePolicy4);
        scrollAreaWidgetContents_5->setMinimumSize(QSize(0, 0));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        home_music_scroll = new QHBoxLayout();
        home_music_scroll->setSpacing(6);
        home_music_scroll->setObjectName(QString::fromUtf8("home_music_scroll"));

        horizontalLayout_5->addLayout(home_music_scroll);

        home_Music->setWidget(scrollAreaWidgetContents_5);

        verticalLayout->addWidget(home_Music);

        scroll_home->setWidget(scroll_home_contents);

        gridLayout_4->addWidget(scroll_home, 0, 0, 1, 1);

        tabWidget->addWidget(home);
        movies = new QWidget();
        movies->setObjectName(QString::fromUtf8("movies"));
        horizontalLayout = new QHBoxLayout(movies);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(movies);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        group_genre = new QGroupBox(frame);
        group_genre->setObjectName(QString::fromUtf8("group_genre"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(group_genre->sizePolicy().hasHeightForWidth());
        group_genre->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(group_genre, 0, 0, 1, 1);

        group_year = new QGroupBox(frame);
        group_year->setObjectName(QString::fromUtf8("group_year"));
        sizePolicy5.setHeightForWidth(group_year->sizePolicy().hasHeightForWidth());
        group_year->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(group_year, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        clear = new QPushButton(frame);
        clear->setObjectName(QString::fromUtf8("clear"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(clear);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy6.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        horizontalLayout->addWidget(frame);

        scrollArea = new QScrollArea(movies);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy7);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 634, 409));
        scrollArea->setWidget(scrollAreaWidgetContents_4);

        horizontalLayout->addWidget(scrollArea);

        tabWidget->addWidget(movies);
        series = new QWidget();
        series->setObjectName(QString::fromUtf8("series"));
        gridLayout_9 = new QGridLayout(series);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tabWidget->addWidget(series);
        music = new QWidget();
        music->setObjectName(QString::fromUtf8("music"));
        gridLayout_10 = new QGridLayout(music);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tabWidget->addWidget(music);
        favourite = new QWidget();
        favourite->setObjectName(QString::fromUtf8("favourite"));
        gridLayout_5 = new QGridLayout(favourite);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget->addWidget(favourite);

        gridLayout_2->addWidget(tabWidget, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 854, 22));
        menuBar->setDefaultUp(false);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuGo = new QMenu(menuBar);
        menuGo->setObjectName(QString::fromUtf8("menuGo"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuGo->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout_Qt);
        menuMenu->addAction(actionExit);
        menuGo->addAction(actionHome);
        menuGo->addAction(actionMovies);
        menuGo->addAction(actionSeries);
        menuGo->addAction(actionMusic);
        menuGo->addAction(actionFavourite);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionHome->setText(QApplication::translate("MainWindow", "Home", nullptr));
        actionMovies->setText(QApplication::translate("MainWindow", "Movies", nullptr));
        actionSeries->setText(QApplication::translate("MainWindow", "Series", nullptr));
        actionMusic->setText(QApplication::translate("MainWindow", "Music", nullptr));
        actionFavourite->setText(QApplication::translate("MainWindow", "Favourite", nullptr));
        titulo->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600;\">CLIPFLIX</span></p></body></html>", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Movies", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Series", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Music", nullptr));
        pushButton_1->setText(QApplication::translate("MainWindow", "Favourite", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Recommended Movies</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Recommended Series</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Recommended Music</p></body></html>", nullptr));
        group_genre->setTitle(QApplication::translate("MainWindow", "Genre:", nullptr));
        group_year->setTitle(QApplication::translate("MainWindow", "Year", nullptr));
        clear->setText(QApplication::translate("MainWindow", "Clear Filters", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Set Filters", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
        menuGo->setTitle(QApplication::translate("MainWindow", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
