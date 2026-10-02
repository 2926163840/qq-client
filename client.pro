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
    chatbubble.cpp \
    chatfeature.cpp \
    chatitem.cpp \
    chatwidget.cpp \
    dbmanager.cpp \
    emptytipwidget.cpp \
    eventmanager.cpp \
    friendnoticeitem.cpp \
    groupannouncement.cpp \
    groupfeature.cpp \
    handlercmd.cpp \
    hovertip.cpp \
    itemwidget.cpp \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    networkmanager.cpp \
    privatefeature.cpp \
    registeruser.cpp \
    resizeitemlistwidget.cpp \
    userwidget.cpp

HEADERS += \
    UserData.h \
    addfriend.h \
    addfriendwidget.h \
    businessmanager.h \
    chatbubble.h \
    chatfeature.h \
    chatitem.h \
    chatwidget.h \
    dbmanager.h \
    emptytipwidget.h \
    eventmanager.h \
    friendnoticeitem.h \
    groupannouncement.h \
    groupfeature.h \
    handlercmd.h \
    hovertip.h \
    itemwidget.h \
    log.h \
    mainwindow.h \
    networkmanager.h \
    privatefeature.h \
    registeruser.h \
    resizeitemlistwidget.h \
    userwidget.h

FORMS += \
    addfriend.ui \
    addfriendwidget.ui \
    chatitem.ui \
    chatwidget.ui \
    emptytipwidget.ui \
    friendnoticeitem.ui \
    groupannouncement.ui \
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
