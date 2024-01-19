#QT -= gui
QT += core gui
QT += serialport
QT +=network
TEMPLATE = lib
DEFINES += DLLUI_LIBRARY
greaterThan (QT_MAJOR_VERSION, 4) : QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardreader.cpp \
    databaseconnection.cpp \
    dllui.cpp \
    engine.cpp \
    pin.cpp

HEADERS += \
    DLLui_global.h \
    cardreader.h \
    databaseconnection.h \
    dllui.h \
    engine.h \
    pin.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    cardreader.ui \
    dllui.ui \
    pin.ui


