#include "controller.h"

namespace s21 {

Controller::Controller(Model *m) : model(m) {}

double Controller::CalculateExpression(const std::string &expression,
                                       const std::string &input_x) {
  model->CalculateExpression(expression, input_x);
  return model->GetAnswer();
}

void Controller::Clean() { model->ModelClean(); }

Model::XYGraph Controller::CalculateGraph(const std::string &expression,
                                          double scale, double x_min,
                                          double x_max) {
  model->Model::CalculateGraph(expression, scale, x_min, x_max);
  return model->Model::GetGraph();
}

Credit Controller::CalculateCredit(const std::string &sum,
                                   const std::string &rate,
                                   const std::string &date,
                                   const TypeOfDate &type_of_date,
                                   const TypeOfPayment &type_of_payment) {
  model->CalculateCredit(sum, rate, date, type_of_date, type_of_payment);
  return model->Model::GetCredit();
}

}  // namespace s21
