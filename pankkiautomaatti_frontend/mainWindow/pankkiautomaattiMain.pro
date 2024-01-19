QT       += core gui
QT += network
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditwindow.cpp \
    debitorcredit.cpp \
    debitwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    creditwindow.h \
    debitorcredit.h \
    debitwindow.h \
    mainwindow.h

FORMS += \
    creditwindow.ui \
    debitorcredit.ui \
    debitwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




macx|win32: LIBS += -L$$PWD/../build-DLL_History-Qt_6_2_4_for_macOS-Debug/ -lDLL_History.1.0.0

INCLUDEPATH += $$PWD/../DLL_History
DEPENDPATH += $$PWD/../DLL_History

macx|win32: LIBS += -L$$PWD/../build-DLLui-Qt_6_3_1_for_macOS-Debug/ -lDLLui.1.0.0

INCLUDEPATH += $$PWD/../cardandpinDLL1
DEPENDPATH += $$PWD/../cardandpinDLL1

macx|win32: LIBS += -L$$PWD/../build-DLLwithdraw-Qt_6_2_4_for_macOS-Debug/ -lDLLwithdraw.1.0.0

INCLUDEPATH += $$PWD/../DLLwithdraw
DEPENDPATH += $$PWD/../DLLwithdraw
