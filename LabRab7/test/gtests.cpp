//
// Created by Yahor on 26.11.2020.
//
#include <gtest/gtest.h>
#include "Student.h"
#include "StudentAfter1stSession.h"
#include "StudentAfter2ndSession.h"

using namespace std;

TEST(StudentDefaultConstr, IsWorking) {
  Student Razmyslovich("Gosha", 1, 1);
  ASSERT_STREQ(Razmyslovich.getName(), "Gosha");
  ASSERT_EQ(Razmyslovich.getCourse(), 1);
  ASSERT_EQ(Razmyslovich.getGroup(), 1);
}

TEST(StudentCopyConstr, IsWorking) {
  Student a("abc", 2, 13);
  Student b(a);
  ASSERT_STREQ(b.getName(), "abc");
  ASSERT_EQ(b.getCourse(), 2);
  ASSERT_EQ(b.getGroup(), 13);
  ASSERT_STREQ(a.getName(), "abc");
  ASSERT_EQ(a.getCourse(), 2);
  ASSERT_EQ(a.getGroup(), 13);
}

TEST(StudentGetMethods, AreWorking) {
  Student a("abc", 2, 13);
  ASSERT_STREQ(a.getName(), "abc");
  ASSERT_EQ(a.getCourse(), 2);
  ASSERT_EQ(a.getGroup(), 13);
  ASSERT_EQ(a.getId(), 3);
  ASSERT_EQ(a.getRecordBookNum(), 2023202);
}

TEST(StudentSetMethods, AreWorking) {
  Student a("abc", 2, 13);
  a.setName("noname");
  a.setCourse(3);
  a.setGroup(5);
  ASSERT_STREQ(a.getName(), "noname");
  ASSERT_EQ(a.getCourse(), 3);
  ASSERT_EQ(a.getGroup(), 5);
}

TEST(StudentOperatorOverload, IsWorking) {
  Student a("abc", 2, 13);
  stringstream ss;
  ss << a;
  string text, finalText;
  while (ss >> text) {
    finalText += text + " ";
  }
  ASSERT_EQ(finalText, "name - abc; course - 2; group - 13; id - 5; record book number - 2023204 ");
}

TEST(StudentAfter1stSessionConstr, IsWorking) {
  Student a("abc", 2, 13);
  int *marks = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks);
  ASSERT_EQ(a1.getMark1stSession(1), 5);
  ASSERT_EQ(a1.getMark1stSession(2), 7);
  ASSERT_EQ(a1.getMark1stSession(3), 10);
  ASSERT_EQ(a1.getMark1stSession(4), 4);
}

TEST(getMark1stSession, IsWorking) {
  Student a("abc", 2, 13);
  int *marks = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks);
  ASSERT_EQ(a1.getMark1stSession(1), 5);
}

TEST(changeMark1stSession, IsWorking) {
  Student a("abc", 2, 13);
  int *marks = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks);
  a1.changeMark1stSession(2, 10);
  ASSERT_EQ(a1.getMark1stSession(2), 10);
}

TEST(StudentAfter1stSessionOperatorOverload, IsWorking) {
  Student a("abc", 2, 13);
  int *marks = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks);
  stringstream ss;
  ss << a1;
  string text, finalText;
  while (ss >> text) {
    finalText += text + " ";
  }
  ASSERT_EQ(finalText, "name - abc; course - 2; group - 13; id - 13; record book number - 2023209; marks after 1st session - 5 7 10 4 ");
}

TEST(StudentAfter1stSessionAvarageMark, IsWorking) {
  Student a("abc", 2, 13);
  int *marks = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks);
  double avgMrk = (5.0 + 7 + 10 + 4) / 4;
  ASSERT_EQ(a1.averageMark(), avgMrk);
}

TEST(StudentAfter2ndSessionConstr, IsWorking) {
  Student a("abc", 2, 13);
  int *marks1 = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks1);
  int *marks2 = new int[5] {9, 5, 8, 8, 7};
  StudentAfter2ndSession a2(a1, marks2);
  ASSERT_EQ(a2.getMark2ndSession(1), 9);
  ASSERT_EQ(a2.getMark2ndSession(2), 5);
  ASSERT_EQ(a2.getMark2ndSession(3), 8);
  ASSERT_EQ(a2.getMark2ndSession(4), 8);
  ASSERT_EQ(a2.getMark2ndSession(5), 7);
}

TEST(getMark2ndSession, IsWorking) {
  Student a("abc", 2, 13);
  int *marks1 = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks1);
  int *marks2 = new int[5] {9, 5, 8, 8, 7};
  StudentAfter2ndSession a2(a1, marks2);
  ASSERT_EQ(a2.getMark2ndSession(1), 9);
}

TEST(changeMark2ndSession, IsWorking) {
  Student a("abc", 2, 13);
  int *marks1 = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks1);
  int *marks2 = new int[5] {9, 5, 8, 8, 7};
  StudentAfter2ndSession a2(a1, marks2);
  a2.changeMark2ndSession(2, 10);
  ASSERT_EQ(a2.getMark2ndSession(2), 10);
}

TEST(StudentAfter2ndSessionOperatorOverload, IsWorking) {
  Student a("abc", 2, 13);
  int *marks1 = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks1);
  int *marks2 = new int[5] {9, 5, 8, 8, 7};
  StudentAfter2ndSession a2(a1, marks2);
  stringstream ss;
  ss << a2;
  cout << a2 << endl;
  string text, finalText;
  while (ss >> text) {
    finalText += text + " ";
  }
  ASSERT_EQ(finalText, "name - abc; course - 2; group - 13; id - 27; record book number - 2023214; marks after 1st session - 5 7 10 4; marks after 2nd session - 9 5 8 8 7 ");
}

TEST(StudentAfter2ndSessionAvarageMark, IsWorking) {
  Student a("abc", 2, 13);
  int *marks1 = new int[4] {5, 7, 10, 4};
  StudentAfter1stSession a1(a, marks1);
  int *marks2 = new int[5] {9, 5, 8, 8, 7};
  StudentAfter2ndSession a2(a1, marks2);
  double avgMrk = (9.0 + 5 + 8 + 8 + 7 + 5 + 7 + 10 + 4) / 9;
  ASSERT_EQ(a2.averageMark(), avgMrk);
}

TEST(idAndRecordBookNum, AreUnique) {
  Student Zhora("Gosha", 1, 1);
  Student Razmyslovich("GrigoriyProkofievich", 100500, 0);
  ASSERT_NE(Zhora.getId(), Razmyslovich.getId());
}