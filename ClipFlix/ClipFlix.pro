#-------------------------------------------------
#
# Project created by QtCreator 2020-05-19T10:29:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClipFlix
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        cards.cpp \
        data.cpp \
        favourite.cpp \
        list.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        movie.cpp \
        movie_scroll.cpp \
        music.cpp \
        music_scroll.cpp \
        serie.cpp \
        serie_scroll.cpp \
        user.cpp

HEADERS += \
        cards.h \
        data.h \
        favourite.h \
        list.h \
        login.h \
        mainwindow.h \
        movie.h \
        movie_scroll.h \
        music.h \
        music_scroll.h \
        serie.h \
        serie_scroll.h \
        user.h

FORMS += \
        cards.ui \
        favourite.ui \
        list.ui \
        login.ui \
        mainwindow.ui \
        movie_scroll.ui \
        music_scroll.ui \
        serie_scroll.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
