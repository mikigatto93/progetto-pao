QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baseitem.cpp \
    controller.cpp \
    dialogmodificaintestazione.cpp \
    dialogmostradettagliserramento.cpp \
    dialogprodotti.cpp \
    finestra.cpp \
    legno.cpp \
    main.cpp \
    mainwindow.cpp \
    materiale.cpp \
    model.cpp \
    porta.cpp \
    preventivo.cpp \
    preventivojsonreader.cpp \
    scuro.cpp \
    serramento.cpp \
    vetro.cpp \
    widgetfinestre.cpp \
    widgetitemgenerico.cpp \
    widgetporte.cpp \
    widgetscuri.cpp

HEADERS += \
    baseitem.h \
    controller.h \
    deepprt.h \
    dialogmodificaintestazione.h \
    dialogmostradettagliserramento.h \
    dialogprodotti.h \
    finestra.h \
    legno.h \
    mainwindow.h \
    materiale.h \
    model.h \
    porta.h \
    preventivo.h \
    preventivojsonreader.h \
    scuro.h \
    serramento.h \
    slist.h \
    vetro.h \
    widgetfinestre.h \
    widgetitemgenerico.h \
    widgetporte.h \
    widgetscuri.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res.qrc
