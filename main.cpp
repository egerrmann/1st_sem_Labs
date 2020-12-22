//variant 9
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand( time( 0 ) );
    int switcher1;
    double P;
    cout << "Insert 1, if you want to work with array of prepared numbers. Insert 2, if you want to work with array of random numbers";
    cin >> switcher1;
    if (switcher1 != 1 && switcher1 != 2) {
        cout << "ERROR";
        return 0;
    }
    cout << "Insert number P: " << endl;
    cin >> P;
    double array[10] = {5.7, 7.26, 14.2, -3.9, 8.79, -3.9, 15.5, 15.92, 11.34, 5.67};
    switch (switcher1) {
        case 1: {
            break;
        }
        case 2: {
            for (int i = 0; i < 10; i++) {
                array[i] = rand() % 50 - 25;
                cout << array[i] << "   ";
            }
            cout << endl;
            break;
        }
    }
    int nMax;
    cout << "Insert amount of numbers n from array, n > 0 and n < 11:";
    cin >> nMax;
    int amount = 0;
    for (int i = 0; i < nMax; ++i) {
        if (array[i] < P) {
            ++amount;
        }
    }
    cout << "The amount of numbers that are less than P is " << amount << endl;
    int s = 0;
    for (int i = nMax - 1; i >= 0; --i) {
        if (array[i] < 0 && i == nMax - 1) {
            cout << "There are no elements after negative number." << endl;
            break;
        }
        if (array[i] < 0 && i != nMax - 1) {
            for (int j = i + 1; j < nMax; ++j) {
                s += (int) array[j];
            }
            cout << "The sum of int elements is " << s << endl;
            break;
        }
        if (i == 0 && array[i] >= 0)
            cout << "There are no negative numbers in array." << endl;
    }
    int exchanged = 0, norm = 0;
    for (int i = 0; i < nMax; ++i) {
        if (array[i] < P)
            norm += 1;
        else
            break;
    }
    for (int i = norm; i < nMax; ++i) {
        if (array[i] < P) {
            for (int l = i; l > (exchanged + norm); --l) {
                swap(array[l], array[l - 1]);
            }
            ++exchanged;
        }
    }
    cout << "A new array is ";
    for (int i = 0; i < nMax; ++i) {
        cout << array[i] << "   ";
    }
    return 0;
}
=======
#include <fstream>

using namespace std;

char *strncat(char *destination, const char *source, int n) {
    char *lastSymbol = destination;
    for (; *lastSymbol != '\0'; ++lastSymbol);
        while (*source != '\0' && n > 0) {
            *lastSymbol++ = *source++;
            --n;
        }
    *lastSymbol = '\0';
    return destination;
}

int main() {
}
