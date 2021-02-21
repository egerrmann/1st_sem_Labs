//
// Created by Yahor on 16.12.2020.
//
#include "iostream"
#include "StudentAfter1stSession.h"

using namespace std;

StudentAfter1stSession::StudentAfter1stSession(Student &name, int *marks) : Student(name){
  m_marks1 = marks;
}

int StudentAfter1stSession::getMark1stSession (int number) {
  if (number <= 4 && number >= 1) {
    return m_marks1[number - 1];
  }
  else
    cout << "There is no any mark on this position." << endl;
}

int* StudentAfter1stSession::changeMark1stSession(int positionOfMark, int mark) {
  m_marks1[positionOfMark - 1] = mark;
return m_marks1;
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