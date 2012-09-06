#-------------------------------------------------
#
# Project created by QtCreator 2012-09-06T23:26:53
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = rekoverd
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    textmessagecommandsource.cpp \
    getgeolocationcommand.cpp \
    commandprocessor.cpp \
    abstractcommandsource.cpp \
    abstractcommand.cpp

OTHER_FILES += \
    rekoverd.conf

daemonconf.path = /etc/init/apps
daemonconf.files = rekoverd.conf
INSTALLS += daemonconf

target.path = /opt/rekover/bin
INSTALLS += target

CONFIG += mobility
MOBILITY += messaging

HEADERS += \
    textmessagecommandsource.h \
    commandprocessor.h \
    abstractcommandsource.h \
    abstractcommand.h \
    getgeolocationcommand.h
