//
// Created by Yahor on 26.11.2020.
//
#include <gtest/gtest.h>
#include "Student.h"
#include "StudentAfter1stSession.h"
#include "StudentAfter2ndSession.h"

using namespace std;

int course, group;
char *name;

TEST(GetCourse, DoesItWork) {
    string name1;
    cin >> course >> group;
    cin >> name1;
    name = new char[name1.size()];
    for (int i = 0; i < name1.size(); ++i) {
        name[i] = name1[i];
        if (i == name1.size() - 1)
            name1[i + 1] = '\0';
    }
    Student Razmyslovich(name, course, group);
    ASSERT_EQ(Razmyslovich.getCourse(), course);
}

TEST(SetCourse, Check) {
    Student Razmyslovich(name, course, group);
    Razmyslovich.setCourse();
    ASSERT_NE(course, Razmyslovich.getCourse());
}

TEST(IdCompare, TwoStudentsCompareId) {
    Student Razmyslovich(name, course, group);
    Student Bulatov("Bulatov", 100, 1);
    ASSERT_NE(Razmyslovich.getId(), Bulatov.getId());
}