//
// Created by Yahor on 16.12.2020.
//
#include "iostream"
#include "Student.h"

using namespace std;

int Student::countId = 0;
int Student::countRecBookNum = 2023200;

Student::Student(char* name, int course, int group) : m_id(countId), m_recordBookNum(countRecBookNum){
  countId++;
  m_name = name;
  m_course = course;
  m_group = group;
  countRecBookNum++;
}

Student::Student(const Student &studentCopy) : m_id(countId), m_recordBookNum(countRecBookNum){
  countId++;
  m_name = studentCopy.m_name;
  m_course = studentCopy.m_course;
  m_group = studentCopy.m_group;
}

void Student::setName(char* name) {
  m_name = name;
}

char* Student::getName() {
  return m_name;
};

void Student::setCourse(int course) {
  m_course = course;
}

int Student::getCourse() {
  return m_course;
}

void Student::setGroup(int group) {
  m_group = group;
}

int Student::getGroup() {
  return m_group;
}

int Student::getId() {
  return m_id;
}

int Student::getRecordBookNum() {
  return m_recordBookNum;
}

std::ostream &operator << (std::ostream &out, Student &name) {
  out << "name - " << name.m_name << "; course - " << name.m_course <<
      "; group - " << name.m_group << "; id - " << name.getId() <<
      "; record book number - " << name.getRecordBookNum();
  return out;
}

double Student::averageMark() {
  return 0;
}
/*Student::Student() : m_id(countId), m_recordBookNum(countRecBookNum){}*/
