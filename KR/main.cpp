#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

ofstream fout("output_file.txt");

string ConsoleReader (string msg) {
    cin >> msg;
    return msg;
}

bool IsNonDecreasingOrder (string msg) {
    char symbol = msg[1], symbolCompare;
    bool check;
    for (int i = 3; i < msg.size(); i += 2) {
        symbolCompare = msg[i];
        if ((int) symbolCompare < (int) symbol) {
            check = false;
            break;
        }
        symbol = msg[i];
        check = true;
    }
    if (check)
        return true;
    else
        return false;
}

vector<string> FileReader (string input_file) {
    string str;
    vector<string> fileData;
    ifstream fin (input_file);
    while (fin) {
        getline(fin, str);
        fileData.push_back(str);
    }
    return fileData;
}

vector<string> WordParser (vector<string> lines) {
    vector<string> words;
    string line, word;
    int j = 0;
    for (int i = 0; i < lines.size() - 1; ++i) {
        line = lines[i];
        while (j < line.size()) {
            if (line[j] != ' ' ) {
                word.push_back(line[j]);
                j++;
            }
            else {
                words.push_back(word);
                word = "";
                while (line[j] == ' ')
                    j++;
            }
        }
        words.push_back(word);
        word = "";
        j = 0;
    }
    return words;
}

vector<string> FindItems (vector<string> sample) {
    vector<string> answer;
    for (int i = 0; i < sample.size(); ++i) {
        if (IsNonDecreasingOrder(sample[i])) {
            answer.push_back(sample[i]);
        }
    }
    return answer;
}

int WordWeight (string word) {
    int weight = 0, n = word.size();
    for (int i = 0; i < n; ++i) {
        if ((word[i] >> 1 & 1) == 1 && (word[i] >> 3 & 1) == 1) {
            weight += (char) word[i];
        }
    }
    return weight;
}

map<string, int> word_weight_map (vector<string> foundItems) {
    int n = foundItems.size(), numeralsMaxAmount, symbolsMaxAmount, symbolsAmount, numeralsAmount, spaces;
    map<string, int> table;
    symbolsMaxAmount = foundItems[0].size();
    numeralsMaxAmount = WordWeight(foundItems[0]);
    for (int i = 0; i < n; ++i) {
        numeralsAmount = 0;
        int temporary = WordWeight(foundItems[i]);
        while (temporary != 0) {
            temporary /= 10;
            numeralsAmount++;
        }
        symbolsAmount = foundItems[i].size();
        table.insert(pair<string, int>(foundItems[i], WordWeight(foundItems[i])));
        symbolsMaxAmount = max(symbolsMaxAmount, symbolsAmount);
        numeralsMaxAmount = max(numeralsMaxAmount, numeralsAmount);
    }
    int i;
    for (auto it = table.begin(); it != table.end(); ++it) {
        for (i = 0; i < n; ++i) {
            if (foundItems[i] == it->first)
                break;
        }
            fout << "|";
            for (int j = 0; j < symbolsMaxAmount - foundItems[i].size(); ++j) {
                fout << " ";
            }
            fout << it->first << "|";
            numeralsAmount = 0;
            int temporary = WordWeight(foundItems[i]);
            if (temporary == 0)
                numeralsAmount = 1;
            else
                while (temporary != 0) {
                    temporary /= 10;
                    numeralsAmount++;
                }
            for (int j = 0; j < numeralsMaxAmount - numeralsAmount; ++j) {
                fout << " ";
            }
            fout << it->second << "|" << endl;

    }
    return table;
}

int main() {
    string str, fileName;
    cout << "Insert string:" << endl;
    str = ConsoleReader(str);
    if (IsNonDecreasingOrder(str))
        cout << "Symbols are in non-decreasing order." << endl;
    else
        cout << "Symbols aren't in non-decreasing order." << endl;
    cout << "Insert input file name:" << endl;
    vector<string> inputFileData;
    fileName = ConsoleReader(fileName);
    inputFileData = FileReader(fileName);
    for (int i = 0; i < WordParser(inputFileData).size(); i++) {
        cout << WordParser(inputFileData)[i] << "   ";
    }
    cout << endl;
    for (int i = 0; i < FindItems(WordParser(inputFileData)).size(); i++) {
        cout << FindItems(WordParser(inputFileData))[i] << "   ";
    }
    cout << endl;
    word_weight_map(FindItems(WordParser(inputFileData)));
    return 0;
}
