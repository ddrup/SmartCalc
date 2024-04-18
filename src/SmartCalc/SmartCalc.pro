QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anotherwindow.cpp \
    creditcalculator.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    s21_stack.c \
    s21_calc.c \
    tablediffpayment.cpp

HEADERS += \
    anotherwindow.h \
    creditcalculator.h \
    mainwindow.h \
    qcustomplot.h \
    s21_stack.h \
    s21_calc.h \
    tablediffpayment.h

FORMS += \
    anotherwindow.ui \
    creditcalculator.ui \
    mainwindow.ui \
    tablediffpayment.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
