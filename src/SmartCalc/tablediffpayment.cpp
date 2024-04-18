#include "tablediffpayment.h"
#include "ui_tablediffpayment.h"

TableDiffPayment::TableDiffPayment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableDiffPayment)
{
    ui->setupUi(this);
}

TableDiffPayment::~TableDiffPayment()
{
    delete ui;
}

void TableDiffPayment:: slot(int Date, long double Sum, long double Rate){
    ui->tableWidget_diff->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // расширяет таблицу до размера окна
    ui->tableWidget_diff->setRowCount(Date);
    ui->tableWidget_diff->setColumnCount(1);
    ui->tableWidget_diff->setHorizontalHeaderLabels(QStringList() << "Сумма платежа");

    long double BasePayment = (long double)(Sum / Date);
    for(int i = 0;i < ui->tableWidget_diff->rowCount();i++){
        for(int j = 0;j < ui->tableWidget_diff->columnCount(); j++){
            long double PaymentRate = Sum * (Rate / 12.0) * 0.01;
            QTableWidgetItem *Value = new QTableWidgetItem(QString::number(static_cast<double>(BasePayment + PaymentRate),'f',2) + "₽");
            ui->tableWidget_diff->setItem(i,j,Value);
            Sum -= BasePayment;
        }
    }

}
