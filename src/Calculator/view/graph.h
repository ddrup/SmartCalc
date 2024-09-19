#ifndef GRAPH_H
#define GRAPH_H

#include <QDebug>
#include <QVector>
#include <QWidget>
#include <vector>

#include "../controller/controller.h"

namespace Ui {
class Graph;
}

namespace s21 {

class Graph : public QWidget {
  Q_OBJECT

 public:
  Graph(Controller *c, QWidget *parent = nullptr);
  ~Graph();

 private:
  Ui::Graph *ui;
  s21::Controller *controller;
  QString label;

 signals:
  void FirstWindow();

 private slots:
  void BackButtonProcessing();
  void ApplyButtonProcessing();

 public slots:
  void ReceiveExpression(const QString &expression);
};

}  // namespace s21
#endif  // GRAPH_H
