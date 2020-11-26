//
// Created by Yahor on 26.11.2020.
//
#include "iostream"
#include "cmath"
#include <gtest/gtest.h>
#include "ProperFraction.h"

using namespace std;

int num, denom;

TEST(DenomIsEq0, IsEqual0) {
    cin >> num >> denom;
    ProperFraction drob(num, denom);
    ASSERT_NE(drob.getDenominator(), 0);
}

TEST(FractionIsProper, ProperCheck) {
    ProperFraction drob(num, denom);
    ASSERT_LT(fabs(drob.getNumerator()), fabs(drob.getDenominator()));
}

TEST(GetDenominator, DoesItWork) {
    ProperFraction drob(num, denom);
    ASSERT_EQ(drob.getDenominator(), denom);
}

TEST(GetNumerator, DoesItWork) {
    ProperFraction drob(num, denom);
    ASSERT_EQ(drob.getNumerator(), num);
}

TEST(Copy, Test) {
    ProperFraction drob(num, denom);
    ProperFraction drobCopy(drob);
    ASSERT_EQ(drob.getNumerator(), drobCopy.getNumerator());
    ASSERT_EQ(drob.getDenominator(), drobCopy.getDenominator());
}