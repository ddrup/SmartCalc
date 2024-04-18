#include "creditcalculator.h"
#include "ui_creditcalculator.h"
#include "tablediffpayment.h"

#include <QRegularExpression>
#include <QKeyEvent>

extern "C" {
    #include "s21_calc.h"
}

extern "C" int s21_check_correct_value(char *string);
extern "C" int s21_check_correct_value_date(char *string);

CreditCalculator::CreditCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditCalculator)
{
    ui->setupUi(this);

    paymentwindow = new TableDiffPayment();
    connect(this, &CreditCalculator::signal, paymentwindow, &TableDiffPayment::slot);

    // Добавляем обработчик событий клавиатуры
    ui->sum->installEventFilter(this);
    ui->lineEdit_stavka->installEventFilter(this);
    ui->lineEdit_date->installEventFilter(this);
}

CreditCalculator::~CreditCalculator()
{
    delete ui;
}

bool CreditCalculator::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event); // Эта строка выполняет приведение типа события к QKeyEvent, чтобы получить доступ к информации о нажатой клавише.
        static QRegularExpression validInput("[0-9.]");
        // Проверяем, является ли нажатая клавиша цифрой, точкой или клавишей "Backspace"
        if (!keyEvent->text().isEmpty() && !keyEvent->text().contains(validInput) && keyEvent->key() != Qt::Key_Backspace)
        {
            return true; // Игнорируем событие, если нажата недопустимая клавиша
        }
    }

    return QObject::eventFilter(obj, event);
}

void CreditCalculator::clearButtonClicked()
{
    QString currentText = ui->sum->text();
    currentText.chop(1); // Удаляем последний символ
    ui->sum->setText(currentText);
}

void CreditCalculator::on_pushButton_2_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow(); // И вызываем сигнал на открытие главного окна
}

int CreditCalculator::processing_value(){
    ui->label_pole->setText("");
    ui->label_pole_2->setText("");
    ui->label_pole_3->setText("");
    int err_code_one = OK;
    int err_code_two = OK;
    int err_code_three = OK;
    QString text = ui->sum->text();
    QByteArray byte_array = text.toUtf8();
    char *char_array = byte_array.data();

    err_code_one = s21_check_correct_value(char_array);
    if(err_code_one == INCORRECT_VALUE || err_code_one == VALUE_TOO_MATCH){
        ui->sum->setText("0");
        ui->label_pole->setText("Некорректный ввод!");
    }else if(err_code_one == ERROR){
        ui->sum->setText("0");
        ui->label_pole->setText("Обязательное поле!");
    }

    QString text_1 = ui->lineEdit_date->text();
    QByteArray byte_array_1 = text_1.toUtf8();
    char *char_array_1 = byte_array_1.data();

    err_code_two = s21_check_correct_value_date(char_array_1);
    if(err_code_two == INCORRECT_VALUE){
        ui->lineEdit_date->setText("0");
        ui->label_pole_2->setText("Число должно быть целым!");
    }else if(err_code_two == ERROR){
        ui->lineEdit_date->setText("0");
        ui->label_pole_2->setText("Обязательное поле!");
    }else if(err_code_two == VALUE_TOO_MATCH){
        ui->lineEdit_date->setText("0");
        ui->label_pole_2->setText("Число не может быть больше 50!");
    }


    QString text_2 = ui->lineEdit_stavka->text();
    QByteArray byte_array_2 = text_2.toUtf8();
    char *char_array_2 = byte_array_2.data();
    long double value = atof(char_array_2);
    err_code_three = s21_check_correct_value(char_array_2);
    if(err_code_three == INCORRECT_VALUE){
        ui->lineEdit_stavka->setText("0");
        ui->label_pole_3->setText("Число должно быть целым!");
    }else if(err_code_three == ERROR){
        ui->lineEdit_stavka->setText("0");
        ui->label_pole_3->setText("Обязательное поле!");
    }else if(value > 999){
        ui->lineEdit_stavka->setText("0");
        ui->label_pole_3->setText("Число не может быть больше 999!");
    }
    return err_code_one + err_code_two + err_code_three;
}


void CreditCalculator::on_pushButton_clicked()
{
   if(processing_value() == OK){
       QString selectedText = ui->comboBox_time->currentText();
       int date = 0;
       QString text = ui->lineEdit_date->text();
       if(selectedText == "месяца"){
           date = text.toInt();
       }else{
           date = text.toInt()*12;
       }
       QString sum = ui->sum->text();
       long double summ = sum.toDouble();
       long double common_sum = summ;
       QString rate_str = ui->lineEdit_stavka->text();
       long double rate = rate_str.toDouble();

       if (ui->radioButton_diff->isChecked()) {
           paymentwindow->show();  // Показываем второе окно
           emit signal(date,summ,rate);
           long double base_payment = (long double)(summ / date);
           long double over_payment = 0;
           for(int i = 0;i < date;i++){
               long double payment_rate = summ * (rate / 12.0) * 0.01;
               over_payment += base_payment + payment_rate;
               summ -= base_payment;
           }
           QString common_payment_string =  QString::number(static_cast<double>(over_payment),'f',2);
           ui->show_common_payment->setText(common_payment_string+"₽");

           QString overpayment_string =  QString::number(static_cast<double>(over_payment - common_sum),'f',2);
           ui->show_overpayment->setText(overpayment_string+"₽");
       }else{
          long double coefficient = ((rate/1200.0)*pow((1+rate/1200.0),date))/(pow((1+rate/1200),date) - 1);

          long double sum_month = summ * coefficient;
          QString month_payment = QString::number(static_cast<double>(sum_month),'f',2);
          ui->show_payment_month->setText(month_payment+"₽");

          long double common_payment = date * sum_month;
          QString common_payment_string =  QString::number(static_cast<double>(common_payment),'f',2);
          ui->show_common_payment->setText(common_payment_string+"₽");

          long double overpayment = common_payment - summ;
          QString overpayment_string =  QString::number(static_cast<double>(overpayment),'f',2);
          ui->show_overpayment->setText(overpayment_string+"₽");
       }
   }
}

