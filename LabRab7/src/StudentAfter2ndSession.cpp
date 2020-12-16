#include "StudentAfter2ndSession.h"
//
// Created by Yahor on 16.12.2020.
//

using namespace std;

StudentAfter2ndSession::StudentAfter2ndSession (StudentAfter1stSession &name, int *marks) : StudentAfter1stSession(name) {
  m_marks2 = marks;
}

void StudentAfter2ndSession::getMark2ndSession(int number) {
  if (number <= 5 && number >= 1) {
    cout << m_marks2[number - 1] << endl;
  }
  else
    cout << "There is no any mark on this position." << endl;
}

void  StudentAfter2ndSession::changeMark2ndSession(int markToChange) {
  cout << "Insert mark that you want to put instead of " << m_marks2[markToChange - 1] << endl;
  int a;
  cin >> a;
  m_marks2[markToChange - 1] = a;
  cout << "Marks after 2nd session after change:" << endl;
  for (int i = 0; i < 5; ++i) {
    cout << m_marks2[i] << "   ";
  }
  cout << endl;
}

std::ostream &operator << (std::ostream &out, StudentAfter2ndSession &name) {
  out << "name - " << name.m_name << "; course - " << name.m_course <<
      "; group - " << name.m_group << "; id - " << name.getId() <<
      "; record book number - " << name.getRecordBookNum() << "; marks after 1st session -";
  for (int i = 0; i < 4; ++i) {
    out << " " << name.m_marks1[i];
  }
  out << "; marks after 2nd session - ";
  for (int i = 0; i < 5; ++i) {
    out << " " << name.m_marks2[i];
  }
  return out;
}

double StudentAfter2ndSession::averageMark() {
  double avgMark, sum = 0;
  for (int i = 0; i < 4; ++i) {
    sum += m_marks1[i];
  }
  for (int i = 0; i < 5; ++i) {
    sum += m_marks2[i];
  }
  avgMark = sum / 9;
  return avgMark;
}