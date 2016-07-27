#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T11:30:04
#
#-------------------------------------------------

QT       += core serialport
DEFINES += API_DEBUG_DATA

QT       -= gui

TARGET = HelloWorld
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += lib/inc \
               lib/DJIscript/inc

SOURCES += main.cpp \
    lib/src/DJI_API.cpp \
    lib/src/DJI_App.cpp \
    lib/src/DJI_Camera.cpp \
    lib/src/DJI_Codec.cpp \
    lib/src/DJI_Flight.cpp \
    lib/src/DJI_Follow.cpp \
    lib/src/DJI_HardDriver.cpp \
    lib/src/DJI_HotPoint.cpp \
    lib/src/DJI_Link.cpp \
    lib/src/DJI_Memory.cpp \
    lib/src/DJI_Mission.cpp \
    lib/src/DJI_VirtualRC.cpp \
    lib/src/DJI_WayPoint.cpp \
    lib/DJIscript/src/cmdCamera.cpp \
    lib/DJIscript/src/cmdCoreAPI.cpp \
    lib/DJIscript/src/cmdFlight.cpp \
    lib/DJIscript/src/cmdFollow.cpp \
    lib/DJIscript/src/cmdHotPoint.cpp \
    lib/DJIscript/src/cmdIO.cpp \
    lib/DJIscript/src/cmdSettings.cpp \
    lib/DJIscript/src/cmdVirtualRC.cpp \
    lib/DJIscript/src/cmdWayPoint.cpp \
    lib/DJIscript/src/DJI_Interpreter.cpp \
    lib/DJIscript/src/DJI_Script.cpp \
    QonboardSDK.cpp

HEADERS += \
    lib/inc/DJI_API.h \
    lib/inc/DJI_App.h \
    lib/inc/DJI_Camera.h \
    lib/inc/DJI_Codec.h \
    lib/inc/DJI_Config.h \
    lib/inc/DJI_Flight.h \
    lib/inc/DJI_Follow.h \
    lib/inc/DJI_HardDriver.h \
    lib/inc/DJI_HotPoint.h \
    lib/inc/DJI_Link.h \
    lib/inc/DJI_Memory.h \
    lib/inc/DJI_Mission.h \
    lib/inc/DJI_Type.h \
    lib/inc/DJI_Version.h \
    lib/inc/DJI_VirtualRC.h \
    lib/inc/DJI_WayPoint.h \
    lib/inc/DJICommonType.h \
    lib/DJIscript/inc/cmdCamera.h \
    lib/DJIscript/inc/cmdCoreAPI.h \
    lib/DJIscript/inc/cmdFlight.h \
    lib/DJIscript/inc/cmdFollow.h \
    lib/DJIscript/inc/cmdHotPoint.h \
    lib/DJIscript/inc/cmdIO.h \
    lib/DJIscript/inc/cmdSettings.h \
    lib/DJIscript/inc/cmdVirtualRC.h \
    lib/DJIscript/inc/cmdWayPoint.h \
    lib/DJIscript/inc/DJI_Interpreter.h \
    lib/DJIscript/inc/DJI_Script.h \
    QonboardSDK.h
