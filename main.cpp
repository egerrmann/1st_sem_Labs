//variant 9
#include <iostream>
#include <cstdlib>

using namespace std;

double min(double a, double b) {
    if (a > b)
        return b;
    if (b > a)
        return a;
    if (a == b)
        return a;
}

int main() {
    int switcher;
    double P;
    cout << "Insert 1, if you want to work with array of prepared numbers. Insert 2, if you want to work with array of random numbers." << endl;
    cin >> switcher;
    if (switcher != 1 && switcher != 2) {
        cout << "ERROR";
        return 0;
    }
    switch (switcher) {
        case 1: {
            cout << "Insert number P: " << endl;
            cin >> P;
            double array1[10] = {5.7, 7.26, 14.2, -3.9, 8.79, -3.9, 15.5, 15.92, 11.34, 5.67};
            int nMax;
            cout << "Insert amount of numbers n from array, n > 0 and n < 11:";
            cin >> nMax;
            int amount = 0;
            for (int i = 0; i < nMax; ++i) {
                if (array1[i] < P) {
                    ++amount;
                }
            }
            double minNum = array1[0], min1;
            for (int i = 1; i < nMax; ++i) {
                min1 = min(array1[i], array1[i - 1]);
                if (min1 < minNum)
                    minNum = min1;
            }
            cout << "Minimal element is " << minNum;
            cout << endl;
            int s = 0;
            for (int i = nMax - 1; i >= 0; --i) {
                if (array1[i] == minNum) {
                    for (int l = i + 1; l < nMax; ++l) {
                        s += (int) array1[l];
                    }
                    break;
                }
            }
            cout << "The sum of int elements is " << s << endl;
            int exchanged = 0, norm = 0;
            for (int i = 0; i < nMax; ++i) {
                if (array1[i] < P)
                    norm += 1;
                else
                    break;
            }
            for (int i = norm; i < nMax; ++i) {
                if (array1[i] < P) {
                    for (int l = i; l > (exchanged + norm); --l) {
                        swap(array1[l], array1[l - 1]);
                    }
                    ++exchanged;
                }
            }
            /* int lessP = 0;
             for (int i = 0; i < nMax; ++i) {
                 if (array1[i] < P)
                     lessP += 1;
             }
             int a = 0, z;
                 for (int i = 0; i < nMax; ++i) {
                     if (array1[i] >= P) {
                         for (int l = i; l < nMax; ++l) {
                             if (array1[l] < P) {
                                 swap(array1[i], array1[l]);
                                 break;
                             }

                     }
                     for (z = 0; z < nMax; ++z) {
                         if (array1[z] < P)
                             a += 1;
                         if (z == lessP - 1 && a == lessP)
                             goto here;

                     }
                 }
            here:*/
            cout << "A new array is ";
            for (int i = 0; i < nMax; ++i) {
                cout << array1[i] << "   ";
            }
            return 0;
        }
        case 2: {
            cout << "Insert number P: " << endl;
            cin >> P;
            cout << "A new random array: ";
            double array2[10];
            for (int i = 0; i < 10; i++) {
                array2[i] = rand() % 50 - 25;
                cout << array2[i] << "   ";
            }
            cout << endl;
            int nMax1;
            cout << "Insert amount of numbers n from array, n > 0 and n < 11:";
            cin >> nMax1;
            int amount1 = 0;
            for (int i = 0; i < nMax1; ++i) {
                if (array2[i] < P) {
                    ++amount1;
                }
            }
            double minNum1 = array2[0], min2;
            for (int i = 1; i < nMax1; ++i) {
                min2 = min(array2[i], array2[i - 1]);
                if (min2 < minNum1)
                    minNum1 = min2;
            }
            cout << "Minimal element is " << minNum1;
            cout << endl;
            int s1 = 0;
            for (int i = nMax1 - 1; i >= 0; --i) {
                if (array2[i] == minNum1) {
                    for (int l = i + 1; l < nMax1; ++l) {
                        s1 += (int) array2[l];
                    }
                    break;
                }
            }
            cout << "Sum of array elements = " << s1 << endl;
            int exchanged1 = 0, norm1 = 0;
            for (int i = 0; i < nMax1; ++i) {
                if (array2[i] < P)
                    norm1 += 1;
                else
                    break;
            }
            for (int i = norm1; i < nMax1; ++i) {
                if (array2[i] < P) {
                    for (int l = i; l > (exchanged1 + norm1); --l) {
                        swap(array2[l], array2[l - 1]);
                    }
                    ++exchanged1;
                }
            }
            cout << "A new array is ";
            for (int i = 0; i < nMax1; ++i) {
                cout << array2[i] << "   ";
            }
            return 0;
        }
    }
}
