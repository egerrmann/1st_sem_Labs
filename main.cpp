//variant 9
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count(const string& line, char symbol) {
    int n = 0;
    for (auto ch : line) {
        if (ch == symbol) {
            n++;
        }
    }
    return n;
}

int main() {
    ifstream lin("input.txt");
    ofstream fout("output.txt");

    string a, b, inputAnswer, outputAnswer, c;
    vector<string> pattern;
    int repeat = 1;
    cout << "Do want to open input file?";
    cin >> inputAnswer;
    if (inputAnswer == "Yes") {
        if (lin.is_open()) {
            while (getline(lin, c)) {
                cout << c << "\n";
            }
        }
    }
    lin.close();
    ifstream fin("input.txt");
    if (fin.is_open()) {
        while (getline(fin, a)) {
            pattern.push_back(a);
        }
    }

    for (int i = 1; i < pattern.size(); ++i) {
        a = pattern[i - 1];
        b = pattern[i];

        if (pattern[i - 1] == pattern[i] && count(a, ' ') == a.size() && count(b, ' ') == b.size()) {
            repeat++;
        }
        if (pattern[i - 1] != pattern[i] && count(a, ' ') == a.size()) {
            fout << "Amount of repeats is " << repeat << ", ";
            fout << "the row of group beginning is " << i - repeat + 1 << endl;
            repeat = 1;
        }
        if (i == pattern.size() - 1 && count(b, ' ') == b.size()) {
            fout << "Amount of repeats is " << repeat << ", ";
            fout << "the row of group beginning is " << i - repeat + 2 << endl;
        }
    }
    fin.close();
    ifstream pin ("output.txt");
    c = "";
    cout << "Do want to open output file?";
    cin >> outputAnswer;
    if (outputAnswer == "Yes") {
        if (pin.is_open()) {
            while (getline(pin, c)) {
                cout << c << "\n";
            }
        }
    }
    pin.close();
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    char str[300];
    int theOnlyOne, twoAndMore;
    int counter = 0;
    newNum:
    while (fin >> str) {
        if (strlen(str) % 2 == 1) {
            int n = strlen(str), i = 0;
            repeat:
            if (str[n - 1] == str[i]) {
                ++i;
                --n;
                if (n == strlen(str) / 2 + 1) {
                    theOnlyOne = stoi(str);
                    ++counter;
                    if (counter == 2)
                        twoAndMore = stoi(str);
                    goto newNum;
                }
                goto repeat;
            }
            else {
                goto newNum;
            }
        }
        else {
            goto newNum;
        }
    }
    if (counter == 0) {
        cout << "There are no palindromes" << endl;
    }
    if (counter == 1) {
        cout << "The palindrome is the only one and it's = " << theOnlyOne << endl;
    }
    if (counter >= 2) {
        cout << "There are two or more palindromes, the 2nd is = " << twoAndMore << endl;
    }
    return 0;
}
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