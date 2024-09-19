#include <gtest/gtest.h>

#include "model/model.h"
#include "model/token.h"

using namespace s21;

TEST(SmartCalc, Test1) {
  s21::Model model;
  std::string str = "2^2^3";
  std::string x = "0";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  EXPECT_EQ(res, 256);
}

TEST(SmartCalc, TestFuncError1) {
  s21::Model model;
  std::string str = "(1000/5)*3mod6+(2489298-234321)-cos(45)";
  std::string x = "0";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  ASSERT_NEAR(res, 2254976.47, 0.01);
}

TEST(SmartCalc, TestOperation) {
  s21::Model model;
  std::string str = "tan(acos(1))+atan(-1)-sin(4)*asin(0)";
  std::string x = "0";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  ASSERT_NEAR(res, -0.78539816339, 0.00001);
}
TEST(SmartCalc, TestOperation1) {
  s21::Model model;
  std::string str = "23e+3+e+sqrt(49)+ln(5)+log(34)*111e-2";
  std::string x = "0";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  ASSERT_NEAR(res, 23013.0276613, 0.00001);
}
TEST(SmartCalc, TestFunc) {
  s21::Model model;
  std::string str = "x^2*23";
  std::string x = "7";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  EXPECT_EQ(res, 1127);
}
TEST(SmartCalc, TestFunc1) {
  s21::Model model;
  std::string str = "x*1000*23/89+(+2)";
  std::string x = "2.234";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  ASSERT_NEAR(res, 579.325842697, 0.000001);
}
TEST(SmartCalc, TestFunc2) {
  s21::Model model;
  std::string str = "-5mod2";
  std::string x = "2.234";
  model.CalculateExpression(str, x);
  double res = model.GetAnswer();
  EXPECT_EQ(res, 1);
}

TEST(SmartCalc, Error) {
  s21::Model model;
  std::string str = "ute(23)+23";
  std::string x = "2.234";
  EXPECT_THROW(model.CalculateExpression(str, x);, std::invalid_argument);
}
TEST(SmartCalc, Error1) {
  s21::Model model;
  std::string str = "";
  std::string x = "2.234";
  EXPECT_THROW(model.CalculateExpression(str, x);, std::invalid_argument);
}
TEST(SmartCalc, Error2) {
  s21::Model model;
  std::string str = ")(32-23)";
  std::string x = "2.234";
  EXPECT_THROW(model.CalculateExpression(str, x);, std::invalid_argument);
}
TEST(SmartCalc, Error3) {
  s21::Model model;
  std::string str = "45++-324";
  std::string x = "2.234";
  EXPECT_THROW(model.CalculateExpression(str, x);, std::invalid_argument);
}
TEST(SmartCalc, Error4) {
  s21::Model model;
  std::string str = "tan(43+(334*(2)";
  std::string x = "2.234";
  EXPECT_THROW(model.CalculateExpression(str, x);, std::invalid_argument);
}
TEST(SmartCalc, Error5) {
  s21::Model model;
  std::string str = "23.3mod5";
  std::string x = "2.234";
  EXPECT_THROW(model.CalculateExpression(str, x);, std::invalid_argument);
}
TEST(SmartCalc, TestMethod) {
  s21::Model model;
  std::string str = "5mod2";
  std::string x = "2.234";
  model.CalculateExpression(str, x);
  model.ModelClean();
  double res = model.GetAnswer();
  EXPECT_EQ(res, 0);
}
TEST(SmartCalc, TestCredit) {
  s21::Model model;
  std::string sum = "1000000";
  std::string rate = "5";
  std::string date = "5";
  TypeOfDate type_of_date = kYear;
  TypeOfPayment type_of_payment = kAnnuity;
  model.CalculateCredit(sum, rate, date, type_of_date, type_of_payment);
  Credit res = model.GetCredit();
  ASSERT_NEAR(res.common_payment, 1132273.80, 1);
  ASSERT_NEAR(res.sum_month, 18871.23, 1);
  ASSERT_NEAR(res.overpayment, 132273.80, 1);
}
TEST(SmartCalc, TestCredit1) {
  s21::Model model;
  std::string sum = "1000000";
  std::string rate = "5";
  std::string date = "2";
  TypeOfDate type_of_date = kMonth;
  TypeOfPayment type_of_payment = kDifferentiated;
  model.CalculateCredit(sum, rate, date, type_of_date, type_of_payment);
  Credit res = model.GetCredit();
  ASSERT_NEAR(res.common_payment, 1006250.00, 1);
  ASSERT_NEAR(res.overpayment, 6250.00, 1);
  ASSERT_NEAR(res.payment[0], 504166.67, 1);
  ASSERT_NEAR(res.payment[1], 502083.33, 1);
}
TEST(SmartCalc, TestCreditError) {
  s21::Model model;
  std::string sum = "100.00.0";
  std::string rate = "5";
  std::string date = "2";
  TypeOfDate type_of_date = kMonth;
  TypeOfPayment type_of_payment = kDifferentiated;
  EXPECT_THROW(
      model.CalculateCredit(sum, rate, date, type_of_date, type_of_payment);
      , std::invalid_argument);
}
TEST(SmartCalc, TestCreditError1) {
  s21::Model model;
  std::string sum = "100000";
  std::string rate = "500";
  std::string date = "20000";
  TypeOfDate type_of_date = kMonth;
  TypeOfPayment type_of_payment = kDifferentiated;
  EXPECT_THROW(
      model.CalculateCredit(sum, rate, date, type_of_date, type_of_payment);
      , std::invalid_argument);
}
TEST(SmartCalc, TestGraph) {
  s21::Model model;
  std::string expression = "x^2";
  model.CalculateGraph(expression, 1, -4, 4);
  Model::XYGraph res = model.GetGraph();
  size_t j = 0;
  for (int i = -4; i <= 4; ++i) {
    EXPECT_EQ(res.first[j], i);
    EXPECT_EQ(res.second[j], std::pow(i, 2));
    ++j;
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}