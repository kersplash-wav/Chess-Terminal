#include "chess.h"

/*
Cursor Left: \033[C
Cursor Right: \033[D
\033[25;1H" move cursor to row 25 col 1
*/

char select_square(char board[BOARD_HEIGHT][BOARD_WIDTH], short pos_x, short pos_y, char* current_piece) {
    pos_y--; // Correct the position to be an index instead
    char selected_piece = board[pos_y][pos_x];

    if (selected_piece == '@' || selected_piece == 'X') { // Moving a piece to a new position
        switch(*current_piece) {
            case 'P':
                board[pos_y][pos_x] = *current_piece;
                board[pos_y+1][pos_x] = '#';
                break;
            case 'p':
                board[pos_y][pos_x] = *current_piece;
                board[pos_y-1][pos_x] = '#';
        }
    }
    else { // Selecting a new piece
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (board[i][j] == '@') board[i][j] = '#';
            }
        }
        
        switch (selected_piece) {
            case 'P':
                board[pos_y-1][pos_x] = '@';
                break;
            case 'p':
                board[pos_y+1][pos_x] = '@';
                break;
        }
    }

    return selected_piece;
}

void handle_input(char board[BOARD_HEIGHT][BOARD_WIDTH], short* pos_x, short* pos_y, char input, char* current_piece)
{
    // Board Movement //
    switch (input)
    {
    case 'a': 
    case 'A':
        (*pos_x)--;
        if (*pos_x < 0) *pos_x = 0;
        break;
    case 'd':
    case 'D':
        (*pos_x)++;
        if (*pos_x > BOARD_WIDTH - 1) *pos_x = BOARD_WIDTH - 1;
        break;
    case 's':
    case 'S':
        (*pos_y)++;
        if (*pos_y > BOARD_HEIGHT) *pos_y = BOARD_HEIGHT;
        break;
    case 'w':
    case 'W':
        (*pos_y)--;
        if (*pos_y < 1) *pos_y = 1;
        break;
    case '\n':
    case '\r':
        *current_piece = select_square(board, *pos_x, *pos_y, current_piece);
        print_to_terminal(board);
        break;
    }

    printf("\033[%d;%dH", BOARD_YOFFSET + (*pos_y), BOARD_XOFFSET + ((*pos_x)*2));
}