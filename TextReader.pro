#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T15:08:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextReader
TEMPLATE = app
DESTDIR = ../Images
linux-g++:LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_calib3d
INCLUDEPATH = include
SOURCES += main.cpp\
        mainwindow.cpp \
    processimage.cpp

HEADERS  += mainwindow.h \
    processimage.h

FORMS    += mainwindow.ui
