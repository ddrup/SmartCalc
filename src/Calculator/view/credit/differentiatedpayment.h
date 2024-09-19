#ifndef DIFFERENTIATEDPAYMENT_H
#define DIFFERENTIATEDPAYMENT_H

#include <QHBoxLayout>
#include <QTableWidget>
#include <QWidget>
#include <vector>

namespace Ui {
class DifferentiatedPayment;
}

namespace s21 {

class DifferentiatedPayment : public QWidget {
  Q_OBJECT

 public:
  explicit DifferentiatedPayment(QWidget *parent = nullptr);
  ~DifferentiatedPayment();

 signals:
  void CreditWindow();

 public slots:
  void ReceiveCredit(const std::vector<long double> &payments, int date);

 private:
  Ui::DifferentiatedPayment *ui;
};

}  // namespace s21

#endif  // DIFFERENTIATEDPAYMENT_H
