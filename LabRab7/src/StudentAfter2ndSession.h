//
// Created by Yahor on 16.12.2020.
//
#pragma once
#ifndef LABRAB7_SRC_STUDENTAFTER2NDSESSION_H_
#define LABRAB7_SRC_STUDENTAFTER2NDSESSION_H_
#include "StudentAfter1stSession.h"
#include "iostream"
class StudentAfter2ndSession : public StudentAfter1stSession {
 private:
  int *m_marks2;
 public:
  StudentAfter2ndSession (StudentAfter1stSession &, int *marks);
  int getMark2ndSession (int number);
  int* changeMark2ndSession (int positionOfMark, int mark);
  friend std::ostream &operator << (std::ostream &, StudentAfter2ndSession &);
  double averageMark () override;
};
#endif //LABRAB7_SRC_STUDENTAFTER2NDSESSION_H_
