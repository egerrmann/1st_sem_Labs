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
  StackArray() {
    m_array = new double [arrayCapacity];
    m_size = 0;
    m_top = -1;
  }

  ~StackArray() {
    delete [] m_array;
  }

  void push(double element) {
    m_size++;
    if (m_size > arrayCapacity)
      arrayCapacity *= 2;
    //cout << "Inserting " << element << endl;
    m_top++;
    m_array[m_top] = element;
  }

  void arrayOutput() {
    for (int kI = 0; kI < m_size; ++kI) {
      cout << m_array[kI] << "   ";
    }
    cout << "\n";
  };

  double pop() {
    m_size--;
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      exit(EXIT_FAILURE);
    }
    //cout << "Removing " << peek() << endl;
    return m_array[m_top--];
  }

  double peek() {
    if (!isEmpty())
      return m_array[m_top];
    else
      exit(EXIT_FAILURE);
  }

  double size() const {
    return m_top + 1;
  }

  bool isEmpty() const {
    return m_top == -1;
  }

  bool isFull() const {
    return m_top == m_size - 1;
  }

  void operator << (int element) {
    push(element);
  }

  double operator >> (double &a) {
    a = pop();
    return a;
  }

  StackArray& operator = (StackArray const &second) {
    if (*this == second)
      return *this;
    else {
    this->m_size = second.m_size;
      delete[] this->m_array;
      this->m_array = new double [second.m_size];
      for (int i = 0; i < second.m_size; i++) {
        this->m_array[i] = second.m_array[i];
      }
      this->m_top = second.m_top;
      return *this;
    }
  }

  bool operator < (StackArray const &second) const {
    if (this->m_size < second.m_size)
      return true;
    else
      return false;
  }

  bool operator > (StackArray const &second) const {
    if (this->m_size > second.m_size)
      return true;
    else
      return false;
  }

  bool operator == (StackArray const &second) const {
    if (this->m_size == second.m_size)
      return true;
    else
      return false;
  }

  bool operator != (StackArray const &second) const {
    if (this->m_size != second.m_size)
      return true;
    else
      return false;
  }

  double &operator [] (int n) {
    if (n < this->m_size || n >= 0) {
      return this->m_array[n];
    } else {
      cout << "n is invalid";
      exit(EXIT_FAILURE);
    }
  }
};


#endif //LABRAB8__1__STACK_H