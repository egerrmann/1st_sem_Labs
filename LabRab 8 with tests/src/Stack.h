#pragma once
#ifndef LABRAB8__1__STACK_H
#define LABRAB8__1__STACK_H

#include "iostream"

using namespace std;

class StackArray {
 private:
  double *m_array;
  int m_size;
  int m_top;
  int arrayCapacity = 1;
 public:
  StackArray();
  ~StackArray();
  double* getArray() const;
  int getTopPosition() const;
  double getElement(int) const;
  double peek(); //get-method
  double size() const; // get-method
  void push(double);
  void arrayOutput();
  double pop();
  bool isEmpty() const;
  bool isFull() const;
  void operator << (double);
  double operator >> (double&);
  StackArray& operator = (StackArray const &);
  bool operator < (StackArray const &) const;
  bool operator > (StackArray const &) const;
  bool operator == (StackArray const &) const;
  bool operator != (StackArray const &) const;
  double &operator [] (int);
};


#endif //LABRAB8__1__STACK_H