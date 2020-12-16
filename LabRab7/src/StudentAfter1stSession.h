//
// Created by Yahor on 16.12.2020.
//
#pragma once
#ifndef LABRAB7_SRC_STUDENTAFTER1STSESSION_H_
#define LABRAB7_SRC_STUDENTAFTER1STSESSION_H_
#include "Student.h"
#include <iostream>
class StudentAfter1stSession : public Student {
 protected:
  int *m_marks1;
 public:
  StudentAfter1stSession (Student &, int *marks);
  void getMark1stSession (int number);
  void changeMark1stSession (int markToChange);
  friend std::ostream &operator << (std::ostream &, StudentAfter1stSession &);
  double averageMark() override;
};
#endif //LABRAB7_SRC_STUDENTAFTER1STSESSION_H_
