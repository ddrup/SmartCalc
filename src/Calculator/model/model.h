#ifndef CPP3_SMARTCALC_SRC_MODEL_H_
#define CPP3_SMARTCALC_SRC_MODEL_H_

#include <cmath>
#include <deque>
#include <regex>
#include <stack>
#include <unordered_map>
#include <vector>

#include "token.h"

namespace s21 {

struct Credit {
  std::vector<long double> payment;
  long double sum_month;
  long double common_payment;
  long double overpayment;
  int date;
};

enum TypeOfPayment {
  kAnnuity,
  kDifferentiated,
};

enum TypeOfDate {
  kMonth,
  kYear,
};

class Model {
 public:
  using XYGraph = std::pair<std::vector<double>, std::vector<double>>;

  Model() = default;
  ~Model() = default;

  void CalculateExpression(const std::string &expression,
                           const std::string &input_x);
  void CalculateGraph(const std::string &expression, double scale, double x_min,
                      double x_max);
  void CalculateCredit(const std::string &sum, const std::string &rate,
                       const std::string &date, const TypeOfDate &type_of_date,
                       const TypeOfPayment &type_of_payment);

  double GetAnswer() const;
  XYGraph GetGraph() const;
  Credit GetCredit() const;

  void ModelClean();

 private:
  std::string input_expression_;
  std::string input_x_;
  double answer_;
  XYGraph answer_graph_;
  Credit credit;

  std::deque<Token> input_tokens_;
  std::deque<Token> output_tokens_;
  std::deque<Token> result_tokens_;

  static constexpr bool adjacency_matrix_[7][7] = {
      {0, 1, 0, 0, 0, 1, 1},  // kNumbers
      {1, 0, 0, 1, 1, 0, 0},  // kBinaryOperators
      {1, 0, 0, 1, 1, 0, 0},  // kUnaryOperators
      {0, 0, 0, 0, 1, 0, 0},  // kFunctions
      {1, 0, 1, 1, 1, 0, 0},  // kOpenBrackets
      {0, 1, 0, 0, 0, 1, 1},  // kCloseBrackets
      {0, 0, 0, 0, 0, 0, 0},  // kEndExpression
  };

  void ParsingString();
  std::string ReadToken(const std::regex &regular_token,
                        size_t &start_index) const;
  void AddTokenToDeque(const std::string &token);
  void CheckCorrectTokenDeque();
  void ConvertToRPN();
  void Calculate();
  void CalculateBinaryOperator(std::stack<double> &support_stack, Token &token);
  void CalculateUnaryOperator(std::stack<double> &support_stack, Token &token);
  void CalculateFunction(std::stack<double> &support_stack, Token &token);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_SRC_MODEL_H_
