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


SOURCES += main.cpp

OTHER_FILES += \
    rekoverd.conf

daemonconf.path = /etc/init/apps
daemonconf.files = rekoverd.conf
INSTALLS += daemonconf

target.path = /opt/rekover/bin
INSTALLS += target
