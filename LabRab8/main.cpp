#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
  StackArray a;
  StackArray b;

  a << 5;
  a << 7;
  a.push(3);
  a << 46;
  a.push(11);
  a.pop();

  a.arrayOutput();

  cout << a[1] << endl;
  b.push(3);
  b.push(1);
  b.push(9);
  b.pop();

  b.arrayOutput();

  int q = 7;
  b >> q;
  cout << q << endl;

  a = a;

  a.arrayOutput();

  return 0;
}
