#-------------------------------------------------
#
# Project created by QtCreator 2012-01-12T01:59:26
#
#-------------------------------------------------

QT       += core gui

TARGET = X6Macro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keysticker.cpp \
    Input.cpp \
    keymap.cpp

HEADERS  += mainwindow.h \
    keysticker.h \
    Input.h \
    keymap.h \
    main.h

FORMS    += mainwindow.ui

win32: LIBS += d:/Dossier-X/lib/dinput8.lib
win32: LIBS += d:/Dossier-X/lib/dxguid.lib

INCLUDEPATH += d:/Dossier-X/include
