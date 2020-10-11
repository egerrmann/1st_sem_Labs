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

int **fullMatrix(int **a1, int row0, int column0) {
    srand(time(0));
    if (column0 % 2 == 0) {
        int** dArr = new int *[row0];
        for (int i = 0; i < row0; ++i ) {
            dArr[i] = new int[column0];
        }
        for (int i = 0; i < row0; ++i) {
            for (int j = 0; j < column0; ++j) {
                if ((i + j) % 2 == 0) {
                    dArr[i][j] = 1;
                }
                else {
                    dArr[i][j] = a1[i][j / 2];
                }
            }
        }
        return dArr;
    }
    if (column0 % 2 == 1) {
        int **dArr = new int *[row0];
        for (int i = 0; i < row0; ++i) {
            dArr[i] = new int[column0];
        }
        for (int i = 0; i < row0; ++i) {
            for (int j = 0; j < column0; ++j) {
                if ((i + j) % 2 == 0) {
                    dArr[i][j] = 1;
                }
                if (i % 2 == 0 && (i + j) % 2 != 0) {
                    dArr[i][j] = a1[i][j / 2];
                }
                if (i % 2 == 1 && (i + j) % 2 != 0) {
                    dArr[i][j] = a1[i][j / 2];
                    dArr[i][column0 - 1] = rand() % 10 - 5;
                }
            }
        }
        return dArr;
    }
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
        for (int j = 0; j < column; ++j) {
            cout << fullMatrix(dArr, row, column)[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
    int s = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (fullMatrix(dArr, row, column)[i][j] == 0) {
                int k = 0;
                while (k != column) {
                    s = s + fullMatrix(dArr, row, column)[i][k];
                    ++k;
                }
                j = column - 1;
            }
        }
    }
    cout << "The sum of all elements from rows with at least one 0 is " << s << endl;


    int amount = 0, minNum, maxNum;
    for (int i = 0; i < row; ++i) {
        minNum = 1;
        for (int j = 0; j < column; ++j) {
            minNum = min(fullMatrix(dArr, row, column)[i][j], minNum);
        }
        cout << "minNum is = " << minNum << endl;
            for (int j = 0; j < column; ++j) {
                hahaLOL:
                if (fullMatrix(dArr, row, column)[i][j] == minNum) {
                    maxNum = 1;
                    for (int w = 0; w < row; ++w) {
                        maxNum = max(fullMatrix(dArr, row, column)[w][j], maxNum);
                    }
                    if (fullMatrix(dArr, row, column)[i][j] == minNum && fullMatrix(dArr, row, column)[i][j] == maxNum) {
                        ++amount;
                        cout << i << "   " << j << "       " << minNum << endl;
                        ++j;
                        goto hahaLOL;
                    }
                }
            }
    }
    cout << amount;
    delete [] dArr;
    return 0;
}
