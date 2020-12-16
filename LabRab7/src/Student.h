//
// Created by Yahor on 16.12.2020.
//
#pragma once
#ifndef LABRAB7_SRC_STUDENT_H_
#define LABRAB7_SRC_STUDENT_H_
#include <ostream>
class Student {
 protected:
  char* m_name;
  int m_course;
  int m_group;
  static int countId;
  static int countRecBookNum;
 private:
  const int m_id;
  const int m_recordBookNum;
 public:
  Student(char *name, int course, int group);
  Student(const Student&);
  Student();
  void setName();
  char* getName();
  void setCourse();
  int getCourse();
  void setGroup();
  int getGroup();
  int getId();
  int getRecordBookNum();
  friend std::ostream &operator << (std::ostream &, Student &);
  virtual double averageMark();
};

#endif //LABRAB7_SRC_STUDENT_H_
