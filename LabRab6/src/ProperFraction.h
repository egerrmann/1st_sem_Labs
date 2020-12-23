//
// Created by Yahor on 31.10.2020.
//
#ifndef LABRAB6_PROPERFRACTION_H
#define LABRAB6_PROPERFRACTION_H

class ProperFraction {
private:
    ProperFraction();
public:
    int numerator, denominator;
    int getNumerator ();
    int getDenominator ();
    ProperFraction(const ProperFraction &fraction);
    ProperFraction(int numeratorConstr, int denominatorConstr);
    void fractionReduction ();
    void addition (const ProperFraction& frac);
    void multiply (const ProperFraction& frac);
    void division (const ProperFraction& frac);
    void fraction();
};
#endif //LABRAB6_PROPERFRACTION_H
