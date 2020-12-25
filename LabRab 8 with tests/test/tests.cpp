#include <gtest/gtest.h>
#include "Stack.h"
#include "calculator.h"
#include "sstream"

using namespace std;

TEST(StackArrayConstr, IsWorking) {
  StackArray a;
  ASSERT_EQ(a.getTopPosition(), -1);
  ASSERT_EQ(a.size(), 0);
}

TEST(StackGetMethodsAndStackPush, AreWorking) {
  StackArray a;
  a.push(1.1);
  ASSERT_EQ(a.size(), 1);
  ASSERT_EQ(a.getArray()[0], 1.1);
  ASSERT_EQ(a.getTopPosition(), 0);
  ASSERT_EQ(a.peek(), 1.1);
  ASSERT_EQ(a.getElement(1), 1.1);
}

TEST(StackArrayOutput, IsWorking) {
  StackArray a;
  a.push(1.1);
  a.push(2);
  stringstream ss;
  for (int kI = 0; kI < a.size(); ++kI) {
    ss << a.getArray()[kI] << "   ";
  }
  string text, finalText;
  while (ss >> text) {
    finalText += text + "   ";
  }
  ASSERT_EQ(finalText, "1.1   2   ");
}

TEST(StackArrayPop, IsWorking) {
  StackArray a;
  a.push(1.1);
  a.push(2);
  a.pop();
  ASSERT_EQ(a.size(), 1);
  ASSERT_EQ(a.getTopPosition(), 0);
  ASSERT_EQ(a.getElement(1), 1.1);
}

TEST(StackArrayIsEmpty, ReturnsRightValue) {
  StackArray a;
  a.push(1.1);
  ASSERT_NE(a.getTopPosition(), -1);
  a.pop();
  ASSERT_EQ(a.getTopPosition(), -1);
}

TEST(StackArrayIsFull, ReturnsRightValue) {
  StackArray a;
  a.push(1.1);
  ASSERT_EQ(a.getTopPosition(), a.size() - 1);
}

TEST(StackArrayPushOperator, IsWorking) {
  StackArray a;
  a << 1.1;
  ASSERT_EQ(a.getElement(1), 1.1);
}

TEST(StackArrayPopOperator, IsWorking) {
  StackArray a;
  a << 1.1;
  double temp = 1.1;
  a >> temp;
  ASSERT_EQ(a.size(), 0);
}

TEST(StackArrayEqualityOperator, IsWorking) {
  StackArray a;
  a << 1.1;
  StackArray b;
  b << 11;
  b << 3.6;
  a = b;
  ASSERT_EQ(a.size(), 2);
  ASSERT_EQ(a.getElement(1), 11);
  ASSERT_EQ(a.getElement(2), 3.6);
}

TEST(StackArrayLessOperator, IsWorking) {
  StackArray a;
  a << 1.1;
  StackArray b;
  b << 11;
  b << 3.6;
  ASSERT_LT(a, b);
}

TEST(StackArrayMoreOperator, IsWorking) {
  StackArray a;
  a << 1.1;
  StackArray b;
  b << 11;
  b << 3.6;
  ASSERT_GT(b, a);
}

TEST(StackArrayLogicalEqualityAndInequalityOperators, AreWorking) {
  StackArray a;
  a << 1.1;
  StackArray b;
  b << 11;
  ASSERT_TRUE(a == b);
  b << 3.6;
  ASSERT_TRUE(a != b);
}

TEST(StackArrayIndex, IsWorking) {
  StackArray a;
  a << 11;
  a << 3.6;
  ASSERT_EQ(a[0], 11);
  ASSERT_EQ(a[1], 3.6);
}

TEST(CalculatorOperatorPriority, IsWorking) {
  Calculator abc;
  ASSERT_EQ(abc.operatorPriority('('), 0);
  ASSERT_EQ(abc.operatorPriority(')'), 0);
  ASSERT_EQ(abc.operatorPriority('+'), 1);
  ASSERT_EQ(abc.operatorPriority('-'), 1);
  ASSERT_EQ(abc.operatorPriority('*'), 2);
  ASSERT_EQ(abc.operatorPriority('/'), 2);
}

TEST(CalculatorRPN, IsWorking) {
  Calculator abc;
  ASSERT_EQ(abc.rpn(), "577/+");
}

TEST(CalculatorCount, IsWorking) {
  Calculator abc;
  ASSERT_EQ(abc.count(abc.rpn()), 6);
}