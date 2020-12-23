#include <iostream>
#include "ProperFraction.h"


using namespace std;

int main() {
    int numerator1, denominator1;
    cout << "Insert numerator and denominator" << endl;
    cin >> numerator1 >> denominator1;
    ProperFraction drob (numerator1, denominator1);
    cout << "Insert data of the second fraction: " << endl;
    cout << "numerator =" << endl;
    int num1, denom1;
    cin >> num1;
    cout << "denominator =" << endl;
    cin >> denom1;
    ProperFraction drob2 (num1, denom1);
    drob.addition(drob2);
    return 0;
}
