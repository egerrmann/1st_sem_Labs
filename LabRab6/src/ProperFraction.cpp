#include <iostream>
#include <cmath>
#include "ProperFraction.h"

//
// Created by Yahor on 31.10.2020.
//
using namespace std;

ProperFraction::ProperFraction() {
    exit(1);
}

int ProperFraction::getNumerator () {
    return numerator;
}
int ProperFraction::getDenominator () {
    return denominator;
}
ProperFraction::ProperFraction(const ProperFraction &fraction) {
    numerator = fraction.numerator,
    denominator = fraction.denominator;
}
ProperFraction::ProperFraction(int numeratorConstr, int denominatorConstr) {
    numerator = numeratorConstr;
    denominator = denominatorConstr;
};
void ProperFraction::fractionReduction () {
    int divider = fabs(numerator);
    while (divider >= 2) {
        if (numerator % divider == 0 && denominator % divider == 0) {
            numerator /= divider;
            denominator /= divider;
        }
        else
            divider--;
    }
}
void ProperFraction::addition (const ProperFraction& frac) {
    int commonDenominator = frac.denominator * denominator;
    int numeratorAdd1 = frac.numerator * denominator;
    int numeratorAdd2 = numerator * frac.denominator;
    int sum = numeratorAdd1 + numeratorAdd2;
    numerator = sum;
    denominator = commonDenominator;
    fractionReduction();
    fraction();
}

void ProperFraction::multiply (const ProperFraction& frac) {
    int numeratorMult = frac.numerator * numerator;
    int denominatorMult = frac.denominator * denominator;
    numerator = numeratorMult;
    denominator = denominatorMult;
    fractionReduction();
    fraction();
}

void ProperFraction::division (const ProperFraction& frac) {
    if (frac.numerator == 0) {
        cout << "ERROR";
    }
    numerator *= frac.denominator;
    denominator *= frac.numerator;
    fractionReduction();
    fraction();
}
void ProperFraction::fraction() {
    if (denominator == 0) {
        cout << "Error. Denominator can't be equal to 0.";
        return;
    }
    if (numerator == 0) {
        cout << "Error. In proper fraction numerator can't be equal to 0.";
        return;
    }
    if (fabs(numerator) < fabs(denominator)) {
        if (denominator > 0 && numerator > 0) {
            cout << numerator << "/" << denominator;
        }
        if (denominator < 0 && numerator > 0) {
            cout << "-" << numerator << "/" << (-1) * denominator;
        }
        if (denominator < 0 && numerator < 0) {
            cout << (-1) * numerator << "/" << (-1) * denominator;
        }
        if (denominator > 0 && numerator < 0) {
            cout << "-" << (-1) * numerator << "/" << denominator;
        }
    } else {
        cout << "Error. In proper fraction a module of numerator should be less than module of denominator.";
        return;
    }
}