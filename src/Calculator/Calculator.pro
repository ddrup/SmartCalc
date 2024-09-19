QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cc \
    main.cc \
    model/model.cc \
    model/token.cc \
    qcustomplot.cpp \
    view/credit/creditcalculator.cc \
    view/credit/differentiatedpayment.cc \
    view/graph.cc \
    view/graphicview.cc

HEADERS += \
    controller/controller.h \
    model/model.h \
    model/token.h \
    qcustomplot.h \
    view/credit/creditcalculator.h \
    view/credit/differentiatedpayment.h \
    view/graph.h \
    view/graphicview.h

FORMS += \
    view/credit/creditcalculator.ui \
    view/credit/differentiatedpayment.ui \
    view/graph.ui \
    view/graphicview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
