// variant 9
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    srand(time(0));
    int way;
    cout << "Insert 1 if you want to insert an array, and 2 if you want to work with random array." << endl;
    cin >> way;
    if (way != 1 && way != 2) {
        cout << "ERROR";
        return 0;
    }
    int column, row;
    cout << "Amount of rows is: " << endl;
    cin >> row;
    cout << "Amount of columns is: " << endl;
    cin >> column;

    if (column < 1 || column > 10 || row < 0 || row > 10) {
        cout << "ERROR";
        return 0;
    }

    int col1;
    if (column % 2 == 0)
        col1 = column / 2;
    if (column % 2 == 1)
        col1 = column / 2 + 1;
    int** dArr = new int*[row];
    for (int i = 0; i < row; ++i ) {
        dArr[i] = new int[col1];
    }

    switch (way) {
        case 1: {
            cout << "Insert the massive:" << endl;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col1; ++j) {
                    cin >> dArr[i][j];
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col1; ++j) {
                    dArr[i][j] = rand() % 10 - 5;
                }
            }
            break;
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col1; ++j) {
            if (column % 2 == 0) {
                if (i % 2 == 0) {
                    cout << "1  " << dArr[i][j] << "  ";
                }
                if (i % 2 == 1) {
                    cout << dArr[i][j] << "  " << "1  ";
                }
            }
            if (column % 2 == 1) {
                if (i % 2 == 0 && j < col1 - 1) {
                    cout << "1  " << dArr[i][j] << "  ";
                }
                if (i % 2 == 0 && j == col1 - 1) {
                    cout << "1";
                }
                if (i % 2 == 1 && j == 0) {
                    cout << dArr[i][j] << "  ";
                }
                if (i % 2 == 1 && j > 0) {
                    cout << "1  " << dArr[i][j] << "  ";
                }
            }
        }
        cout << endl;
    }

    cout << endl;

    int s = 0;
    if (column % 2 == 0) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col1; ++j) {
                if (dArr[i][j] == 0) {
                    for (int k = 0; k < col1; k++) {
                        s += dArr[i][k];
                    }
                    s += (1 * col1);
                    j = col1 - 1;
                }
            }
        }
    }
    if (column % 2 == 1) {
        for (int i = 0; i < row; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < col1 - 1; ++j) {
                    if (dArr[i][j] == 0) {
                        for (int k = 0; k < col1 - 1; k++) {
                            s += dArr[i][k];
                        }
                        s += (1 * col1);
                        j = col1 - 1;
                    }
                }
            }
            if (i % 2 == 1) {
                for (int j = 0; j < col1; ++j) {
                    if (dArr[i][j] == 0) {
                        for (int k = 0; k < col1; k++) {
                            s += dArr[i][k];
                        }
                        s += (1 * (col1 - 1));
                        j = col1 - 1;
                    }
                }
            }
        }
    }
    cout << "The sum of all elements from rows with at least one 0 is " << s << endl;

    int sedl = 0, minNum, maxNum;
    if (column % 2 == 0) {
        for (int i = 0; i < row; i += 2) {
            for (int j = 0; j < col1 - 1; ++j) {
                minNum = min(dArr[i][j], dArr[i][j + 1]);
            }
            for (int j = 0; j < col1; ++j) {
                if (dArr[i][j] == minNum && dArr[i][j] < 1) {
                    for (int i1 = 0; i1 < row - 1; i1 += 2) {
                        maxNum = max(dArr[i1][j], dArr[i1 + 1][j]);
                    }
                    if (dArr[i][j] == maxNum && dArr[i][j] > 1)
                        ++sedl;
                }
            }
        }
        for (int i = 1; i < row; i += 2) {
            for (int j = 0; j < col1 - 1; ++j) {
                minNum = min(dArr[i][j], dArr[i][j + 1]);
            }
            for (int j = 0; j < col1; ++j) {
                if (dArr[i][j] == minNum && dArr[i][j] < 1) {
                    for (int i1 = 1; i1 < row - 1; i1 += 2) {
                        maxNum = max(dArr[i1][j], dArr[i1 + 1][j]);
                    }
                    if (dArr[i][j] == maxNum && dArr[i][j] > 1)
                        ++sedl;
                }
            }
        }
    }
    if (column % 2 == 1) {
        for (int i = 0; i < row; i += 2) {
            for (int j = 0; j < col1 - 2; ++j) {
                minNum = min(dArr[i][j], dArr[i][j + 1]);
            }
            for (int j = 0; j < col1 - 1; ++j) {
                if (dArr[i][j] == minNum && dArr[i][j] < 1) {
                    for (int i1 = 0; i1 < row - 1; i1 += 2) {
                        maxNum = max(dArr[i1][j], dArr[i1 + 1][j]);
                    }
                    if (dArr[i][j] == maxNum && dArr[i][j] > 1)
                        ++sedl;
                }
            }
        }
        for (int i = 1; i < row; i += 2) {
            for (int j = 0; j < col1 - 1; ++j) {
                minNum = min(dArr[i][j], dArr[i][j + 1]);
            }
            for (int j = 0; j < col1 - 1; ++j) {
                if (dArr[i][j] == minNum && dArr[i][j] < 1) {
                    for (int i1 = 1; i1 < row - 1; i1 += 2) {
                        maxNum = max(dArr[i1][j], dArr[i1 + 1][j]);
                    }
                    if (dArr[i][j] == maxNum && dArr[i][j] > 1)
                        ++sedl;
                }
            }
        }
    }
    cout << endl;
    cout << "The amount of saddle points is " << sedl;
    cout << endl;
    delete [] dArr;
    return 0;
}
