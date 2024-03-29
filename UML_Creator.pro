#-------------------------------------------------
#
# Project created by QtCreator 2019-07-29T20:43:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UML_Creator
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

CONFIG += c++11

SOURCES += \
        diagramitem.cpp \
        handles.cpp\
        handle.cpp \
        diagramscene.cpp \
        diagramshapes.cpp \
        diagramview.cpp \
        mainwindow.cpp \
        properties.cpp \
        toolbar.cpp \
        main.cpp

HEADERS += \
        diagramitem.h \
        handles.h\
        handle.h \
        diagramscene.h \
        diagramshapes.h \
        diagramview.h \
        mainwindow.h \
        properties.h \
        toolbar.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    styles.txt \
    toolbar.qss

RESOURCES +=
