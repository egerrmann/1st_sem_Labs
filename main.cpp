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
