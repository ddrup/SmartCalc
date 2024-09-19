#ifndef CPP3_SMARTCALC_SRC_TOKEN_H_
#define CPP3_SMARTCALC_SRC_TOKEN_H_

#include <string>

enum Precedence {
  kLow,
  kMedium,
  kHigh,
  kDefault,
  kUnaryOperator,
  kFunction,
};

enum Associativity {
  kLeft,
  kRight,
  kNone,
};

enum Type {
  kNumber,
  kPlus,
  kMinus,
  kMultiply,
  kDivide,
  kDegree,
  kMod,
  kOpenBracket,
  kCloseBracket,
  kCos,
  kSin,
  kTan,
  kAsin,
  kAcos,
  kAtan,
  kSqrt,
  kLn,
  kLog,
  kUnaryMinus,
  kUnaryPlus,
};

enum Kind {
  kNumbers,
  kBinaryOperators,
  kUnaryOperators,
  kFunctions,
  kOpenBrackets,
  kCloseBrackets,
  kEndExpression,
};

class Token {
 public:
  Token() = default;
  Token(const std::string &name, Precedence precedence,
        Associativity associativity, Type type, Kind kind);

  std::string GetName() const;
  Kind GetKind() const;
  Type GetType() const;
  Precedence GetPrecedence() const;
  Associativity GetAssociativity() const;

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  Type type_;
  Kind kind_;
};

#endif  // CPP3_SMARTCALC_SRC_TOKEN_H_
