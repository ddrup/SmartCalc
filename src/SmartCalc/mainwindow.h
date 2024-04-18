#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <anotherwindow.h>
#include <creditcalculator.h>

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "s21_calc.h"
#include "s21_stack.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  anotherwindow *sWindow;
  CreditCalculator *thirdWindow;
  bool eventFilter(QObject *obj, QEvent *event);
  void clearButtonClicked();

 signals:
  void signal(stack *tmp_stack);

 private slots:
  void digit_number();
  void on_pushButton_dot_clicked();
  void on_pushButton_ac_clicked();
  void operation();
  void on_pushButton_bracket_first_clicked();
  void on_pushButton_bracket_last_clicked();
  void function();
  void on_pushButton_delete_symbol_clicked();
  void on_pushButton_pi_clicked();
  void on_pushButton_equals_clicked();
  void on_pushButton_x_clicked();

  void on_pushButton_credit_clicked();

 signals:
  void stackChanged(stack *tmp_stack);
};
#endif  // MAINWINDOW_H
