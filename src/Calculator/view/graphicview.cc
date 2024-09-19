#include "graphicview.h"

#include "ui_graphicview.h"

namespace s21 {

GraphicView::GraphicView(Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GraphicView), controller(c) {
  ui->setupUi(this);

  graph_window = new Graph(controller);
  connect(graph_window, &Graph::FirstWindow, this, &GraphicView::show);
  connect(this, &GraphicView::SendExpressionToGraph, graph_window,
          &Graph::ReceiveExpression);

  credit_window = new CreditCalculator(controller);
  connect(credit_window, &CreditCalculator::FirstWindow, this,
          &GraphicView::show);

  connect(ui->pushButton_credit, SIGNAL(clicked()), this,
          SLOT(CreditButtonProcessing()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this,
          SLOT(GraphButtonProcessing()));

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(DigitProcessing()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(DigitProcessing()));

  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(OperationProcessing()));
  connect(ui->pushButton_multiply, SIGNAL(clicked()), this,
          SLOT(OperationProcessing()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(OperationProcessing()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(OperationProcessing()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this,
          SLOT(OperationProcessing()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(OperationProcessing()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(FunctionProcessing()));

  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(OthersButtonProcessing()));
  connect(ui->pushButton_bracket_first, SIGNAL(clicked()), this,
          SLOT(OthersButtonProcessing()));
  connect(ui->pushButton_bracket_last, SIGNAL(clicked()), this,
          SLOT(OthersButtonProcessing()));
  connect(ui->pushButton_pi, SIGNAL(clicked()), this,
          SLOT(OthersButtonProcessing()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(OthersButtonProcessing()));
  connect(ui->pushButton_e, SIGNAL(clicked()), this,
          SLOT(OthersButtonProcessing()));

  connect(ui->pushButton_ac, SIGNAL(clicked()), this,
          SLOT(ACButtonProcessing()));
  connect(ui->pushButton_delete_symbol, SIGNAL(clicked()), this,
          SLOT(DeleteButtonProcessing()));
  connect(ui->pushButton_equals, SIGNAL(clicked()), this,
          SLOT(EqualButtonProcessing()));
}

GraphicView::~GraphicView() { delete ui; }

void GraphicView::DigitProcessing() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text();

  if (new_label == "0" || new_label == "ERROR!") {
    new_label = "";
  }

  new_label += button->text();
  ui->result_show->setText(new_label);
}

void GraphicView::OperationProcessing() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text();

  if (new_label == "0" || new_label == "ERROR!") {
    new_label = "";
  }

  if (button->text() == "÷") {
    new_label += '/';
  } else if (button->text() == "×") {
    new_label += '*';
  } else {
    new_label += button->text();
  }

  ui->result_show->setText(new_label);
}

void GraphicView::FunctionProcessing() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text();

  if (new_label == "0" || new_label == "ERROR!") {
    new_label = "";
  }

  new_label += button->text() + "(";
  ui->result_show->setText(new_label);
}

void GraphicView::OthersButtonProcessing() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text();
  if (new_label == "0" || new_label == "ERROR!") {
    new_label = "";
  }
  if (button->text() == "π") {
    new_label += "3.1415926535";
  } else if (button->text() == 'X') {
    new_label += 'x';
  } else {
    new_label += button->text();
  }
  ui->result_show->setText(new_label);
}

void GraphicView::ACButtonProcessing() { ui->result_show->setText("0"); }

void GraphicView::DeleteButtonProcessing() {
  QString new_label = ui->result_show->text();
  QChar last_char = new_label.at(new_label.length() - 1);

  if (new_label == "0" || new_label == "ERROR!") {
    new_label = "0";
  } else {
    if (new_label.endsWith("sin(") || new_label.endsWith("cos(") ||
        new_label.endsWith("tan(") || new_label.endsWith("asin(") ||
        new_label.endsWith("acos(") || new_label.endsWith("atan(") ||
        new_label.endsWith("sqrt(") || new_label.endsWith("ln(") ||
        new_label.endsWith("log(") || new_label.endsWith("mod")) {
      new_label.remove(new_label.length() - 1, 1);
      last_char = new_label.at(new_label.length() - 1);
      while (new_label.length() != 0 &&
             (last_char >= 'a' && last_char <= 'z') && last_char != 'd') {
        new_label.remove(new_label.length() - 1, 1);
        if (new_label.length() != 0) {
          last_char = new_label.at(new_label.length() - 1);
        }
      }
    } else {
      new_label.remove(new_label.length() - 1, 1);
    }
    if (new_label.length() == 0) {
      new_label = "0";
    }
  }
  ui->result_show->setText(new_label);
}

void GraphicView::EqualButtonProcessing() {
  QString answer = "";
  std::string expression = ui->result_show->text().toStdString();
  QString value_x = ui->lineEdit_value_x->text();
  if (CorrectInputX(value_x) && expression != "ERROR!") {
    std::string value = value_x.toStdString();
    try {
      double result = controller->CalculateExpression(expression, value);
      answer = QString::number(result);
    } catch (const std::exception &e) {
      controller->Clean();
      answer = "ERROR!";
    }
    ui->result_show->setText(answer);
  } else {
    ui->lineEdit_value_x->setText("0");
  }
}

bool GraphicView::CorrectInputX(const QString &input_x) {
  static QRegularExpression regularDigit(
      R"(^([+-])?(\d)+(\.(\d)+)?(e([+-])?(\d)+)?$)");

  QRegularExpressionMatch match = regularDigit.match(input_x);
  if (match.hasMatch()) {
    return true;
  } else {
    return false;
  }
}

void GraphicView::GraphButtonProcessing() {
  graph_window->show();
  emit SendExpressionToGraph(ui->result_show->text());
  this->close();
}

void GraphicView::CreditButtonProcessing() {
  credit_window->show();
  this->close();
}

}  // namespace s21
