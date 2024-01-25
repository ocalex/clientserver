QT       += core gui
QT += network
QT += core5compat
QT += sql
LIBS     += -lws2_32
LIBS     += -liphlpapi

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apps.cpp \
    autorisation.cpp \
    database.cpp \
    insert_user.cpp \
    list_users.cpp \
    main.cpp \
    mainwindow.cpp \
    server.cpp

HEADERS += \
    apps.h \
    autorisation.h \
    database.h \
    insert_user.h \
    list_users.h \
    mainwindow.h \
    server.h

FORMS += \
    apps.ui \
    autorisation.ui \
    insert_user.ui \
    list_users.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
