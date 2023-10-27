#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyPosition(int board[SIZE][SIZE], int& row, int& col) {
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    if (!findEmptyPosition(board, row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void displaySudoku(int board[SIZE][SIZE]) {  
    cout << endl;
    cout << "---------------------\n";
    for (int i = 0; i < SIZE; ++i) {
        if (i % 3 == 0 && i != 0) {
            cout << "|-------------------|\n";
        }
        for (int j = 0; j < SIZE; ++j) {
            if (j % 3 == 0) {
                cout << "|";
            }
            if (j == SIZE - 1) {
                cout << board[i][j];
            }
            else {
                cout << board[i][j] << " ";
            }            
        }
        cout << "|" << endl;
    }
    cout << "---------------------\n";
}

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << endl;

    cout << "----------------------------\n";
    cout << "| Sudoku Puzzle (Unsolved) |\n";
    cout << "----------------------------\n";
    displaySudoku(board);

    if (solveSudoku(board)) {
        cout << endl;
        cout << "--------------------------\n";
        cout << "| Sudoku Puzzle (Solved) |\n";
        cout << "--------------------------\n";
        displaySudoku(board);
    }
    else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}