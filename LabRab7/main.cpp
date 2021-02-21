#include <iostream>
#include "Student.h"
#include "StudentAfter1stSession.h"
#include "StudentAfter2ndSession.h"

using namespace std;


int main() {
    Student Egor ("Egor", 1, 4);
    Student Chester ("Chester", 4, 1);
    Egor.getGroup();
    Egor.setGroup();
    Egor.getGroup();
    int *marks1 = new int[4] {7, 6, 8, 10};
    cout << "What position of marks after 1st session do you want to know?" << endl;
    int markPosition;
    cin >> markPosition;
    StudentAfter1stSession Egor1 (Egor, marks1);
    Egor1.getMark1stSession(markPosition);
    cout << "What position of mark do you want to change?" << endl;
    cin >> markPosition;
    Egor1.changeMark1stSession(markPosition);
    int *marks2 = new int[5] {7, 5, 8, 8, 6};
    cout << "What position of marks after 2nd session do you want to know?" << endl;
    cin >> markPosition;
    StudentAfter2ndSession Egor2 (Egor1, marks2);
    Egor2.getMark2ndSession(markPosition);
    cout << "What position of mark do you want to change?" << endl;
    cin >> markPosition;
    Egor2.changeMark2ndSession(markPosition);
    cout << Egor << endl;
    cout << Egor1 << endl;
    cout << Egor2 << endl;
    cout << Egor1.averageMark() << endl;
    cout << Egor2.averageMark() << endl;
    return 0;
}
