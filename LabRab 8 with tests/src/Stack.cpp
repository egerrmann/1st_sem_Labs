//
// Created by Yahor on 25.12.2020.
//
#include "iostream"
#include "Stack.h"
using namespace std;

StackArray::StackArray() {
  m_array = new double [arrayCapacity];
  m_size = 0;
  m_top = -1;
}

StackArray::~StackArray() {
  delete [] m_array;
}

double * StackArray::getArray() const {
  return m_array;
}

int StackArray::getTopPosition() const {
  return m_top;
}

double StackArray::getElement(int position) const {
  return m_array[position - 1];
}

double StackArray::peek() {
  if (!isEmpty())
    return m_array[m_top];
  else
    exit(EXIT_FAILURE);
}

double StackArray::size() const {
  return m_top + 1;
}

void StackArray::push(double element) {
  m_size++;
  if (m_size > arrayCapacity)
    arrayCapacity *= 2;
  //cout << "Inserting " << element << endl;
  m_top++;
  m_array[m_top] = element;
}

void StackArray::arrayOutput() {
  for (int kI = 0; kI < m_size; ++kI) {
    cout << m_array[kI] << "   ";
  }
  cout << "\n";
}

double StackArray::pop() {
  m_size--;
  if (isEmpty())
  {
    cout << "Stack is empty" << endl;
    exit(EXIT_FAILURE);
  }
  //cout << "Removing " << peek() << endl;
  return m_array[m_top--];
}

bool StackArray::isEmpty() const {
  return m_top == -1;
}

bool StackArray::isFull() const {
  return m_top == m_size - 1;
}

void StackArray::operator << (double element) {
  push(element);
}

double StackArray::operator >> (double &a) {
  a = pop();
  return a;
}

StackArray& StackArray::operator = (StackArray const &second) {
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

bool StackArray::operator < (StackArray const &second) const {
  if (this->m_size < second.m_size)
    return true;
  else
    return false;
}

bool StackArray::operator > (StackArray const &second) const {
  if (this->m_size > second.m_size)
    return true;
  else
    return false;
}

bool StackArray::operator == (StackArray const &second) const {
  if (this->m_size == second.m_size)
    return true;
  else
    return false;
}

bool StackArray::operator != (StackArray const &second) const {
  if (this->m_size != second.m_size)
    return true;
  else
    return false;
}

double &StackArray::operator [] (int n) {
  if (n < this->m_size || n >= 0) {
    return this->m_array[n];
  } else {
    cout << "n is invalid";
    exit(EXIT_FAILURE);
  }
}