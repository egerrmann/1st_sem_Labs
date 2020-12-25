#pragma once
#ifndef LABRAB8__1___CALCULATOR_H_
#define LABRAB8__1___CALCULATOR_H_
#include <string>
#include "Stack.h"
#include "cmath"

using namespace std;
class Calculator {
 public:
  int operatorPriority (char);
  string rpn();
  int count(string);
};

#endif //LABRAB8__1___CALCULATOR_H_