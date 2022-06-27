QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_ow.cpp \
    add_product.cpp \
    add_rc_in.cpp \
    add_rc_in_2.cpp \
    add_rc_out.cpp \
    add_rc_out_2.cpp \
    add_stuff.cpp \
    add_wh.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    add_ow.h \
    add_product.h \
    add_rc_in.h \
    add_rc_in_2.h \
    add_rc_out.h \
    add_rc_out_2.h \
    add_stuff.h \
    add_wh.h \
    login.h \
    mainwindow.h

FORMS += \
    add_ow.ui \
    add_product.ui \
    add_rc_in.ui \
    add_rc_in_2.ui \
    add_rc_out.ui \
    add_rc_out_2.ui \
    add_stuff.ui \
    add_wh.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
