#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QRegularExpression>
#include <QKeyEvent>

extern "C" {
    #include "s21_stack.h"
    #include "s21_calc.h"
}

int sign = 0;

extern "C" void s21_parser_string(stack **stack_string, char *str);
extern "C" void s21_reverse_polish_notation(stack **new_stack);
extern "C" double s21_calculate_expression(stack **new_stack,double value_x);
extern "C" void s21_reverse_stack(stack **stack_string);
extern "C" char* s21_check_correct_string(char *string,int *err_code);
extern "C" int s21_check_correct_value(char *string);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sWindow = new anotherwindow();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(sWindow, &anotherwindow::firstWindow, this, &MainWindow::show);
    //передача значения во второе окно
    connect(this, &MainWindow::signal, sWindow, &anotherwindow::slot);

    // Инициализируем третье окно
    thirdWindow = new CreditCalculator();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(thirdWindow, &CreditCalculator::secondWindow, this, &MainWindow::show);


    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_number()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_number()));

    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operation()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(function()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(function()));

    ui->lineEdit_value_x->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event); // Эта строка выполняет приведение типа события к QKeyEvent, чтобы получить доступ к информации о нажатой клавише.
        static QRegularExpression validInput("[0-9.]");
        // Проверяем, является ли нажатая клавиша цифрой, точкой или клавишей "Backspace"
        if (!keyEvent->text().isEmpty() && !keyEvent->text().contains(validInput) && keyEvent->key() != Qt::Key_Backspace)
        {
            return true; // Игнорируем событие, если нажата недопустимая клавиша
        }else{
            if(ui->result_show->text().contains('.')){
                return true;
            }
        }
    }

    return QObject::eventFilter(obj, event);
}

void MainWindow::clearButtonClicked()
{
    QString currentText = ui->lineEdit_value_x->text();
    currentText.chop(1); // Удаляем последний символ
    ui->lineEdit_value_x->setText(currentText);
}

void MainWindow::digit_number(){
    QPushButton *button = (QPushButton *)sender();
    if(ui->result_show->text() == "0" || ui->result_show->text() == "ERROR!"){
        ui->result_show->setText("");
    }
    QString new_label = ui->result_show->text();
    if(!new_label.endsWith(")") && !new_label.endsWith("X")){
        new_label += button->text();
    }
    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(sign == 0){
        ui->result_show->setText(ui->result_show->text() + ".");
        sign = 1;
    }
}


void MainWindow::on_pushButton_ac_clicked()
{
    ui->result_show->setText("0");
    sign = 0;
}

void MainWindow::operation()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label = ui->result_show->text();
    sign = 0;
    if((new_label == "0" || ui->result_show->text() == "ERROR!") && (button->text() == '+' || button->text() == '-')){
        new_label = button->text();
    }else if (new_label != "0"){
        if(new_label.endsWith("(") && (button->text() == '+' || button->text() == '-')){
            new_label += button->text();
        }else if(!(new_label.endsWith("/") || new_label.endsWith("*") || new_label.endsWith("+") || new_label.endsWith("-") || new_label.endsWith("^") || new_label.endsWith("mod") || new_label.endsWith(".") || new_label.endsWith("("))){
            if(button->text() == "÷"){
                new_label += '/';
            }else if(button->text() == "×"){
                new_label += '*';
            }else{
                new_label += button->text();
            }
        }
    }


    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_bracket_first_clicked()
{
    sign = 0;
    if(ui->result_show->text() == "0"|| ui->result_show->text() == "ERROR!"){
        ui->result_show->setText("(");
    }else{
        QString text = ui->result_show->text();
        QChar lastChar = text.at(text.length() - 1);
        if(lastChar == '*' || lastChar == '/' || lastChar == '-' || lastChar == '+' || lastChar == '^' || lastChar == 'd'){
            if(ui->result_show->text() == "0"){
                ui->result_show->setText("(");
            }else{
                ui->result_show->setText(ui->result_show->text() + "(");
            }
        }
    }
}


void MainWindow::on_pushButton_bracket_last_clicked()
{
    sign = 0;
    QString text = ui->result_show->text();
    int charCount_first = text.count('(');
    int charCount_last = text.count(')');
    QChar lastChar = text.at(text.length() - 1);
    if(charCount_first > charCount_last && lastChar != '('&& lastChar != '+'&& lastChar != '-'&& lastChar != '*'&& lastChar != '/'&& lastChar != 'd'&& lastChar != '^'){
        ui->result_show->setText(ui->result_show->text() + ")");
    }
}

