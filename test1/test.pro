#-------------------------------------------------
#
# Project created by QtCreator 2016-01-24T19:18:44
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
DEFINES += PLATFORM_QT

SOURCES += main.cpp\
        mainwindow.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    win_qextserialport.cpp \
    DJI_LIB/DJI_Pro_App.cpp \
    DJI_LIB/DJI_Pro_Codec.cpp \
    DJI_LIB/DJI_Pro_Hw.cpp \
    DJI_LIB/DJI_Pro_Link.cpp \
    DJI_LIB/DJI_Pro_Rmu.cpp

HEADERS  += mainwindow.h \
    qextserialbase.h \
    qextserialport.h \
    win_qextserialport.h \
    DJI_LIB/DJI_Pro_App.h \
    DJI_LIB/DJI_Pro_Codec.h \
    DJI_LIB/DJI_Pro_Config.h \
    DJI_LIB/DJI_Pro_Hw.h \
    DJI_LIB/DJI_Pro_Link.h \
    DJI_LIB/DJI_Pro_Rmu.h

FORMS    += mainwindow.ui
