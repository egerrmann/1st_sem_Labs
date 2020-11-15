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
    return 0;
}