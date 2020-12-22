//
// Created by Yahor on 26.11.2020.
//
#include "iostream"
#include "cmath"
#include <gtest/gtest.h>
#include "ProperFraction.h"

using namespace std;

TEST(FractionOutput, DenomIsEqual0) {
  ASSERT_THROW({ProperFraction drob(5, 0);}, invalid_argument);
}

TEST(Fraction, IsProper) {
  ProperFraction drob(-1, 5);
  ASSERT_LT(fabs(drob.getNumerator()), fabs(drob.getDenominator()));
}

TEST(Fraction, IsNotProper) {
  ProperFraction drob1(5, 4);
  ProperFraction drob2(5, 5);
  ASSERT_GT(fabs(drob1.getNumerator()), fabs(drob1.getDenominator()));
  ASSERT_EQ(fabs(drob2.getNumerator()), fabs(drob2.getDenominator()));
}

TEST(GetNumeratorFunc, IsWorking) {
  ProperFraction drob(2, 5);
  ASSERT_EQ(drob.getNumerator(), 2);
}

TEST(GetDenominatorFunc, IsWorking) {
  ProperFraction drob(2, 5);
  ASSERT_EQ(drob.getDenominator(), 5);
}

TEST(ProperFractionCopyConstructor, IsWorking) {
  ProperFraction drob1(2, 5);
  ProperFraction drob2(drob1);
  ASSERT_EQ(drob1.getNumerator(), drob2.getNumerator());
  ASSERT_EQ(drob1.getDenominator(), drob2.getDenominator());
}

TEST(ProperFractionDefaultConstructor, IsWorking) {
  ProperFraction drob(2, 5);
  ASSERT_EQ(drob.getNumerator(), 2);
  ASSERT_EQ(drob.getDenominator(), 5);
}

TEST(FractionReduction, IsWorking) {
  ProperFraction drob(5, 10);
  drob.fractionReduction();
  ASSERT_EQ(drob.getNumerator(), 1);
  ASSERT_EQ(drob.getDenominator(), 2);
}

TEST(FractionReduction, FractionIsNonReductional) {
  ProperFraction drob(11, 12);
  drob.fractionReduction();
  ASSERT_EQ(drob.getNumerator(), 11);
  ASSERT_EQ(drob.getDenominator(), 12);
}

TEST(AddingFunc, IsWorking) {
  ProperFraction drob1(2, 5);
  ProperFraction drob2(3, 6);
  drob1.addition(drob2);
  ASSERT_EQ(drob1.getNumerator(), 9);
  ASSERT_EQ(drob1.getDenominator(), 10);
}

TEST(AddingFunc, CheckingForReduction) {
  ProperFraction drob1(1, 2);
  ProperFraction drob2(1, 2);
  drob1.addition(drob2);
  ASSERT_EQ(drob1.getNumerator(), 1);
  ASSERT_EQ(drob1.getDenominator(), 1);
}

TEST(MultiplyFunc, IsWorking) {
  ProperFraction drob1(2, 5);
  ProperFraction drob2(3, 6);
  drob1.multiply(drob2);
  ASSERT_EQ(drob1.getNumerator(), 1);
  ASSERT_EQ(drob1.getDenominator(), 5);
}

TEST(DivisionFunc, IsWorking) {
  ProperFraction drob1(2, 5);
  ProperFraction drob2(3, 6);
  drob1.division(drob2);
  ASSERT_EQ(drob1.getNumerator(), 4);
  ASSERT_EQ(drob1.getDenominator(), 5);
}

