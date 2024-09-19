#ifndef CREDITCALCULATOR_H
#define CREDITCALCULATOR_H

#include <QKeyEvent>
#include <QWidget>

#include "../../controller/controller.h"
#include "differentiatedpayment.h"

namespace Ui {
class CreditCalculator;
}

namespace s21 {

class CreditCalculator : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalculator(Controller *c, QWidget *parent = nullptr);
  ~CreditCalculator();

 signals:
  void FirstWindow();
  void SendCredit(const std::vector<long double> &payments, int date);

 private slots:
  void BackButtonProcessing();
  void ResultButtonProcessing();

 private:
  Ui::CreditCalculator *ui;
  Controller *controller;
  DifferentiatedPayment *payment_window;

  bool eventFilter(QObject *obj, QEvent *event);
  void clearButtonClicked();
  bool CorrectInputDouble(const QString &input);
  bool CorrectInputInteger(const QString &input);
};

}  // namespace s21

#endif  // CREDITCALCULATOR_H
