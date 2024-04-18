#ifndef CREDITCALCULATOR_H
#define CREDITCALCULATOR_H

#include <QWidget>

#include "tablediffpayment.h"

namespace Ui {
class CreditCalculator;
}

class CreditCalculator : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalculator(QWidget *parent = nullptr);
  ~CreditCalculator();

 signals:
  void signal(int date, long double sum, long double rate);
  void secondWindow();
  void firstWindow();  // Сигнал для первого окна на открытие

 private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

 private:
  int processing_value();
  bool eventFilter(QObject *obj, QEvent *event);
  void clearButtonClicked();
  TableDiffPayment *paymentwindow;

 private:
  Ui::CreditCalculator *ui;
};

#endif  // CREDITCALCULATOR_H
