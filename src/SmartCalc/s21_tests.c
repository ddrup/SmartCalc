#include <check.h>

#include "s21_calc.h"

START_TEST(test_calc1) {
  char *str = "2 + 2";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq(result, 4);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc2) {
  char *str = "sin(5) * tan(1) + 23";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq_tol(result, 21.5066, 4);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc3) {
  char *str = "cos(5) / 2^5";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq_tol(result, 0.0089, 4);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc4) {
  char *str = "asin(1) + acos(0) + atan(1)";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq_tol(result, 3.9270, 4);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc5) {
  char *str = "log(1000) - ln(56)";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq_tol(result, -1.0253, 4);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc6) {
  char *str = "(17)mod2";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq(result, 1);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc7) {
  char *str = "234 + 5 * 4 + (10 * sin(10))";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq_tol(result, 248.559788, 5);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc8) {
  char *str = "X + 5";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 5;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq(result, 10);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc9) {
  char *str = "sqrt(16)";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq(result, 4);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc10) {
  char *str = "435/0";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc11) {
  char *str = "-435+485-";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc12) {
  char *str = "(4/0)";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc13) {
  char *str = "+12-45";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);
  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq(result, -33);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc14) {
  char *str = "4 * (-12) + atan(10) * 4";

  stack *stack1 = NULL;
  s21_parser_string(&stack1, str);
  s21_reverse_stack(&stack1);

  s21_reverse_polish_notation(&stack1);
  double value_x = 0;
  double result = s21_calculate_expression(&stack1, value_x);

  ck_assert_double_eq_tol(result, -45.4065566902, 5);
  free_stack(&stack1);
}
END_TEST

START_TEST(test_calc15) {
  char *str =
      "657567567567567567567567567567567567567+56450650460+45/"
      "5+4+2+2+2+67-34+(1mod3+log(100)+9+(-43)*34/"
      "(34+4345)+435+345435+45345345+435345)+54654654+456456456+5464-45*453+"
      "45345+4543565365/"
      "64564*0453045+"
      "5546456459069456894596984568945869548645868459689549684556546";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc16) {
  char *str = "((((43+4358)";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc17) {
  char *str = "323.5 + 354";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, OK);
}
END_TEST

START_TEST(test_calc18) {
  char *str = "(-)";
  int error_code = OK;
  str = s21_check_correct_string(str, &error_code);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc19) {
  char *str = "456.546";
  int error_code = OK;
  error_code = s21_check_correct_value_date(str);
  ck_assert_int_eq(error_code, INCORRECT_VALUE);
}
END_TEST

START_TEST(test_calc20) {
  char *str = "51";
  int error_code = OK;
  error_code = s21_check_correct_value_date(str);
  ck_assert_int_eq(error_code, VALUE_TOO_MATCH);
}
END_TEST

START_TEST(test_calc21) {
  char *str = "";
  int error_code = OK;
  error_code = s21_check_correct_value_date(str);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc22) {
  char *str = "4524354252345432534";
  int error_code = OK;
  error_code = s21_check_correct_value(str);
  ck_assert_int_eq(error_code, VALUE_TOO_MATCH);
}
END_TEST

START_TEST(test_calc23) {
  char *str = "";
  int error_code = OK;
  error_code = s21_check_correct_value(str);
  ck_assert_int_eq(error_code, ERROR);
}
END_TEST

START_TEST(test_calc24) {
  char *str = "345.4..";
  int error_code = OK;
  error_code = s21_check_correct_value(str);
  ck_assert_int_eq(error_code, INCORRECT_VALUE);
}
END_TEST

Suite *my_tests_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("SmartCalc Tests");

  tc_core = tcase_create("TESTS");

  tcase_add_test(tc_core, test_calc1);
  tcase_add_test(tc_core, test_calc2);
  tcase_add_test(tc_core, test_calc3);
  tcase_add_test(tc_core, test_calc4);
  tcase_add_test(tc_core, test_calc5);
  tcase_add_test(tc_core, test_calc6);
  tcase_add_test(tc_core, test_calc7);
  tcase_add_test(tc_core, test_calc8);
  tcase_add_test(tc_core, test_calc9);
  tcase_add_test(tc_core, test_calc10);
  tcase_add_test(tc_core, test_calc11);
  tcase_add_test(tc_core, test_calc12);
  tcase_add_test(tc_core, test_calc13);
  tcase_add_test(tc_core, test_calc14);
  tcase_add_test(tc_core, test_calc15);
  tcase_add_test(tc_core, test_calc16);
  tcase_add_test(tc_core, test_calc17);
  tcase_add_test(tc_core, test_calc18);
  tcase_add_test(tc_core, test_calc19);
  tcase_add_test(tc_core, test_calc20);
  tcase_add_test(tc_core, test_calc21);
  tcase_add_test(tc_core, test_calc22);
  tcase_add_test(tc_core, test_calc23);
  tcase_add_test(tc_core, test_calc24);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int number_failed = 0;
  Suite *suite;
  SRunner *srunner;

  suite = my_tests_suite();
  srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_NORMAL);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
