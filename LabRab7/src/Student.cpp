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

void Student::setName() {
  string name;
  cout << "Insert a name:" << endl;
  cin >> name;
  char *name1 = new char[name.size()];
  for (int i = 0; i < name.size(); ++i) {
    name1[i] = name[i];
    if (i == name.size() - 1)
      name1[i + 1] = '\0';
  }
  m_name = name1;
}

char* Student::getName() {
  return m_name;
};

void Student::setCourse() {
  int course;
  cout << "Insert a course:" << endl;
  cin >> course;
  m_course = course;
}

int Student::getCourse() {
  return m_course;
}

void Student::setGroup() {
  int group;
  cout << "Insert a group:" << endl;
  cin >> group;
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
