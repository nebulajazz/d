#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_N 10

int total_solutions = 0;
int N;
int solutions[MAX_N][MAX_N];

// Check if placing a queen at position (row, col) is safe
bool isSafe(int row, int col, int board[]) {
    for (int i = 0; i < col; i++) {
        // Check if there is a queen in the same row or in diagonal positions
        if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

// Solve N Queens problem using backtracking
void solveNQueens(int col, int board[]) {
    if (col == N) {
        // If all queens are placed successfully, store the solution
        for (int i = 0; i < N; i++) {
            solutions[total_solutions][i] = board[i];
        }
        total_solutions++;
        return;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, board)) {
            board[col] = i;
            solveNQueens(col + 1, board);
        }
    }
}

// Print the chessboard for a single solution
void printSolution(int solution) {
    printf("Solution %d:\n", solution + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solutions[solution][j] == i) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int num_queens;

    printf("Enter the number of queens (N): ");
    scanf("%d", &num_queens);

    if (num_queens < 1 || num_queens > MAX_N) {
        printf("Please enter a number between 1 and %d.\n", MAX_N);
        return 1;
    }

    N = num_queens;
    int board[MAX_N];

    total_solutions = 0;
    solveNQueens(0, board);

    printf("Total number of solutions for %d queens: %d\n", N, total_solutions);

    for (int i = 0; i < total_solutions; i++) {
        printSolution(i);
    }

    return 0;
}
