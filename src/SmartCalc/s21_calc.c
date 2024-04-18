#include "s21_calc.h"

void s21_parser_string(stack **stack_string, char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      parser_number(stack_string, str, &i);
    } else if (str[i] == 'X') {
      push_back(stack_string, 0, 0, X);
    } else if (str[i] == '+') {
      if (i == 0 || (i != 0 && str[i - 1] == '(')) {
        push_back(stack_string, 0, 0, NUMBER);
      }
      push_back(stack_string, 0, 1, PLUS);
    } else if (str[i] == '-') {
      if (i == 0 || (i != 0 && str[i - 1] == '(')) {
        push_back(stack_string, 0, 0, NUMBER);
      }
      push_back(stack_string, 0, 1, MINUS);
    } else if (str[i] == '*') {
      push_back(stack_string, 0, 2, MULTIPLY);
    } else if (str[i] == '/') {
      push_back(stack_string, 0, 2, DIVIDE);
    } else if (str[i] == 'm') {
      push_back(stack_string, 0, 2, MOD);
      i += 2;
    } else if (str[i] == '^') {
      push_back(stack_string, 0, 3, DEGREE);
    } else if (str[i] == '(') {
      push_back(stack_string, 0, 5, BRACKET_FIRST);
    } else if (str[i] == ')') {
      push_back(stack_string, 0, 5, BRACKET_SECOND);
    } else if (str[i] == 'c') {
      push_back(stack_string, 0, 4, COS);
      i += 2;
    } else if (str[i] == 's' && str[i + 1] == 'i') {
      push_back(stack_string, 0, 4, SIN);
      i += 2;
    } else if (str[i] == 't') {
      push_back(stack_string, 0, 4, TAN);
      i += 2;
    } else if (str[i] == 'a' && str[i + 1] == 'c') {
      push_back(stack_string, 0, 4, ACOS);
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 's') {
      push_back(stack_string, 0, 4, ASIN);
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 't') {
      push_back(stack_string, 0, 4, ATAN);
      i += 3;
    } else if (str[i] == 's' && str[i + 1] == 'q') {
      push_back(stack_string, 0, 4, SQRT);
      i += 3;
    } else if (str[i] == 'l' && str[i + 1] == 'o') {
      push_back(stack_string, 0, 4, LOG);
      i += 3;
    } else if (str[i] == 'l' && str[i + 1] == 'n') {
      push_back(stack_string, 0, 4, LN);
      i += 1;
    }
  }
}

void parser_number(stack **stack_string, char *str, size_t *i) {
  char number[256] = "";
  int counter = 0;
  while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.') {
    number[counter] = str[*i];
    counter += 1;
    (*i) += 1;
  }
  double tmp = atof(number);
  push_back(stack_string, tmp, 0, NUMBER);
  (*i) -= 1;
}

void s21_reverse_polish_notation(stack **new_stack) {
  stack *ready = NULL;
  stack *support = NULL;
  double val = 0;
  int priority = 0;
  type_t type = 0;
  while (*new_stack != NULL) {
    peek_back(new_stack, &val, &priority, &type);
    double tmp_val = 0;
    int tmp_priority = 0;
    type_t tmp_type = 0;
    int flag = 0;
    if (type == NUMBER || type == X) {
      push_back(&ready, val, priority, type);
      flag = 1;
    }
    while (support != NULL && flag == 0) {
      peek_back(&support, &tmp_val, &tmp_priority, &tmp_type);
      if (type == BRACKET_SECOND && tmp_type != BRACKET_FIRST) {
        push_back(&ready, tmp_val, tmp_priority, tmp_type);
        pop_back(&support);
      } else if (type == BRACKET_SECOND && tmp_type == BRACKET_FIRST) {
        pop_back(&support);
        flag = 1;
      } else if (tmp_type == BRACKET_FIRST) {
        flag = 1;
      } else {
        if (priority <= tmp_priority) {
          push_back(&ready, tmp_val, tmp_priority, tmp_type);
          pop_back(&support);
        } else {
          flag = 1;
        }
      }
    }
    if (type != BRACKET_SECOND && type != NUMBER && type != X) {
      push_back(&support, val, priority, type);
    }
    pop_back(new_stack);
  }
  while (support != NULL) {
    peek_back(&support, &val, &priority, &type);
    push_back(&ready, val, priority, type);
    pop_back(&support);
  }
  while (ready != NULL) {
    peek_back(&ready, &val, &priority, &type);
    push_back(new_stack, val, priority, type);
    pop_back(&ready);
  }
}

double s21_calculate_expression(stack **new_stack, double value_x) {
  stack *support = NULL;
  double val = 0;
  int priority = 0;
  type_t type = 0;
  while (*new_stack != NULL) {
    peek_back(new_stack, &val, &priority, &type);
    if (type == NUMBER) {
      push_back(&support, val, priority, type);
    } else if (type == X) {
      push_back(&support, value_x, priority, NUMBER);
    } else if (type < 10) {
      s21_calculate_value(&support, type);
    } else {
      s21_calculate_function(&support, type);
    }
    pop_back(new_stack);
  }
  peek_back(&support, &val, &priority, &type);
  pop_back(&support);
  return val;
}

