#QT -= gui
QT  += core gui
QT += network
CONFIG += c++11 //

TEMPLATE = lib
DEFINES += DLLWITHDRAW_LIBRARY
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dllwithdraw.cpp

HEADERS += \
    DLLwithdraw_global.h \
    dllwithdraw.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    dllwithdraw.ui
