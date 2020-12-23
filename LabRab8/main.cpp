#include <iostream>
#include "Stack.h"
#include "calculator.h"

using namespace std;

int main() {
  Calculator abc;
  abc.count(abc.rpn());
  return 0;
}
