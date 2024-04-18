#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>

extern "C" {
#include "s21_calc.h"
#include "s21_stack.h"
}

namespace Ui {
class anotherwindow;
}

class anotherwindow : public QWidget {
  Q_OBJECT

 public:
  explicit anotherwindow(QWidget *parent = nullptr);
  ~anotherwindow();

 signals:
  void firstWindow();  // Сигнал для первого окна на открытие

 public slots:
  void slot(stack *tmp_stack);

 private slots:
  // Слот-обработчик нажатия кнопки
  void on_pushButton_back_clicked();
  void on_pushButton_graphic_clicked();

 private:
  Ui::anotherwindow *ui;
  QVector<double> x, y;
};

#endif  // ANOTHERWINDOW_H
