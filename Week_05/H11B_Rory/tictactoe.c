#include <stdio.h>

#define SIZE 5

// Function prototypes:
void print_result(char board[SIZE][SIZE]);
int did_player_win(char player, char board[SIZE][SIZE]);
int check_rows(char player, char board[SIZE][SIZE]);
int check_cols(char player, char board[SIZE][SIZE]);
int check_diagonals(char player, char board[SIZE][SIZE]);

int main(void) {

    // Initialise some sample boards.
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    // Print the result of each board.
    print_result(no_wins_board);
    print_result(x_wins_board);
    print_result(o_wins_board);

    return 0;
}

// Takes in a board and print out the corresponding winner of the board.
void print_result(char board[SIZE][SIZE]) {
    if (did_player_win('X', board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Check if a given player won the given board.
int did_player_win(char player, char board[SIZE][SIZE]) {
    
    // How can a player win in a tic-tac-toe game?
    // 1. a full row
    // 2. a full col
    // 3. y = -x
    // 4. y = x
    return (
        check_rows(player, board) || 
        check_cols(player, board) || 
        check_diagonals(player, board)
    );
}

// Check if there is a full row of the given player type.
int check_rows(char player, char board[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int count = 0;
        int col = 0;
        while (col < SIZE) {
            if (board[row][col] == player) {
                count++;
            }
            col++;
        }
        if (count == SIZE) {
            return 1;
        }
        row++;
    }
    return 0;
}

// Check if there is a full col of the given player type.
int check_cols(char player, char board[SIZE][SIZE]) {
    int col = 0;
    while (col < SIZE) {
        int count = 0;
        int row = 0;
        while (col < SIZE) {
            if (board[row][col] == player) {
                count++;
            }
            row++;
        }
        if (count == SIZE) {
            return 1;
        }
        col++;
    }
    return 0;
}

// Check if there is a full diagonal of the given player type.
int check_diagonals(char player, char board[SIZE][SIZE]) {
    
    // For the y = -x diagonal, row == col.
    int count = 0;
    int i = 0;
    while (i < SIZE) {
        if (board[i][i] == player) {
            count++;
        }
        i++;
    }
    if (count == SIZE) {
        return 1;
    }

    // For the y = x diagonal, starting from top right to bottom
    // left, row increases while col decreases.
    count = 0;
    int row = 0;
    int col = SIZE - 1;
    while (row < SIZE && col >= 0) {
        if (board[row][col] == player) {
            count++;
        }
        row++;
        col--;
    }
    if (count == SIZE) {
        return 1;
    }
    
    return 0;
}