//
// Created by Yahor on 16.12.2020.
//
#include "iostream"
#include "StudentAfter1stSession.h"

using namespace std;

StudentAfter1stSession::StudentAfter1stSession(Student &name, int *marks) : Student(name){
  m_marks1 = marks;
}

void StudentAfter1stSession::getMark1stSession (int number) {
  if (number <= 4 && number >= 1) {
    cout << m_marks1[number - 1] << endl;
  }
  else
    cout << "There is no any mark on this position." << endl;
}

void StudentAfter1stSession::changeMark1stSession(int markToChange) {
  cout << "Insert mark that you want to put instead of " << m_marks1[markToChange - 1] << endl;
  int a;
  cin >> a;
  m_marks1[markToChange - 1] = a;
  cout << "Marks after 1st session after change:" << endl;
  for (int i = 0; i < 4; ++i) {
    cout << m_marks1[i] << "   ";
  }
  cout << endl;
};

std::ostream &operator << (std::ostream &out, StudentAfter1stSession &name) {
  out << "name - " << name.m_name << "; course - " << name.m_course <<
      "; group - " << name.m_group << "; id - " << name.getId() <<
      "; record book number - " << name.getRecordBookNum() << "; marks after 1st session -";
  for (int i = 0; i < 4; ++i) {
    out << " " << name.m_marks1[i];
  }
  return out;
}

double StudentAfter1stSession::averageMark() {
  double avgMark, sum = 0;
  for (int i = 0; i < 4; ++i) {
    sum += m_marks1[i];
  }
  avgMark = sum / 4;
  return avgMark;
}