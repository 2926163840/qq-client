QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfriend.cpp \
    addfriendwidget.cpp \
    businessmanager.cpp \
    dbmanager.cpp \
    emptytipwidget.cpp \
    friendnoticeitem.cpp \
    handlercmd.cpp \
    hovertip.cpp \
    itemwidget.cpp \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    networkmanager.cpp \
    registeruser.cpp \
    userwidget.cpp

HEADERS += \
    UserData.h \
    addfriend.h \
    addfriendwidget.h \
    businessmanager.h \
    dbmanager.h \
    emptytipwidget.h \
    friendnoticeitem.h \
    handlercmd.h \
    hovertip.h \
    itemwidget.h \
    log.h \
    mainwindow.h \
    networkmanager.h \
    registeruser.h \
    userwidget.h

FORMS += \
    addfriend.ui \
    addfriendwidget.ui \
    emptytipwidget.ui \
    friendnoticeitem.ui \
    itemwidget.ui \
    mainwindow.ui \
    registeruser.ui \
    userwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
