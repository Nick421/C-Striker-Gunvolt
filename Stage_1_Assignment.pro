#-------------------------------------------------
#
# Project created by QtCreator 2019-03-15T11:39:07
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stage_1_Assignment
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
    background.cpp \
    dialog.cpp \
    main.cpp \
    configreader.cpp \
    stickmanfactory.cpp \
    stickman.cpp \
    tinystickman.cpp \
    normalstickman.cpp \
    largestickman.cpp \
    giantstickman.cpp \
    coordinate.cpp

HEADERS += \
    background.h \
    dialog.h \
    configreader.h \
    stickmanfactory.h \
    stickman.h \
    tinystickman.h \
    normalstickman.h \
    largestickman.h \
    giantstickman.h \
    coordinate.h

FORMS += \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README

RESOURCES += \
    gameresources.qrc
