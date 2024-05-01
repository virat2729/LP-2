#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 8; // Size of the chessboard

// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<vector<int> >& board, int row, int col) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Helper function for N-Queens problem
bool solveNQueensUtil(vector<vector<int> >& board, int col) {
    // Base case: If all queens are placed then return true
    if (col >= N) {
        return true;
    }

    // Consider this column and try placing this queen in all rows
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1)) {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0;
        }
    }

    // If the queen can't be placed in any row in this column, then return false
    return false;
}

// Function to solve N-Queens problem
void solveNQueens() {
    vector<vector<int> > board(N, vector<int>(N, 0)); // Initialize chessboard with 0s

    if (solveNQueensUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return;
    }

    // Print the solution
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    solveNQueens();
    return 0;
}
