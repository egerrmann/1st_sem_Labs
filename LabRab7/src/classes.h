//
// Created by Yahor on 12.11.2020.
//

#ifndef LABRAB7_CLASSES_H
#define LABRAB7_CLASSES_H
#include <iostream>
#pragma once

using namespace std;

class Student {
protected:
    char* m_name;
    int m_course;
    int m_group;
private:
    int m_id;
    int m_recordBookNum;
public:
    static int countId;
    static int countRecBookNum;
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
};

class StudentAfter1stSession : public Student {
protected:
    int *m_marks1;
public:
    StudentAfter1stSession (Student &, int *marks);
    void getMark1stSession (int number);
    void changeMark1stSession (int markToChange);
    friend std::ostream &operator << (std::ostream &, StudentAfter1stSession &);
    virtual double averageMark ();
};

class StudentAfter2ndSession : public StudentAfter1stSession {
private:
    int *m_marks2;
protected:
public:
    StudentAfter2ndSession (StudentAfter1stSession &, int *marks);
    void getMark2ndSession (int number);
    void changeMark2ndSession (int markToChange);
    friend std::ostream &operator << (std::ostream &, StudentAfter2ndSession &);
    double averageMark () override;
};

#endif //LABRAB7_CLASSES_H