void MainWindow::function(){
    sign = 0;
    QPushButton *button = (QPushButton *)sender();
    QString new_label = ui->result_show->text();
    if(ui->result_show->text() == "0" || ui->result_show->text() == "ERROR!"){
        new_label = button->text() + "(";
    }else{
        if(ui->result_show->text().endsWith("/") || ui->result_show->text().endsWith("*") || ui->result_show->text().endsWith("+") || ui->result_show->text().endsWith("-") || ui->result_show->text().endsWith("^") || ui->result_show->text().endsWith("mod") || ui->result_show->text().endsWith("(")){
            new_label += button->text() + "(";
        }
    }
    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_delete_symbol_clicked()
{
    QString text = ui->result_show->text();
    if(text.length() == 0 || text == "0" ||ui->result_show->text() == "ERROR!"){
        text = "0";
    }else{
        QChar lastChar = text.at(text.length() - 1);
        if(text.endsWith("sin(") || text.endsWith("cos(") || text.endsWith("tan(") || text.endsWith("asin(") || text.endsWith("acos(") || text.endsWith("atan(") || text.endsWith("sqrt(") || text.endsWith("ln(") || text.endsWith("log(") || text.endsWith("mod")){
            do{
                text.remove(text.length() - 1, 1);
                lastChar = text.at(text.length() - 1);
            }while(lastChar >= 'a' && lastChar <= 'z' && text.length() != 1);
            text.remove(text.length()-1, 1);
        }else {
            text.remove(text.length() - 1, 1);
        }
        if(text.length() == 0){
            text = "0";
        }
    }
    ui->result_show->setText(text);
}


void MainWindow::on_pushButton_pi_clicked()
{
    if(ui->result_show->text() == "0"|| ui->result_show->text() == "ERROR!"){
        ui->result_show->setText(" ");
    }
    QString new_label = ui->result_show->text();
    QChar lastChar = new_label.at(new_label.length() - 1);
    if(lastChar == '*' || lastChar == '/' || lastChar == '-' || lastChar == '+' || lastChar == '^' || lastChar == 'd' || lastChar == '('){
        new_label += "3.1415926535";
    }else if(lastChar == ' '){
        new_label = "3.1415926535";
    }
    sign = 1;
    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_equals_clicked()
{
    QString new_label = ui->result_show->text();

    stack *tmp_stack = NULL;
    QByteArray byte_array = new_label.toUtf8();
    char *char_array = byte_array.data();
    int error = 0;
    char_array = s21_check_correct_string(char_array,&error);
    if(error != ERROR){
        s21_parser_string(&tmp_stack,char_array);
        s21_reverse_stack(&tmp_stack);
        s21_reverse_polish_notation(&tmp_stack);
        QString string_line_edit = ui->lineEdit_value_x->text();
        if(string_line_edit != '0' || (string_line_edit == '0' && !new_label.contains('X'))){
            QByteArray byte_array_line_edit = string_line_edit.toUtf8();
            char *string = byte_array_line_edit.data();
            error = s21_check_correct_value(string);
            if(error != OK){
                ui->lineEdit_value_x->setText("ERROR!");
            }else{
                QString value_x_string = ui->lineEdit_value_x->text();
                long double value_x = value_x_string.toDouble();

                double value = s21_calculate_expression(&tmp_stack,value_x);
                QString str_value = QString::number(static_cast<double>(value),'f',2);
                ui->result_show->setText(str_value);
            }
        }else{
            sWindow->show();// Показываем второе окно
            emit signal(tmp_stack);
            this->close();    // Закрываем основное окно
        }
    }else{
        new_label = "ERROR!";
        ui->result_show->setText(new_label);
    }
}


void MainWindow::on_pushButton_x_clicked()
{
    sign = 0;
    if(ui->result_show->text() == "0" || ui->result_show->text() == "ERROR!"){
        ui->result_show->setText(" ");
    }
    QString new_label = ui->result_show->text();
    QChar lastChar = new_label.at(new_label.length() - 1);
    if(lastChar == '*' || lastChar == '/' || lastChar == '-' || lastChar == '+' || lastChar == '^' || lastChar == 'd' || lastChar == '('){
        new_label += 'X';
    }else if(lastChar == ' '){
        new_label = 'X';
    }
    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_credit_clicked()
{
    thirdWindow->show();// Показываем второе окно
    this->close();    // Закрываем основное окно
}

