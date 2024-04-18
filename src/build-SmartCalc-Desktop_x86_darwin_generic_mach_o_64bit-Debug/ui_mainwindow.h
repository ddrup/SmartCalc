/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_0;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_equals;
    QPushButton *pushButton_div;
    QPushButton *pushButton_ac;
    QPushButton *pushButton_degree;
    QPushButton *pushButton_replace_sign;
    QPushButton *pushButton_bracket_first;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_log;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_bracket_last;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_x;
    QPushButton *pushButton_delete_symbol;
    QPushButton *pushButton_pi;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(420, 389);
        MainWindow->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result_show = new QLabel(centralwidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setGeometry(QRect(0, 0, 411, 91));
        QFont font;
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        result_show->setFont(font);
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"\n"
"}\n"
"\n"
"background-color : white;"));
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(180, 150, 60, 60));
        QFont font1;
        font1.setPointSize(20);
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(240, 150, 60, 60));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(300, 150, 60, 60));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(180, 210, 60, 60));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 210, 60, 60));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 210, 60, 60));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(180, 270, 60, 60));
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 270, 60, 60));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 270, 60, 60));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#5d5e5f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(300, 330, 60, 60));
        pushButton_dot->setFont(font1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	background:#5d5e5f;\n"
"	border-left: 1px solid black;\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(180, 330, 120, 60));
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	background:#5d5e5f;\n"
"	border-left: 1px solid black;\n"
"	border-top: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #9e9e9f, stop: 1 #9e9e9f);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(360, 270, 60, 60));
        pushButton_plus->setFont(font1);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-right: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#ffa00a;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffcc99, stop: 1 #ffcc99);\n"
"}"));
        pushButton_multiply = new QPushButton(centralwidget);
        pushButton_multiply->setObjectName(QString::fromUtf8("pushButton_multiply"));
        pushButton_multiply->setGeometry(QRect(360, 150, 60, 60));
        pushButton_multiply->setFont(font1);
        pushButton_multiply->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-right: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#ffa00a;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffcc99, stop: 1 #ffcc99);\n"
"}"));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(360, 210, 60, 60));
        pushButton_minus->setFont(font1);
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-right: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#ffa00a;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffcc99, stop: 1 #ffcc99);\n"
"}"));
        pushButton_equals = new QPushButton(centralwidget);
        pushButton_equals->setObjectName(QString::fromUtf8("pushButton_equals"));
        pushButton_equals->setGeometry(QRect(360, 330, 60, 60));
        pushButton_equals->setFont(font1);
        pushButton_equals->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border: 1px solid black;\n"
"	background:#ffa00a;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffcc99, stop: 1 #ffcc99);\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(360, 90, 60, 60));
        pushButton_div->setFont(font1);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-right: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#ffa00a;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffcc99, stop: 1 #ffcc99);\n"
"}"));
        pushButton_ac = new QPushButton(centralwidget);
        pushButton_ac->setObjectName(QString::fromUtf8("pushButton_ac"));
        pushButton_ac->setGeometry(QRect(180, 90, 60, 60));
        pushButton_ac->setFont(font1);
        pushButton_ac->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#FFA500;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_degree = new QPushButton(centralwidget);
        pushButton_degree->setObjectName(QString::fromUtf8("pushButton_degree"));
        pushButton_degree->setGeometry(QRect(60, 90, 60, 60));
        pushButton_degree->setFont(font1);
        pushButton_degree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_replace_sign = new QPushButton(centralwidget);
        pushButton_replace_sign->setObjectName(QString::fromUtf8("pushButton_replace_sign"));
        pushButton_replace_sign->setGeometry(QRect(240, 90, 60, 60));
        pushButton_replace_sign->setFont(font1);
        pushButton_replace_sign->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_bracket_first = new QPushButton(centralwidget);
        pushButton_bracket_first->setObjectName(QString::fromUtf8("pushButton_bracket_first"));
        pushButton_bracket_first->setGeometry(QRect(60, 150, 60, 60));
        pushButton_bracket_first->setFont(font1);
        pushButton_bracket_first->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(120, 270, 60, 60));
        pushButton_atan->setFont(font1);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(60, 270, 60, 60));
        pushButton_acos->setFont(font1);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(120, 330, 60, 60));
        pushButton_log->setFont(font1);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(0, 210, 60, 60));
        pushButton_sin->setFont(font1);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(120, 210, 60, 60));
        pushButton_tan->setFont(font1);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(60, 330, 60, 60));
        pushButton_ln->setFont(font1);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_bracket_last = new QPushButton(centralwidget);
        pushButton_bracket_last->setObjectName(QString::fromUtf8("pushButton_bracket_last"));
        pushButton_bracket_last->setGeometry(QRect(120, 150, 60, 60));
        pushButton_bracket_last->setFont(font1);
        pushButton_bracket_last->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(60, 210, 60, 60));
        pushButton_cos->setFont(font1);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(0, 270, 60, 60));
        pushButton_asin->setFont(font1);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(0, 330, 60, 60));
        pushButton_sqrt->setFont(font1);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	border-bottom: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(0, 150, 60, 60));
        pushButton_mod->setFont(font1);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(120, 90, 60, 60));
        pushButton_x->setFont(font1);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_delete_symbol = new QPushButton(centralwidget);
        pushButton_delete_symbol->setObjectName(QString::fromUtf8("pushButton_delete_symbol"));
        pushButton_delete_symbol->setGeometry(QRect(300, 90, 60, 60));
        pushButton_delete_symbol->setFont(font1);
        pushButton_delete_symbol->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        pushButton_pi = new QPushButton(centralwidget);
        pushButton_pi->setObjectName(QString::fromUtf8("pushButton_pi"));
        pushButton_pi->setGeometry(QRect(0, 90, 60, 60));
        pushButton_pi->setFont(font1);
        pushButton_pi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#ffffff;\n"
"	border-top: 1px solid black;\n"
"	border-left: 1px solid black;\n"
"	background:#3e3f40;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #5d5e5f, stop: 1 #5d5e5f);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_multiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_ac->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_degree->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_replace_sign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_bracket_first->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_bracket_last->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_delete_symbol->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pushButton_pi->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
