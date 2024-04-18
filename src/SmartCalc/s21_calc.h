#ifndef SRC_SMARTCALC_H
#define SRC_SMARTCALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_stack.h"

void s21_parser_string(stack **stack_string, char *str);
void parser_number(stack **stack_string, char *str, size_t *i);
void s21_reverse_polish_notation(stack **new_stack);
double s21_calculate_expression(stack **new_stack, double value_x);
void s21_calculate_value(stack **support, type_t type);
void s21_calculate_function(stack **support, type_t type);
void s21_reverse_stack(stack **stack_string);
int s21_check_correct_value(char *string);
int s21_check_correct_value_date(char *string);
char *s21_check_correct_string(char *string, int *err_code);

#endif
