#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
 public:
  Controller(Model *m);

  double CalculateExpression(const std::string &expression,
                             const std::string &input_x);
  Model::XYGraph CalculateGraph(const std::string &expression, double scale,
                                double x_min, double x_max);
  Credit CalculateCredit(const std::string &sum, const std::string &rate,
                         const std::string &date,
                         const TypeOfDate &type_of_date,
                         const TypeOfPayment &type_of_payment);

  void Clean();

 private:
  Model *model;
};

}  // namespace s21

#endif  // CONTROLLER_H
