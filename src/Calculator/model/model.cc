#include "model.h"

namespace s21 {

void Model::CalculateExpression(const std::string &expression,
                                const std::string &input_x) {
  input_expression_ = expression;
  input_x_ = input_x;

  ParsingString();
  CheckCorrectTokenDeque();
  ConvertToRPN();
  Calculate();
}

void Model::CalculateGraph(const std::string &expression, double scale,
                           double x_min, double x_max) {
  input_expression_ = expression;

  ParsingString();
  CheckCorrectTokenDeque();
  ConvertToRPN();
  double x = x_min;
  while (x <= x_max) {
    std::deque<Token> tmp_tokens = result_tokens_;
    input_x_ = std::to_string(x);
    Calculate();
    result_tokens_ = tmp_tokens;

    answer_graph_.first.push_back(x);
    answer_graph_.second.push_back(GetAnswer());
    x += scale;
  }
}

double Model::GetAnswer() const { return answer_; }

Model::XYGraph Model::GetGraph() const { return answer_graph_; }

Credit Model::GetCredit() const { return credit; }

void Model::ParsingString() {
  std::string current_token = "";
  const std::regex regular_word("([a-z])+");
  const std::regex regular_digit("(\\d)+(\\.(\\d)+)?(e([+-])?(\\d)+)?");

  for (size_t i = 0; i < input_expression_.size(); i++) {
    if (isalpha(input_expression_[i])) {
      current_token = ReadToken(regular_word, i);
    } else if (isdigit(input_expression_[i])) {
      current_token = ReadToken(regular_digit, i);
    } else {
      current_token = input_expression_[i];
    }
    AddTokenToDeque(current_token);
  }
}

std::string Model::ReadToken(const std::regex &regular_token,
                             size_t &start_index) const {
  std::sregex_iterator regex_iterator(input_expression_.begin() + start_index,
                                      input_expression_.end(), regular_token);
  std::smatch match = *regex_iterator;
  start_index += (match.length() - 1);
  return match.str();
}

void Model::AddTokenToDeque(const std::string &token) {
  static std::unordered_map<std::string, Token> list{
      {"x", Token("x", kDefault, kNone, kNumber, kNumbers)},
      {"+", Token("+", kLow, kLeft, kPlus, kBinaryOperators)},
      {"-", Token("-", kLow, kLeft, kMinus, kBinaryOperators)},
      {"*", Token("*", kMedium, kLeft, kMultiply, kBinaryOperators)},
      {"/", Token("/", kMedium, kLeft, kDivide, kBinaryOperators)},
      {"mod", Token("mod", kMedium, kLeft, kMod, kBinaryOperators)},
      {"^", Token("^", kHigh, kRight, kDegree, kBinaryOperators)},
      {"(", Token("(", kDefault, kNone, kOpenBracket, kOpenBrackets)},
      {")", Token(")", kDefault, kNone, kCloseBracket, kCloseBrackets)},
      {"cos", Token("cos", kFunction, kLeft, kCos, kFunctions)},
      {"sin", Token("sin", kFunction, kLeft, kSin, kFunctions)},
      {"tan", Token("tan", kFunction, kLeft, kTan, kFunctions)},
      {"acos", Token("acos", kFunction, kLeft, kAcos, kFunctions)},
      {"asin", Token("asin", kFunction, kLeft, kAsin, kFunctions)},
      {"atan", Token("atan", kFunction, kLeft, kAtan, kFunctions)},
      {"sqrt", Token("sqrt", kFunction, kLeft, kSqrt, kFunctions)},
      {"log", Token("log", kFunction, kLeft, kLog, kFunctions)},
      {"ln", Token("ln", kFunction, kLeft, kLn, kFunctions)},
      {"e", Token("e", kDefault, kNone, kNumber, kNumbers)},
  };

  if (auto token_map = list.find(token); token_map != list.end()) {
    if (token == "-" &&
        (input_tokens_.empty() || input_tokens_.back().GetName() == "(")) {
      input_tokens_.push_back(
          Token("-", kUnaryOperator, kLeft, kUnaryMinus, kUnaryOperators));
    } else if (token == "+" && (input_tokens_.empty() ||
                                input_tokens_.back().GetName() == "(")) {
      input_tokens_.push_back(
          Token("+", kUnaryOperator, kLeft, kUnaryPlus, kUnaryOperators));
    } else {
      input_tokens_.push_back(list[token]);
    }
  } else {
    if (isdigit(token[0])) {
      input_tokens_.push_back(Token(token, kDefault, kNone, kNumber, kNumbers));
    } else {
      throw std::invalid_argument("Incorrect token");
    }
  }
}

void Model::CheckCorrectTokenDeque() {
  if (input_tokens_.empty()) {
    throw std::invalid_argument("Empty input tokens");
  }
  size_t count_brackes = 0;

  Kind current_type = input_tokens_.front().GetKind();
  output_tokens_.push_back(input_tokens_.front());

  if (current_type == kOpenBrackets) ++count_brackes;

  if (current_type == kBinaryOperators || current_type == kCloseBrackets) {
    throw std::invalid_argument("Incorrect expression");
  }

  input_tokens_.pop_front();
  while (!input_tokens_.empty()) {
    Kind prev_type = current_type;
    current_type = input_tokens_.front().GetKind();

    if (current_type == kOpenBrackets) ++count_brackes;
    if (current_type == kCloseBrackets) --count_brackes;

    if (adjacency_matrix_[prev_type][current_type] == 0) {
      throw std::invalid_argument("Incorrect expression");
    }

    output_tokens_.push_back(input_tokens_.front());
    input_tokens_.pop_front();
  }
  if (adjacency_matrix_[current_type][kEndExpression] == 0 ||
      count_brackes != 0) {
    throw std::invalid_argument("Incorrect expression");
  }
}

void Model::ConvertToRPN() {
  std::stack<Token> support_stack;

  while (!output_tokens_.empty()) {
    Token token = output_tokens_.front();
    if (token.GetKind() == kBinaryOperators) {
      while (!support_stack.empty()) {
        Token temp_token = support_stack.top();
        if (temp_token.GetAssociativity() == kRight &&
            (temp_token.GetPrecedence() > token.GetPrecedence())) {
          result_tokens_.push_back(temp_token);
        } else if (temp_token.GetAssociativity() == kLeft &&
                   (temp_token.GetPrecedence() >= token.GetPrecedence())) {
          result_tokens_.push_back(temp_token);
        } else {
          break;
        }
        support_stack.pop();
      }
      support_stack.push(token);
    } else if (token.GetKind() == kCloseBrackets) {
      while (support_stack.top().GetKind() != kOpenBrackets) {
        result_tokens_.push_back(support_stack.top());
        support_stack.pop();
      }
      support_stack.pop();
    } else if (token.GetKind() == kNumbers) {
      result_tokens_.push_back(token);
    } else {
      support_stack.push(token);
    }
    output_tokens_.pop_front();
  }
  while (!support_stack.empty()) {
    result_tokens_.push_back(support_stack.top());
    support_stack.pop();
  }
}

void Model::Calculate() {
  std::stack<double> support_stack;
  while (!result_tokens_.empty()) {
    Token current_token = result_tokens_.front();
    if (current_token.GetKind() == kNumbers) {
      double value = 0;
      if (current_token.GetName() == "x") {
        value = std::stod(input_x_);
      } else if (current_token.GetName() == "e") {
        value = 2.718281828459045;
      } else {
        value = std::stod(current_token.GetName());
      }
      support_stack.push(value);
    } else if (current_token.GetKind() == kBinaryOperators) {
      CalculateBinaryOperator(support_stack, current_token);
    } else if (current_token.GetKind() == kUnaryOperators) {
      CalculateUnaryOperator(support_stack, current_token);
    } else if (current_token.GetKind() == kFunctions) {
      CalculateFunction(support_stack, current_token);
    }
    result_tokens_.pop_front();
  }
  answer_ = support_stack.top();
}

void Model::CalculateBinaryOperator(std::stack<double> &support_stack,
                                    Token &token) {
  double value2 = support_stack.top();
  support_stack.pop();
  double value1 = support_stack.top();
  support_stack.pop();

  if (token.GetType() == kPlus) {
    value1 += value2;
  } else if (token.GetType() == kMinus) {
    value1 -= value2;
  } else if (token.GetType() == kMultiply) {
    value1 *= value2;
  } else if (token.GetType() == kDivide) {
    value1 /= value2;
  } else if (token.GetType() == kDegree) {
    value1 = pow(value1, value2);
  } else if (token.GetType() == kMod) {
    if (std::floor(value1) != value1 || std::floor(value2) != value2) {
      throw std::invalid_argument(
          "Division with remainder must have integer operands");
    }
    long long integer_value1 = static_cast<long long>(value1);
    long long integer_value2 = static_cast<long long>(value2);
    int remainder = integer_value1 % integer_value2;
    if (remainder < 0) {
      remainder += std::abs(integer_value2);
    }
    value1 = remainder;
  }
  support_stack.push(value1);
}

void Model::CalculateUnaryOperator(std::stack<double> &support_stack,
                                   Token &token) {
  double value = support_stack.top();
  support_stack.pop();
  if (token.GetType() == kUnaryMinus) {
    value *= (-1);
  }
  support_stack.push(value);
}

void Model::CalculateFunction(std::stack<double> &support_stack, Token &token) {
  double value = support_stack.top();
  support_stack.pop();
  if (token.GetType() == kCos) {
    value = cos(value);
  } else if (token.GetType() == kSin) {
    value = sin(value);
  } else if (token.GetType() == kTan) {
    value = tan(value);
  } else if (token.GetType() == kAsin) {
    value = asin(value);
  } else if (token.GetType() == kAcos) {
    value = acos(value);
  } else if (token.GetType() == kAtan) {
    value = atan(value);
  } else if (token.GetType() == kSqrt) {
    value = sqrt(value);
  } else if (token.GetType() == kLn) {
    value = log(value);
  } else if (token.GetType() == kLog) {
    value = log10(value);
  }
  support_stack.push(value);
}

void Model::ModelClean() {
  input_expression_ = "";
  input_x_ = "";
  answer_ = 0;
  input_tokens_.clear();
  output_tokens_.clear();
  result_tokens_.clear();
  answer_graph_.first.clear();
  answer_graph_.second.clear();
  credit.payment.clear();
}

void Model::CalculateCredit(const std::string &sum, const std::string &rate,
                            const std::string &date,
                            const TypeOfDate &type_of_date,
                            const TypeOfPayment &type_of_payment) {
  const std::regex regular_digit_double(
      "^(\\d)+(\\.(\\d)+)?(e([+-])?(\\d)+)?$");
  const std::regex regular_digit_integer("^(\\d)+$");

  if (!std::regex_match(sum, regular_digit_double) ||
      !std::regex_match(rate, regular_digit_integer) ||
      !std::regex_match(date, regular_digit_integer)) {
    throw std::invalid_argument("Incorrect value");
  }

  long double summ = stoi(sum);
  long long coefficient = stoi(rate);
  long long time = stoi(date);

  if (time <= 0 || time > 50 || coefficient <= 0 || coefficient > 1000) {
    throw std::invalid_argument("Incorrect value");
  }
  if (type_of_date == kYear) time *= 12;

  if (type_of_payment == kAnnuity) {
    long double cf = pow((1 + coefficient / 1200.0), time) /
                     (pow((1 + coefficient / 1200.0), time) - 1) *
                     (coefficient / 1200.0);

    credit.sum_month = summ * cf;
    credit.common_payment = credit.sum_month * time;
    credit.overpayment = credit.common_payment - summ;
    credit.date = time;

  } else if (type_of_payment == kDifferentiated) {
    long double common_summ = summ;
    long double base_payment = summ / time;
    long double over_payment = 0;

    for (int i = 0; i < time; i++) {
      long double payment_rate = summ * (coefficient / 12.0) * 0.01;
      credit.payment.push_back(base_payment + payment_rate);
      over_payment += base_payment + payment_rate;
      summ -= base_payment;
    }

    credit.common_payment = over_payment;
    credit.overpayment = over_payment - common_summ;
    credit.sum_month = 0;
    credit.date = time;
  }
}

}  // namespace s21