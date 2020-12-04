#ifndef LABRAB8__1__STACK_H
#define LABRAB8__1__STACK_H

#include "iostream"

using namespace std;

class StackArray {

 private:
  int *m_array;
  int m_size;
  int m_top;

 public:
  StackArray() {
    m_array = new int[0];
    m_size = 0;
    m_top = -1;
  }

  ~StackArray() {
    delete [] m_array;
  }

  void push(int element) {
    m_size++;
    cout << "Inserting " << element << endl;
    m_top++;
    m_array[m_top] = element;
  }

  void arrayOutput() {
    for (int kI = 0; kI < m_size; ++kI) {
      cout << m_array[kI] << "   ";
    }
    cout << "\n";
  };

  int pop() {
    m_size--;
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      exit(EXIT_FAILURE);
    }
    cout << "Removing " << peek() << endl;
    m_top--;
    return m_array[m_top];
  }

  int peek() {
    if (!isEmpty())
      return m_array[m_top];
    else
      exit(EXIT_FAILURE);
  }

  int size() {
    return m_top + 1;
  }

  bool isEmpty() {
    return m_top == -1;
  }

  bool isFull() {
    return m_top == m_size - 1;
  }

  void operator << (int element) {
    push(element);
  }

  void operator >> (int &a) {
    a = pop();
  }

  StackArray& operator = (StackArray const &second) {
    this->m_size = second.m_size;
    delete [] this->m_array;
    this->m_array = new int [second.m_size];
    for (int i = 0; i < second.m_size; i++) {
      this->m_array[i] = second.m_array[i];
    }
    this->m_top = second.m_top;
    return *this;
  }

  bool operator < (StackArray const &second) {
    if (this->m_size < second.m_size)
      return true;
    else
      return false;
  }

  bool operator > (StackArray const &second) {
    if (this->m_size > second.m_size)
      return true;
    else
      return false;
  }

  bool operator == (StackArray const &second) {
    if (this->m_size == second.m_size)
      return true;
    else
      return false;
  }

  bool operator != (StackArray const &second) {
    if (this->m_size != second.m_size)
      return true;
    else
      return false;
  }

  int &operator [] (int n) {
    if (n < this->m_size || n >= 0) {
      return this->m_array[n];
    } else {
      cout << "n is invalid";
      exit(EXIT_FAILURE);
    }
  }
};


#endif //LABRAB8__1__STACK_H