void s21_calculate_value(stack **support, type_t type) {
  double val_1 = 0;
  double val_2 = 0;
  double result = 0;
  int tmp_pri = 0;
  type_t ty = 0;
  peek_back(support, &val_2, &tmp_pri, &ty);
  pop_back(support);
  peek_back(support, &val_1, &tmp_pri, &ty);
  pop_back(support);
  if (type == PLUS) {
    result = val_1 + val_2;
  } else if (type == MINUS) {
    result = val_1 - val_2;
  } else if (type == MULTIPLY) {
    result = val_1 * val_2;
  } else if (type == DIVIDE) {
    result = val_1 / val_2;
  } else if (type == DEGREE) {
    result = pow(val_1, val_2);
  } else {
    result = (int)val_1 % (int)val_2;
  }
  push_back(support, result, 0, 1);
}

void s21_calculate_function(stack **support, type_t type) {
  double val_1 = 0;
  double result = 0;
  int tmp_pri = 0;
  type_t ty = 0;
  peek_back(support, &val_1, &tmp_pri, &ty);
  pop_back(support);
  if (type == COS) {
    result = cos(val_1);
  } else if (type == SIN) {
    result = sin(val_1);
  } else if (type == TAN) {
    result = tan(val_1);
  } else if (type == ACOS) {
    result = acos(val_1);
  } else if (type == ASIN) {
    result = asin(val_1);
  } else if (type == ATAN) {
    result = atan(val_1);
  } else if (type == SQRT) {
    result = sqrt(val_1);
  } else if (type == LN) {
    result = log(val_1);
  } else if (type == LOG) {
    result = log10(val_1);
  }
  push_back(support, result, 0, 1);
}

void s21_reverse_stack(stack **stack_string) {
  stack *tmp_stack = NULL;
  stack *tmp_stack_1 = NULL;
  double val = 0;
  int priority = 0;
  type_t type = 0;
  while ((*stack_string) != NULL) {
    peek_back(stack_string, &val, &priority, &type);
    push_back(&tmp_stack, val, priority, type);
    pop_back(stack_string);
  }
  while (tmp_stack != NULL) {
    peek_back(&tmp_stack, &val, &priority, &type);
    push_back(&tmp_stack_1, val, priority, type);
    pop_back(&tmp_stack);
  }
  while (tmp_stack_1 != NULL) {
    peek_back(&tmp_stack_1, &val, &priority, &type);
    push_back(stack_string, val, priority, type);
    pop_back(&tmp_stack_1);
  }
}

int s21_check_correct_value(char *string) {
  int err_code = OK;
  if (strlen(string) == 0 || (strlen(string) == 1 && string[0] == 0)) {
    err_code = ERROR;
  } else {
    for (int i = 0; i < (int)strlen(string); i++) {
      int count_digit = 0;
      int flag = 0;
      while ((string[i] >= '0' && string[i] <= '9') || string[i] == '.') {
        if (string[i] == '.') {
          flag += 1;
        }
        if (flag == 0) {
          count_digit += 1;
        }
        i++;
      }
      if (count_digit > 17) {
        err_code = VALUE_TOO_MATCH;
      }
      if (flag > 1) {
        err_code = INCORRECT_VALUE;
      }
    }
  }
  return err_code;
}

int s21_check_correct_value_date(char *string) {
  int err_code = OK;
  if (strlen(string) == 0 || (strlen(string) == 1 && string[0] == 0)) {
    err_code = ERROR;
  } else {
    int flag = 0;
    for (int i = 0; i < (int)strlen(string); i++) {
      if (string[i] == '.') {
        flag = 1;
      }
    }
    if (flag == 1) {
      err_code = INCORRECT_VALUE;
    } else {
      int value = atof(string);
      if (value > 50) {
        err_code = VALUE_TOO_MATCH;
      }
    }
  }
  return err_code;
}

char *s21_check_correct_string(char *string, int *err_code) {
  *err_code = OK;
  int bracket = 0;
  int number = 0;
  size_t size = strlen(string);
  size_t i = 0;
  if (size > 255) {
    *err_code = ERROR;
  } else {
    for (i = 0; i < size; i++) {
      if (string[i] == '(') {
        bracket += 1;
      }
      if (string[i] == ')') {
        bracket -= 1;
      }
      if (i == size - 1 &&
          (string[i] == '+' || string[i] == '-' || string[i] == '*' ||
           string[i] == '/' || string[i] == 'd' || string[i] == '^' ||
           string[i] == '(' || string[i] == '.')) {
        (*err_code) = ERROR;
      } else if (i <= size - 2 && string[i] == '/' && string[i + 1] == '0' &&
                 !((string[i + 2] >= '0' && string[i + 2] <= '9') ||
                   string[i + 2] == '.')) {
        (*err_code) = ERROR;
      }
    }
    if (bracket != 0) {
      (*err_code) = ERROR;
    } else {
      for (i = 0; i < size; i++) {
        if (string[i] == '(') {
          number = 0;
        }
        if (string[i] == ')') {
          if (!number) {
            *err_code = ERROR;
          }
        }
        if ((string[i] >= '0' && string[i] <= '9') || string[i] == 'X') {
          number = 1;
        }
      }
    }
    if (*err_code == OK) {
      *err_code = s21_check_correct_value(string);
    }
  }

  return string;
}
