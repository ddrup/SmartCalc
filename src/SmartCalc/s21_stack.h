#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1
#define VALUE_TOO_MATCH 2
#define INCORRECT_VALUE 3

typedef enum Type {
  NUMBER = 1,
  X = 2,
  PLUS = 3,
  MINUS = 4,
  MULTIPLY = 5,
  DIVIDE = 6,
  DEGREE = 7,
  MOD = 8,
  BRACKET_FIRST = 9,
  BRACKET_SECOND = 10,
  COS = 11,
  SIN = 12,
  TAN = 13,
  ASIN = 14,
  ACOS = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19
} type_t;

typedef struct Stack {
  double value;
  int priority;
  type_t type;
  struct Stack *next;
} stack;

void push_back(stack **head, double val, int priority, type_t type);
void pop_back(stack **head);
void peek_back(stack **head, double *val, int *priority, type_t *type);
void free_stack(stack **head);

#endif
