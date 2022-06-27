#include <stdio.h>

#define SIZE 5
#define DID_WIN 1
#define NO_WIN 0

int did_player_win(char player, char board[SIZE][SIZE]) {
    // Loop to check the diagonal.
    int count_first_diag = 0;
    int count_second_diag = 0;
    int i = 0;
    int j = SIZE - 1;
    while (i < SIZE) {
        if (board[i][i] == player) {
            count_first_diag++;
        }
        if (board[i][j] == player) {
            count_second_diag++;
        }
        j--;
        i++;
    }
    
    if (count_first_diag == SIZE) {
        return DID_WIN;
    }
    if (count_second_diag == SIZE) {
        return DID_WIN;
    }
    
    // Horizontals
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
            return DID_WIN;
        }
        
        row++;
    }
    
    int col = 0;
    while (col < SIZE) {
        int count = 0;
        row = 0;
        while (row < SIZE) {
            if (board[row][col] == player) {
                count++;
            }
            row++;
        }
        
        if (count == SIZE) {
            return DID_WIN;
        }
        
        col++;
    }
    
    return NO_WIN;
}

int main(void) {
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

    if (did_player_win('X', x_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', x_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}
