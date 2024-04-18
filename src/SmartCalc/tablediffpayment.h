#ifndef TABLEDIFFPAYMENT_H
#define TABLEDIFFPAYMENT_H

#include <QHBoxLayout>
#include <QTableWidget>
#include <QWidget>

namespace Ui {
class TableDiffPayment;
}

class TableDiffPayment : public QWidget {
  Q_OBJECT

 public:
  explicit TableDiffPayment(QWidget *parent = nullptr);
  ~TableDiffPayment();

 signals:
  void CreditWindow();

 public slots:
  void slot(int Date, long double Sum, long double Rate);

 private:
  Ui::TableDiffPayment *ui;
};

#endif  // TABLEDIFFPAYMENT_H
