#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char> >& sudoku, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == c) {
            return false;
        }
        if (sudoku[i][col] == c) {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char> >& sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(sudoku, i, j, c)) {
                        sudoku[i][j] = c;
                        if (solve(sudoku)) {
                            return true;
                        } else {
                            sudoku[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char> >& sudoku) {
    solve(sudoku);
}

int main() {
    vector<vector<char> > sudoku(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    cout <<endl;
    solveSudoku(sudoku);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}
