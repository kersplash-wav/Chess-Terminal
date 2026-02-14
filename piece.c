#include "chess.h"

void whitePawnSelected(char board[BOARD_HEIGHT][BOARD_WIDTH], short pos_x, short pos_y) {
    if (board[pos_y-1][pos_x] == EMPTY_SQUARE) board[pos_y-1][pos_x] = MOVE_SQUARE;
    if (board[pos_y-1][pos_x+1] >= 'a' && board[pos_y-1][pos_x+1] <= 'z') board[pos_y-1][pos_x+1] = CAPTURE_SQUARE;
    if (board[pos_y-1][pos_x-1] >= 'a' && board[pos_y-1][pos_x-1] <= 'z') board[pos_y-1][pos_x-1] = CAPTURE_SQUARE;
}

void blackPawnSelected(char board[BOARD_HEIGHT][BOARD_WIDTH], short pos_x, short pos_y) {
    if (board[pos_y+1][pos_x] == EMPTY_SQUARE) board[pos_y+1][pos_x] = MOVE_SQUARE;
    if (board[pos_y+1][pos_x+1] >= 'A' && board[pos_y+1][pos_x+1] <= 'Z') board[pos_y+1][pos_x+1] = CAPTURE_SQUARE;
    if (board[pos_y+1][pos_x-1] >= 'A' && board[pos_y+1][pos_x-1] <= 'Z') board[pos_y+1][pos_x-1] = CAPTURE_SQUARE;
}

