#include "graph.h"

#include "ui_graph.h"

namespace s21 {

Graph::Graph(Controller *c, QWidget *parent)
    : QWidget(parent), ui(new Ui::Graph), controller(c) {
  ui->setupUi(this);

  // Default value graph
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);
  ui->spinBox_min_y->setValue(-10);
  ui->spinBox_max_y->setValue(10);
  ui->spinBox_min_x->setValue(-10);
  ui->spinBox_max_x->setValue(10);

  connect(ui->pushButton_back, SIGNAL(clicked()), this,
          SLOT(BackButtonProcessing()));
  connect(ui->pushButton_graphic, SIGNAL(clicked()), this,
          SLOT(ApplyButtonProcessing()));
}

Graph::~Graph() { delete ui; }

void Graph::BackButtonProcessing() {
  this->close();
  emit FirstWindow();
}

void Graph::ReceiveExpression(const QString &expression) { label = expression; }

void Graph::ApplyButtonProcessing() {
  controller->Clean();
  double min_y = ui->spinBox_min_y->value();
  double min_x = ui->spinBox_min_x->value();

  double max_y = ui->spinBox_max_y->value();
  double max_x = ui->spinBox_max_x->value();

  long long scale = qMax(max_x - min_x, max_y - min_y);
  double h = 0;
  if (scale < 2000) {
    h = 0.01;
  } else if (scale < 200000) {
    h = 1;
  } else {
    h = 10;
  }

  ui->widget->xAxis->setRange(min_x, max_x);
  ui->widget->yAxis->setRange(min_y, max_y);

  std::string expression = label.toStdString();
  try {
    ui->widget->clearGraphs();
    Model::XYGraph result =
        controller->Controller::CalculateGraph(expression, h, min_x, max_x);
    QVector<double> x(result.first.begin(), result.first.end());
    QVector<double> y(result.second.begin(), result.second.end());

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->graph(0)->setPen(QPen(Qt::blue, 2));
    ui->widget->replot();
  } catch (const std::exception &e) {
    controller->Clean();
  }
}

}  // namespace s21
