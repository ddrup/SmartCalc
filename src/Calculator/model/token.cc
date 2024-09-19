#include "token.h"

Token::Token(const std::string &name, Precedence precedence,
             Associativity associativity, Type type, Kind kind)
    : name_(name),
      precedence_(precedence),
      associativity_(associativity),
      type_(type),
      kind_(kind) {}

std::string Token::GetName() const { return name_; }

Kind Token::GetKind() const { return kind_; }

Precedence Token::GetPrecedence() const { return precedence_; }

Associativity Token::GetAssociativity() const { return associativity_; }

Type Token::GetType() const { return type_; }