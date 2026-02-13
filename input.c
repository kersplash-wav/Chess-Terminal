#include "chess.h"

/*
Cursor Left: \033[C
Cursor Right: \033[D
\033[25;1H" move cursor to row 25 col 1
*/

void handle_input(char board[BOARD_HEIGHT][BOARD_WIDTH], short* pos_x, short* pos_y, char input)
{
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
    }

    printf("\033[%d;%dH", BOARD_YOFFSET + (*pos_y), BOARD_XOFFSET + ((*pos_x)*2));
}