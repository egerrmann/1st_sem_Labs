//
// Created by Yahor on 12.11.2020.
//
#include "classes.h"
#include "iostream"

int Student::countId = 0;
int Student::countRecBookNum = 2023200;

Student::Student(char* name, int course, int group) {
    countId++;
    m_id = countId;
    m_name = name;
    m_course = course;
    m_group = group;
    countRecBookNum++;
    m_recordBookNum = countRecBookNum;
}

Student::Student(const Student &studentCopy) {
    countId++;
    m_id = countId;
    m_name = studentCopy.m_name;
    m_course = studentCopy.m_course;
    m_group = studentCopy.m_group;
    m_recordBookNum = studentCopy.m_recordBookNum;
}

Student::Student() {
    std::cout << "There are no any parameters";
    exit(1);
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




