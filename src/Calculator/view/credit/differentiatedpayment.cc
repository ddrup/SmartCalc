#include "differentiatedpayment.h"

#include "ui_differentiatedpayment.h"

namespace s21 {

DifferentiatedPayment::DifferentiatedPayment(QWidget *parent)
    : QWidget(parent), ui(new Ui::DifferentiatedPayment) {
  ui->setupUi(this);
}

DifferentiatedPayment::~DifferentiatedPayment() { delete ui; }

void DifferentiatedPayment::ReceiveCredit(
    const std::vector<long double> &payments, int date) {
  ui->tableWidget_diff->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);  // расширяет таблицу до размера окна
  ui->tableWidget_diff->setRowCount(date);
  ui->tableWidget_diff->setColumnCount(1);
  ui->tableWidget_diff->setHorizontalHeaderLabels(QStringList()
                                                  << "Сумма платежа");

  for (int i = 0; i < ui->tableWidget_diff->rowCount(); i++) {
    for (int j = 0; j < ui->tableWidget_diff->columnCount(); j++) {
      QTableWidgetItem *Value = new QTableWidgetItem(
          QString::number(static_cast<double>(payments[i]), 'f', 2) + "₽");
      ui->tableWidget_diff->setItem(i, j, Value);
    }
  }
}

}  // namespace s21
