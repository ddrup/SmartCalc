#include "creditcalculator.h"

#include "ui_creditcalculator.h"

namespace s21 {

CreditCalculator::CreditCalculator(Controller *c, QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditCalculator), controller(c) {
  ui->setupUi(this);

  payment_window = new DifferentiatedPayment();
  connect(payment_window, &DifferentiatedPayment::CreditWindow, this,
          &CreditCalculator::show);
  connect(this, &CreditCalculator::SendCredit, payment_window,
          &DifferentiatedPayment::ReceiveCredit);

  connect(ui->pushButton_back, SIGNAL(clicked()), this,
          SLOT(BackButtonProcessing()));
  connect(ui->pushButton_result, SIGNAL(clicked()), this,
          SLOT(ResultButtonProcessing()));

  ui->sum->installEventFilter(this);
  ui->lineEdit_rate->installEventFilter(this);
  ui->lineEdit_date->installEventFilter(this);
}

CreditCalculator::~CreditCalculator() { delete ui; }

void CreditCalculator::BackButtonProcessing() {
  this->close();
  emit FirstWindow();
}

bool CreditCalculator::eventFilter(QObject *obj, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(
        event);  // Эта строка выполняет приведение типа события к QKeyEvent,
                 // чтобы получить доступ к информации о нажатой клавише.
    static QRegularExpression validInput("[0-9.]");
    // Проверяем, является ли нажатая клавиша цифрой, точкой или клавишей
    // "Backspace"
    if (!keyEvent->text().isEmpty() && !keyEvent->text().contains(validInput) &&
        keyEvent->key() != Qt::Key_Backspace) {
      return true;  // Игнорируем событие, если нажата недопустимая клавиша
    }
  }

  return QObject::eventFilter(obj, event);
}

void CreditCalculator::clearButtonClicked() {
  QString currentText = ui->sum->text();
  currentText.chop(1);
  ui->sum->setText(currentText);
}

void CreditCalculator::ResultButtonProcessing() {
  std::string sum = ui->sum->text().toStdString();
  std::string rate = ui->lineEdit_rate->text().toStdString();
  std::string date = ui->lineEdit_date->text().toStdString();

  QString time = ui->comboBox_time->currentText();
  TypeOfDate type_of_date;

  if (time == "месяца") {
    type_of_date = kMonth;
  } else {
    type_of_date = kYear;
  }

  TypeOfPayment type_of_payment;

  if (ui->radioButton_diff->isChecked()) {
    type_of_payment = kDifferentiated;
  } else {
    type_of_payment = kAnnuity;
  }

  try {
    Credit result = controller->CalculateCredit(sum, rate, date, type_of_date,
                                                type_of_payment);
    if (type_of_payment == kAnnuity) {
      QString month_payment =
          QString::number(static_cast<double>(result.sum_month), 'f', 2);
      ui->show_payment_month->setText(month_payment + "₽");

      QString common_payment_string =
          QString::number(static_cast<double>(result.common_payment), 'f', 2);
      ui->show_common_payment->setText(common_payment_string + "₽");

      QString overpayment_string =
          QString::number(static_cast<double>(result.overpayment), 'f', 2);
      ui->show_overpayment->setText(overpayment_string + "₽");
    } else {  // Diff

      QString common_payment_string =
          QString::number(static_cast<double>(result.common_payment), 'f', 2);
      ui->show_common_payment->setText(common_payment_string + "₽");

      QString overpayment_string =
          QString::number(static_cast<double>(result.overpayment), 'f', 2);
      ui->show_overpayment->setText(overpayment_string + "₽");

      payment_window->show();
      emit SendCredit(result.payment, result.date);
    }
  } catch (const std::exception &e) {
    controller->Clean();
  }
}

}  // namespace s21
