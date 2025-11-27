#include <iostream>
using namespace std;

#define N 9   // Sudoku size

// Function to print the grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if placing num at grid[row][col] is valid
bool isValid(int grid[N][N], int row, int col, int num) {
    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // 3×3 subgrid check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Backtracking algorithm
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool emptyFound = false;

    // Find first empty cell (0 means empty)
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound) break;
    }

    // No empty cell = solved
    if (!emptyFound)
        return true;

    // Try numbers 1–9
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num; // Tentative placement

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;   // Undo (backtrack)
        }
    }

    return false; // Trigger backtracking
}

int main() {
    int grid[N][N] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    cout << "Original Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists!";
    }

    return 0;
}
