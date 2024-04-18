#include "anotherwindow.h"
#include "ui_anotherwindow.h"

#include <QtCore>

extern "C" {
    #include "s21_stack.h"
    #include "s21_calc.h"
}

extern "C" double s21_calculate_expression(stack **new_stack,double value_x);
extern "C" void s21_reverse_stack(stack **stack_string);

anotherwindow::anotherwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anotherwindow)
{
    ui->setupUi(this);

}
stack* tempy_stack;

anotherwindow::~anotherwindow()
{
    delete ui;
}


void anotherwindow::on_pushButton_back_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void anotherwindow::slot(stack *tmp_stack)
{
    tempy_stack = tmp_stack;
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(-10,10);
    ui->widget->yAxis->setRange(-10,10);
    ui->spinBox_min_y->setValue(-10);
    ui->spinBox_max_y->setValue(10);
    ui->spinBox_min_x->setValue(-10);
    ui->spinBox_max_x->setValue(10);
}

void anotherwindow::on_pushButton_graphic_clicked()
{
    ui->widget->clearGraphs(); // Очистка всех графиков перед добавлением нового
    x.clear();
    y.clear();
    double min_y = ui->spinBox_min_y->value();
    double min_x = ui->spinBox_min_x->value();

    double max_y = ui->spinBox_max_y->value();
    double max_x = ui->spinBox_max_x->value();
    if(min_y > max_y){
        ui->spinBox_min_y->setValue(max_y);
        ui->spinBox_max_y->setValue(min_y);
        qSwap(min_y,max_y);
    }
    if(min_x > max_x){
        ui->spinBox_min_x->setValue(max_x);
        ui->spinBox_max_x->setValue(min_x);
        qSwap(min_x,max_x);
    }
    ui->widget->xAxis->setRange(min_x, max_x);
    ui->widget->yAxis->setRange(min_y, max_y);
    long long scale = qMax(max_x-min_x, max_y - min_y);
    double h = 0;
    if(scale < 2000){
        h = 0.01;
    }else if(scale < 200000){
        h = 1;
    }else{
        h = 10;
    }
    double val = 0;
    int priority = 0;
    type_t type = NUMBER;
    double X = min_x;
    while(X <= max_x){
        stack *add_stack = NULL;
        stack *add_stack_1 = NULL;
        while (tempy_stack != NULL) {
          peek_back(&tempy_stack, &val, &priority, &type);
          push_back(&add_stack, val, priority, type);
          push_back(&add_stack_1, val, priority, type);
          pop_back(&tempy_stack);
        }
        s21_reverse_stack(&add_stack);
        while (add_stack_1 != NULL) {
          peek_back(&add_stack_1, &val, &priority, &type);
          push_back(&tempy_stack, val, priority, type);
          pop_back(&add_stack_1);
        }
        double Y = s21_calculate_expression(&add_stack,X);
        x.push_back(X);
        y.push_back(Y);
        X += h;
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(0)->setPen(QPen(Qt::blue, 2));
    ui->widget->replot();
}
// 1000 - 0.01
//
