#include <stdbool.h>

bool isValid(char** board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == num) return false;
        
        // Check column
        if (board[i][col] == num) return false;
        
        // Check 3x3 box
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == num) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            // Find an empty cell
            if (board[r][c] == '.') {
                // Try characters '1' through '9'
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, r, c, num)) {
                        board[r][c] = num; // Tentatively place num
                        
                        // Recursively try to solve the rest of the board
                        if (solve(board)) {
                            return true;
                        }
                        
                        board[r][c] = '.'; // Backtrack if it fails
                    }
                }
                return false; // Trigger backtracking if no number fits
            }
        }
    }
    return true; // Board is completely and successfully filled
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}