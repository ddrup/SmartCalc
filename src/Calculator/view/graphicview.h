#ifndef GRAPHICVIEW_H
#define GRAPHICVIEW_H

#include <QDebug>  // Delete
#include <QMainWindow>
#include <QRegularExpression>
#include <QString>

#include "../controller/controller.h"
#include "credit/creditcalculator.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GraphicView;
}
QT_END_NAMESPACE

namespace s21 {

class GraphicView : public QMainWindow {
  Q_OBJECT

 public:
  GraphicView(Controller *c, QWidget *parent = nullptr);
  ~GraphicView();

 private:
  Ui::GraphicView *ui;
  s21::Controller *controller;
  Graph *graph_window;
  CreditCalculator *credit_window;

  bool CorrectInputX(const QString &input_x);

 private slots:
  void DigitProcessing();
  void OperationProcessing();
  void FunctionProcessing();
  void OthersButtonProcessing();
  void ACButtonProcessing();
  void DeleteButtonProcessing();
  void EqualButtonProcessing();
  void GraphButtonProcessing();
  void CreditButtonProcessing();

 signals:
  void SendExpressionToGraph(const QString &expression);
};

}  // namespace s21
#endif  // GRAPHICVIEW_H
